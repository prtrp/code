#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

typedef struct dnarr {
	size_t dlen;
	size_t dindx;
	char *darr;
} dnarr;

struct gameConfig {
	int sx, sy;
	int screenrows;
	int screencols;
	struct termios orig_termios;
};

struct gameConfig gc;

dnarr buffGame = {0, 0, NULL};

//------------- game setup
void disableGameMod(void) {
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &gc.orig_termios) == -1) {
		perror("ERROR WITH tcsetattr");
		exit(1);
	}
}

void enableGameMod(void) {
	if (tcgetattr(STDIN_FILENO, &gc.orig_termios) == -1) {
		perror("Error with tcgetattr");
		exit(1);
	}
	atexit(disableGameMod);

	struct termios raw = gc.orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | IXON | ISTRIP);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag &= ~(CS8);

	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
		perror("ERROR WITH tcsetattr");
		exit(1);
	}
}

//------------- dynamic array
void apDnarr(dnarr *arr, const char* inStr, size_t szArr) {
	if(arr->dlen <= 0) {
		arr->dlen = 2;
		arr->darr = malloc(sizeof(char)*(arr->dlen));
	}

	if(arr->darr == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}

	while((arr->dlen - arr->dindx) < szArr) {
		arr->dlen *= 2;
		char *tmp = NULL;
		tmp = realloc(arr->darr, sizeof(char)*(arr->dlen));

		if(tmp == NULL) {
			fprintf(stderr, "Memory reallocation error\n");
			free(arr->darr);
			exit(1);
		}
		arr->darr = tmp;
	}
	memcpy(&arr->darr[arr->dindx], inStr, szArr);
	arr->dindx += szArr;
}

void dnFree(dnarr *strcArr) {
	free(strcArr->darr);
	strcArr->dindx = 0;
	strcArr->dlen = 0;
}

//------------- work with cursor
int getCursorPosition(int *rows, int *cols) {
	char buff[32];
	unsigned int i = 0;
	if((write(STDOUT_FILENO, "\x1b[6n", 4)) != 4) {
		return -1;
	}
	while (i < sizeof(buff)-1) {
		if (read(STDIN_FILENO, &buff[i], 1) != 1) break;
		if (buff[i] == 'R') break;
		i++;
	}
	buff[i] = '\n';

	if(buff[0] != '\x1b' || buff[1] != '[') {
		return -1;
	}

	if(sscanf(&buff[2], "%d;%d", rows, cols) != 2) {
		return -1;
	}

	return 0;
}

int getWindowSize(int *rows, int *cols) {
	struct winsize ws;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
		if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) {
			return -1;
		}
		return getCursorPosition(rows, cols);
	} else {
		*cols = ws.ws_col;
		*rows = ws.ws_row;
		return 0;
	}
}

//------------- print the corner of game
void fullRec(size_t base, size_t hight) {
	for(size_t rows = 0; rows < hight; rows++) {
		for(size_t cols = 0; cols < base; cols++) {
			if ((rows != 0 && rows != hight-1) && (cols != 0 && cols != base-1)) {
				apDnarr(&buffGame, " ", 1);
			} else {
				if ((cols == 0 && rows == 0) || (cols == base-1 && rows == hight-1) ||
					(cols == 0 && rows == hight-1) || (cols == base-1 && rows == 0)) {
					apDnarr(&buffGame, "+", 1);

				}else if (rows == 0 || rows == hight-1) {
					apDnarr(&buffGame, "-", 1);
					
				}else {
					apDnarr(&buffGame, "|", 1);
				}
			}
		}
		apDnarr(&buffGame, "\n\r", 2);
	}
}

void readKey() {
	int retRead;
	char ch;
	if((retRead = read(STDIN_FILENO, &ch, 1)) != 1) {
		if(retRead == -1 && errno != EAGAIN) {
			perror("error with read");
			exit(1);
		}
	}

	if(ch == 'q') {
		exit(0);
	}

}

void refreshScreen(void) {
	// clean screen and go in first position
	apDnarr(&buffGame, "\x1b[2J\x1b[H", 7);

	fullRec(30, 20);
	// put the cursor in the starting position
	char buff[32];
	snprintf(buff, sizeof(buff), "\x1b[%d;%dH", gc.sx, gc.sy);
	apDnarr(&buffGame, buff, strlen(buff));

	// try center a line
	write(STDOUT_FILENO, buffGame.darr, buffGame.dindx);

	dnFree(&buffGame);
}

void init(void) {

	if(getWindowSize(&gc.screenrows, &gc.screencols) == -1) {
		perror("error with getWindows");
		exit(1);
	}

	// initiailze the position of snake
	gc.sx = (gc.screenrows / 2);
	gc.sy = (gc.screencols / 2);
}


int main() {
	init();
	enableGameMod();
	while(1) {
		refreshScreen();
		readKey();
	}

	return 0;
}
