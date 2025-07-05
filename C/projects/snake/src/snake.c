#define _POSIX_SOURCE 199309L

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>
#include <time.h>

#define HEIGHT 30;
#define WIDTH 40;


//----------------------------------------------------//
//##################### data type ####################//
//----------------------------------------------------//

// game settings
struct game {
    bool gameOver;

    int xHead, yHead;
    char snake[128];

    int lastMove;

    int cols, rows;
    int xfruit, yfruit;
    int score;
};
struct game G;

// termianl settings
struct termianl {
    int rows, cols;
    struct termios orig_term;
};
struct termianl T;

typedef struct dnarr {
    int capacity;
    int indx;
    char *str;
}dnarr;
dnarr gamearr = {0, 0, NULL};

enum KEY {
    UP = 1000,
    DOWN,
    LEFT,
    RIGHT,
    QUIT
};

// --- die function
void die (const char *s) {
    perror(s);
    write(STDIN_FILENO, "\x1b[2J\x1b[H", 7);
    write(STDIN_FILENO, "\x1b[?25h", 6);
    exit(1);
}

//----------------------------------------------------//
//#################### DYNAMIC ARRAY #################//
//----------------------------------------------------//

void apndArr(char *str, int len) {
    while ((gamearr.capacity - gamearr.indx)<= len+1) 
        gamearr.capacity = gamearr.capacity == 0 ? 2 : gamearr.capacity*2;

    char *new = NULL;
    new = realloc(gamearr.str, sizeof(char)*gamearr.capacity);
    if (new == NULL) die ("realloc"); 
    gamearr.str = new;

    memcpy(&gamearr.str[gamearr.indx], str, len);
    gamearr.indx += len;
}

void freeGbff(void) {
    gamearr.indx = 0;
    gamearr.capacity = 0;
    free(gamearr.str);

    //used for dandlig pointers
    gamearr.str = NULL;
}

//----------------------------------------------------//
//##################### TERMINAL MOD #################//
//----------------------------------------------------//

void disableRowMode(void) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &T.orig_term) == -1) die("tcsetattr");
    if (write(STDIN_FILENO, "\x1b[2J\x1b[H", 7) != 7) die("write");
    if (write(STDIN_FILENO, "\x1b[?25h", 6) != 6) die ("write");
}

void enableRowMode(void) {

    struct termios raw;

    // setting terminal os original
    if (tcgetattr(STDIN_FILENO, &T.orig_term) == -1) die("tcgetattr");

    atexit(disableRowMode);

    raw = T.orig_term;

    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_iflag &= ~(ISTRIP | ICRNL| IXON | BRKINT | INPCK);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);

    raw.c_cc[VTIME] = 1;
    raw.c_cc[VMIN] = 0;   

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

//----------------------------------------------------//
//##################### KEY INPUT ####################//
//----------------------------------------------------//

int keyRead(void) {
    int nread;
    char c;

    nread = read(STDIN_FILENO, &c, 1);

    if(nread == 1) {
        switch (c) {
            case 'q': return QUIT; G.gameOver = true; break;

            case 'w': return UP; if (G.xHead >= ((T.rows - G.rows)/2)+1) G.xHead--; break;
            case 's': return DOWN; if (G.xHead < ((T.rows - G.rows)/2 + G.rows)-1) G.xHead++; break;

            case 'a': return LEFT; if (G.yHead >= ((T.cols - G.cols)/2)+1) G.yHead--; break;
            case 'd': return RIGHT; if (G.yHead < (((T.cols - G.cols)/2)-1)+G.cols) G.yHead++; break;
        }
    }
    else if (nread == -1 && errno != EAGAIN) {
        die("read");
    }
    return 0;
}

//----------------------------------------------------//
//################## CURSOR POSITION #################//
//----------------------------------------------------//

int getCursorPosition(int *rows, int *cols) {
    char buf[32];
    unsigned int i = 0;

    if (write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;

    while (i < sizeof(buf) -1) {
        if (read(STDIN_FILENO, &buf[i], 1) != 1) break;
        if (buf[i] == 'R') break;
        i++;
    }
    buf[i] = '\0';

    if (buf[0] != '\x1b' || buf[1] != '[') return -1;

    if (sscanf(&buf[2], "%d;%d", rows, cols) != 2) return -1;
    return 0;
}

int getTermianlSize(int *rows, int *cols) {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {

        if (write(STDOUT_FILENO, "{\x1b[999C\x1b[999B", 12) != 12) return -1;

        return getCursorPosition(rows, cols);
        return -1;
    }
    else {
        T.cols = ws.ws_col;
        T.rows = ws.ws_row;
        return 0;
    }
}

void moveSnake(void) {
    char buff[32];

    apndArr("\x1b[?25l", 6);
    snprintf(buff, sizeof(buff), "\x1b[%d;%dH%c", G.xHead, G.yHead, G.snake[0]);
    apndArr(buff,strlen(buff));
}

//----------------------------------------------------//
//##################### DRAW PART ####################//
//----------------------------------------------------//

void prtRec(int width, int height) {
    char buff[32];
    for (int i = 0; i < height; i++) {
        snprintf(buff, sizeof(buff), 

                 // use ; not : tmux is not tollerand as kitty
                 "\x1b[%d;%dH", ((T.rows - G.rows)/2) +i, (T.cols - G.cols)/2); 
        apndArr(buff, strlen(buff));
        //for(unsigned int k = 0; k < (T.rows - G.rows); k++) printf(" ");

        for(int j = 0; j < width; j++) {

            // top and down border and upper corner
            if ((i == 0 || i == height-1) && (j != 0 && j < width-1)) 
                apndArr("\u2550", 3);
            
            else if (j == 0 && i == 0) 
                apndArr("\u2554", 3);

            else if (j == width-1 && i == 0) 
                apndArr("\u2557", 3);


            // left and write borders and lower corner
            else if ((j == 0 && i < height-1)|| (j == width-1 && i < height-1)) 
                apndArr("\u2551", 3); 

            else if (j == 0 && i == height-1) {
                apndArr("\u255A", 3);
            }

            else if (j == width-1 && i == height-1) {
                apndArr("\u255D", 3);
            }

            else apndArr(" ", 1);
        }
    }
    apndArr("\r\n", 2);
}

void delay(int ms) {
    struct timespec ts = {
        .tv_sec = ms / 1000,
        .tv_nsec = (ms % 1000) * 1000000
    };
    while (nanosleep(&ts, &ts) == -1 && errno == EINTR);
}

void draw(void) {
    write(STDOUT_FILENO, "\x1b[2J\x1b[H", 7);

    getTermianlSize(&G.rows, &G.cols);
    if (G.cols > T.cols) G.cols = T.cols;

    if (G.rows > T.rows) G.rows = T.rows-2;

    prtRec(G.cols, G.rows);
    moveSnake();
    write(STDOUT_FILENO, gamearr.str, gamearr.indx);
    freeGbff();
}

//----------------------------------------------------//
//##################### LOGIC ########################//
//----------------------------------------------------//

void snakeMove(void) {
    int key = keyRead();

    if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == QUIT) {
        G.lastMove = key;
    }

    const int top_bound = (T.rows - G.rows)/2 + 1;
    const int bottom_bound = top_bound + G.rows - 3;
    const int left_bound = (T.cols - G.cols)/2 + 1;
    const int right_bound = left_bound + G.cols - 3;

    switch (G.lastMove) {
        case QUIT: 
            G.gameOver = true; 
            break;

        case UP:
            G.xHead--;
            if (G.xHead < top_bound) G.xHead = bottom_bound;
            break;

        case DOWN:
            G.xHead++;
            if (G.xHead > bottom_bound) G.xHead = top_bound;
            break;

        case LEFT:
            G.yHead--;
            if (G.yHead < left_bound) G.yHead = right_bound;
            break;

        case RIGHT:
            G.yHead++;
            if (G.yHead > right_bound) G.yHead = left_bound;
            break;

        default: 
            break;

    }
}

void lose(void) {
}

void logic(void) {
    snakeMove();
    lose();

}

//----------------------------------------------------//
//##################### MAIN #########################//
//----------------------------------------------------//

void setup() {
    enableRowMode();
    getTermianlSize(&G.rows, &G.cols);

    G.gameOver = false;
    G.cols = WIDTH;
    G.rows = HEIGHT;

    G.score = 0;
    G.xfruit = 0;
    G.yfruit = 0;
    G.xHead = T.rows/2; 
    G.yHead = T.cols/2;

    G.snake[0] = 'O';
    G.snake[1] = '\0';

}

int main() {
    setup();

    while(!G.gameOver) {
        draw();
        logic();
        delay(100);
    }
}
