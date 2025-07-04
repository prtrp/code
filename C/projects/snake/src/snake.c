#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>

#define HEIGHT 30;
#define WIDTH 40;

//----------------------------------------------------//
//##################### data type ####################//
//----------------------------------------------------//

// game settings
struct game {
    bool gameOver;
    unsigned int xHead, yHead;
    unsigned int cols, rows;
    unsigned int xfruit, yfruit;
    unsigned int score;
};
struct game G;

// termianl settings
struct termianl {
    unsigned rows, cols;
    struct termios orig_term;
};
struct termianl T;

typedef struct dnarr {
    int capacity;
    int indx;
    char *str;
}dnarr;
dnarr gamearr = {0, 0, NULL};

// --- die function
void die (const char *s) {
    perror(s);
    write(STDIN_FILENO, "\x1b[2J\x1b[H", 7);
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

//----------------------------------------------------//
//##################### TERMINAL MOD #################//
//----------------------------------------------------//


void disableRowMode(void) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &T.orig_term) == -1) die("tcsetattr");
    if (write(STDIN_FILENO, "\x1b[2J\x1b[H", 7) != 7) die("write");
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

void keyRead() {
    int nread;
    char c;

    while ((nread = read(STDIN_FILENO, &c, 1) != 1)) 
        if (nread == -1 && errno != EAGAIN) die("read");

    switch (c) {
        case 'q': exit(0);
    }
    
}

//----------------------------------------------------//
//##################### DRAW PART ####################//
//----------------------------------------------------//

void getTermianlSize() {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) die("ioctl");

    T.cols = ws.ws_col;
    T.rows = ws.ws_row;
}

void prtRec(int width, int height) {
    char buff[32];
    for (int i = 0; i < height; i++) {
        snprintf(buff, sizeof(buff), 
                 "\x1b[%d:%dH", ((T.rows - G.rows)/2) +i, (T.cols - G.cols)/2);
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

void draw(void) {
    write(STDOUT_FILENO, "\x1b[2J\x1b[H", 7);

    getTermianlSize();
    if (G.cols > T.cols) G.cols = T.cols;

    if (G.rows > T.rows) G.rows = T.rows-2;

    prtRec(G.cols, G.rows);
    write(STDOUT_FILENO, gamearr.str, gamearr.indx);
    printf("Tcosl = %d, Trows = %d Gcols = %d Grows = %d\r\n", T.cols, T.rows, G.cols, G.rows);
}

//----------------------------------------------------//
//##################### MAIN #########################//
//----------------------------------------------------//

void setup() {
    enableRowMode();

    G.gameOver = false;
    G.cols = WIDTH;
    G.rows = HEIGHT;

    G.score = 0;
    G.xfruit = 0;
    G.yfruit = 0;
    G.xHead = 0;
    G.yHead = 0;

}

int main() {
    setup();

    while(!G.gameOver) {
        draw();
        keyRead();
    }
}
