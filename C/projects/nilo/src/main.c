//--- includes
#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <ctype.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>

// --- defines

#define KILO_VERSION "0.0.1"
#define CTRL_KEY(k) ((k) & 0x1f)

enum editorKey {
	ARROW_LEFT = 1000, 
	ARROW_RIGHT,
	ARROW_UP,
	DEL_KEY,
	ARROW_DOWN,
	HOME_KEY,
	END_KEY,
	PAGE_UP,
	PAGE_DOWN
};

//--- data

// datatype for store a row, erow = editor row, stores a line of text as a pointer 
typedef struct erow {
	int size; // size of a row
	char *chars; // chars inside the line
} erow;

// creat our original status of terminal
struct editorConfig {
	// position of cursor (x; y)
	int cx, cy;

	// track which row user is scrolled to 
	// the firt line that appair
	int rowoff;
	int screenrows;
	int screencols;
	int numrows; 

	// array that contains all rows
	erow *row;
	struct termios orig_termios;
};
struct editorConfig E;

// --- terminal

void die(const char *s) {
	// erase the terminal
	write(STDOUT_FILENO, "\x1b[2J", 4);
	// used for move the cursor in terminal
	write(STDOUT_FILENO, "\x1b[H", 3);

	perror(s);
	exit(1);
}

void disableRowMode() {
	// setting the original status of terminal
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1) die("tcsetattr");
}

void enableRawMode() {
	if (tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) die("tcgetattr");

	// cames from stdlib, will be the last function to be called
	atexit(disableRowMode); 
	
	// setting the raw modifigaction starter to normal temrinal
	struct termios raw = E.orig_termios;

	// not show typing | turn off canonical mode | disable ctrl-c, ctrl-z |
	// diables ctrl-v | 
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);

	// convert \r to \n | diable ctrl-s and ctrl-q | disable ctrl-c 
	// remove eighth byte | check di parità
	raw.c_iflag &= ~(ICRNL | IXON | BRKINT | ISTRIP | INPCK);

	// convert each \n into \r\n
	raw.c_oflag &= ~(OPOST);

	// set char len to 8 bit
	raw.c_cflag |= (CS8);

	// maximum number of bytes before read() return
	raw.c_cc[VMIN] = 0;
	
	// maximum amout of time wait before read() returns
	raw.c_cc[VTIME] = 1;

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int editorReadKey() {
	int nread;
	char c; 

	// quando read return != 1 do:
	while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {

		// if nread == -1 and the error is not wait, then exit
		if (nread == -1 && errno != EAGAIN) die("read");
	}

	if (c == '\x1b') {
		char seq[3];

		if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
		if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';

		if (seq[0] == '[') {

			if (seq[1] >= '0' && seq[1] <= '9') {
				if (read(STDIN_FILENO, &seq[2], 1) != 1) return '\x1b';
				if (seq[2] == '~') {
					switch (seq[1]) {
						case '1': return HOME_KEY;
						case '3': return DEL_KEY;
						case '4': return END_KEY;
						case '5': return PAGE_UP;
						case '6': return PAGE_DOWN;
						case '7': return HOME_KEY;
						case '8': return END_KEY;
					}
				}
			}
			else {
				switch (seq[1]) {
					case 'A': return ARROW_UP;
					case 'B': return ARROW_DOWN;
					case 'C': return ARROW_RIGHT;
					case 'D': return ARROW_LEFT;
					case 'H': return HOME_KEY;
					case 'F': return END_KEY;

				}
			}
		} else if (seq[0] == 'O') {
			switch (seq[1]) {
				case 'H': return HOME_KEY;
				case 'F': return END_KEY;
			}
		}

		return '\x1b';
	}
	else {
		return c;
	}
}

int getCursorPosition(int *rows, int *cols) {
	char buf[32];
	unsigned int i = 0;

	// 6n used for ask the cursor position ;
	if(write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;

	while (i < sizeof(buf) -1) {
		// it reads from the standard input the escape sequence, not form the terminal.
		// trasferisce da STDIN_FILENO a buf[i] finché non incontra R
		if (read(STDIN_FILENO, &buf[i], 1) != 1) break;
		if (buf[i] == 'R') break;
		i++;
	}
	buf[i] = '\0';

	// se non sono presenti \x1b o [ allora ce un errore
	if (buf[0] != '\x1b' || buf[1] != '[') return -1;

	// inizia a scannerizzare dalla terza posizione fino a \0.
	if (sscanf(&buf[2], "%d;%d", rows, cols) != 2) return -1;
	return 0;

}

int getWindowSize(int *rows, int *cols) {
	// create a struct ws
	struct winsize ws;

	// ioctl used for control ardware and software, apply the len of rows and cols into ws.
	// control first if icotl work, after if provided a true value
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {

		// 999C adn 999B used for set the cursor on bottop right
		if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) return -1;

		// for observe result of our esacape before die()
		return getCursorPosition(rows, cols);
		return -1;
	} else {
		*cols = ws.ws_col;
		*rows = ws.ws_row;
		return 0;
	}
}

//-- row operations
void editorAppendRow(char *s, size_t len) {

	// adding erow datatype for each row encountered, +1 for 0 index
	E.row = realloc(E.row, sizeof(erow) * (E.numrows + 1));

	// at means where we are inside the array of struct erow 
	int at = E.numrows;

	// inside the specific location inside array
	// .size is equal to the len
	E.row[at].size = len;

	// inside the specific location inside array 
	// create enough space for contain the string an '\0'
	E.row[at].chars = malloc(sizeof(char)*(len+1));

	// copy the chars from the string to the chars location
	memcpy(E.row[at].chars, s, len);

	// add the null terminator
	E.row[at].chars[len] = '\0';

	// increment the numbers of rows
	E.numrows++;
}

//--- file i/o

void editorOpen(char *filename) {
	FILE *fp = fopen(filename, "r");
	if (!fp) die("fopen");

	// is the buffer that rappresent the single line
	char *line = NULL; 

	// line cpapcity tiene traccia della capacita 
	// corrente del buffer allocato
	size_t linecap = 0;

	// take the size of each line one at the time
	ssize_t linelen;

	// read only one row at time, each call overwrite line with another row
	while ((linelen = getline(&line, &linecap, fp)) != -1) {
		
		// used for remove \n and \r at the end of the file and decrement the len
		while (linelen > 0 && (line[linelen -1] == '\n' || line[linelen -1] == '\r')) linelen --;
		editorAppendRow(line, linelen);
	}

	free(line);
	fclose(fp);

}

//--- buffer append

struct abuf {
	char *b;
	int len;
};

#define ABUF_INIT {NULL, 0}

void abAppend(struct abuf *ab, const char *s, int size) {
	
	// crate a new allocated array that have the original dimension
	// plus the size of the word to add
	char *new = realloc(ab -> b, ab -> len + size);

	if (new == NULL) return;

	// copy the memory starting by the last len of the provious 
	// buffer, so i can add the new word inside the buffer.
	memcpy(&new[ab -> len], s, size);
	ab -> b = new;
	ab -> len += size;
	
}

void abFree(struct abuf *ab) {
	free(ab -> b);
}

// --- output

void editorScroll() {
	if (E.cy < E.rowoff) {
		E.rowoff = E.cy;
	}

	if (E.cy >= E.rowoff + E.screenrows) {
		E.rowoff = E.cy - E.screenrows + 1;
	}
}

void editorDrawRows(struct abuf *ab) {
	int y;
	for (y = 0; y < E.screenrows; y++) {

		int filerow = y + E.rowoff;

		// if our current line is bigger than our rows to print
		if (filerow >= E.numrows) {

			// if we are at 1/3 of rows and if the file is empty
			if (E.numrows == 0 && y == E.screenrows / 3) {
				char welcome[128];

				// return the len of what we print inside the welcome message
				int welcomelen = snprintf(welcome, sizeof(welcome),
							  "nilo editor -- version %s", KILO_VERSION);

				if (welcomelen > E.screencols) welcomelen = E.screencols;
				int padding = (E.screencols - welcomelen) /2 ;
				if (padding) {
					abAppend(ab, "~", 1);
					padding--;
				}
				while (padding--) abAppend(ab, " ", 1);
				abAppend(ab, welcome, welcomelen);
			}
			else {
				abAppend(ab, "~", 1); 
			}
		}

		// else print our rows form E.row.chars
		else {
			int len = E.row[filerow].size;

			// if the len of the line is bigger than the line
			if (len > E.screencols) len = E.screencols;
			abAppend(ab, E.row[filerow].chars, len);
		}

		// eraise right part in line from the cursor
		// usefull for update the terminal
		abAppend(ab, "\x1b[K", 3);
		if (y < E.screenrows -1) {
			abAppend(ab, "\r\n", 2);
		} 
	}
}

void editorRefreshScreen() {
	editorScroll();

	struct abuf ab = ABUF_INIT;

	// ?25 means control cursor, l means hide
	abAppend(&ab, "\x1b[?25l", 6);

	// used for move the cursor in terminal
	abAppend(&ab, "\x1b[H", 3);

	editorDrawRows(&ab);

	abAppend(&ab, "\x1b[H", 3);

	char buf[32];
	
	// are putting inside buf the esc key for point to the position plus 1
	// because terminal uses the 1-index position
	snprintf(buf, sizeof(buf), "\x1b[%d;%dH", (E.cy - E.rowoff) + 1, E.cx + 1);
	abAppend(&ab, buf, strlen(buf));

	// ?25 means control cursor, h means show
	abAppend(&ab, "\x1b[?25h", 6);

	write(STDOUT_FILENO, ab.b, ab.len);
	abFree(&ab);
}

// --- input

void editorMoveCursor(int key) {
	switch (key) {
		case ARROW_LEFT:  if (E.cx > 0) E.cx--; break;
		case ARROW_RIGHT: if (E.cx < E.screencols -1) E.cx++; break;
		case ARROW_UP:    if (E.cy >= 1) E.cy--; break;
		case ARROW_DOWN:  if (E.cy < E.numrows) E.cy++; break;
	}
}

void editorProcessKeypress() {
	int c = editorReadKey();

	switch (c) {
		case CTRL_KEY('q') : 
			write(STDOUT_FILENO, "\x1b[2J", 4);
			write(STDOUT_FILENO, "\x1b[H", 3);

			exit(0); 
			break;

		case HOME_KEY: E.cx = 0; break;
		case END_KEY: E.cx = E.screencols -1; break;

		case PAGE_UP:
		case PAGE_DOWN:
		{
			int times = E.screenrows; 
			while (times--) editorMoveCursor(c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
		} break;

		case ARROW_LEFT: 
		case ARROW_RIGHT:
		case ARROW_UP:
		case ARROW_DOWN: 
			editorMoveCursor(c); break;
	}
}

// --- init

void initEditor() {
	E.cx = 0;
	E.cy = 0;
	E.rowoff = 0;
	E.numrows = 0;
	E.row = NULL;

	if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
}

int main(int argc, char *argv[]) {
	enableRawMode();
	initEditor();

	// argv[0] is the name of program itself
	// argv[1] is the first argument
	if (argc >= 2) editorOpen(argv[1]);

	while(1) {
		editorRefreshScreen();
		editorProcessKeypress();
	}
	return 0;
}
