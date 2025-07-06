#define _POSIX_C_SOUECE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>
#include <time.h>

#define HEIGHT 30
#define WIDTH 40


//----------------------------------------------------//
//##################### data type ####################//
//----------------------------------------------------//

struct bounds {
    int top_bound;
    int bottom_bound;
    int left_bound;
    int right_bound;
};

// game settings
struct game {
    bool gameOver;

    int snakeLen;
    int snakeX[128];
    int snakeY[128];

    int lastMove;

    int cols, rows;
    int xfruit, yfruit;
    int score;

    struct bounds B;
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
            case 'q': return QUIT;  

            case 'w': return UP; 
            case 's': return DOWN; 

            case 'a': return LEFT;
            case 'd': return RIGHT;
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

int getTerminalSize(int *rows, int *cols) {
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

//----------------------------------------------------//
//##################### LOGIC ########################//
//----------------------------------------------------//

bool isPositionOccupated(int x, int y) {
    for (int i = 0; i < G.snakeLen; i++) {
        if (G.snakeX[i] == x && G.snakeY[i] == y) return true;
    }
    return false;
}

void snakeMove(void) {
    int key = keyRead();

    if (key == UP || key == DOWN || key == LEFT || key == RIGHT || key == QUIT) {
        G.lastMove = key;
    }

    switch (G.lastMove) {
        case QUIT: G.gameOver = true; break;

        case UP: G.snakeX[0]--; break;
        case DOWN: G.snakeX[0]++;  break;

        case LEFT: G.snakeY[0]--;  break;
        case RIGHT: G.snakeY[0]++;  break;

        default: 
            break;
    }

    if (G.snakeX[0] < G.B.top_bound) G.snakeX[0] = G.B.bottom_bound;
    if (G.snakeX[0] > G.B.bottom_bound) G.snakeX[0] = G.B.top_bound;
    if (G.snakeY[0] < G.B.left_bound) G.snakeY[0] = G.B.right_bound;
    if (G.snakeY[0] > G.B.right_bound) G.snakeY[0] = G.B.left_bound;
}

void lose(void) {
    for (int i = 1; i < G.snakeLen; i++) {
        if (G.snakeX[0] == G.snakeX[i] && G.snakeY[0] == G.snakeY[i]) {
            G.gameOver = true;
            return;
        }
    }
}

void logic(void) {

    // save previous tail
    int prevX = G.snakeX[G.snakeLen-1];
    int prevY = G.snakeY[G.snakeLen-1];

    // move body not head
    for (int i = G.snakeLen-1; i > 0; i--) {
        G.snakeX[i] = G.snakeX[i-1];
        G.snakeY[i] = G.snakeY[i-1];
    }

    snakeMove();

    G.B.top_bound = ((T.rows - G.rows)/2)+1;
    G.B.bottom_bound = G.B.top_bound + G.rows -3;
    G.B.left_bound = ((T.cols - G.cols)/2)+1;
    G.B.right_bound = G.B.left_bound + G.cols-3;


    if (G.snakeX[0] == G.xfruit && G.snakeY[0] == G.yfruit) {

        // regenerate the new fruits
        do{
            G.xfruit = G.B.top_bound + (rand() % (G.rows -2));
            G.yfruit = G.B.left_bound + (rand() % (G.cols -2));
        }
        while (isPositionOccupated(G.xfruit, G.yfruit));


        // create another fruit in the temrminal
        G.score += 10;
        G.snakeLen++;

        // set the tail coordinates
        G.snakeX[G.snakeLen-1] = prevX;
        G.snakeX[G.snakeLen-1] = prevY;

    }
    lose();

}

//----------------------------------------------------//
//##################### DRAW PART ####################//
//----------------------------------------------------//

void delay(int ms) {
    struct timespec ts = {
        .tv_sec = ms / 1000,
        .tv_nsec = (ms % 1000) * 1000000
    };
    while (nanosleep(&ts, &ts) == -1 && errno == EINTR);
}


void prntfruit(void) {    

    char buff[32];
    snprintf(buff, sizeof(buff), "\x1b[%d;%dH%c", G.xfruit, G.yfruit,'*');
    apndArr(buff, strlen(buff));
}

void drawSnake(void) {

    char buff[256];
    apndArr("\x1b[?25l", 6);

    snprintf(buff, sizeof(buff), "\x1b[%d;%dH%c", G.snakeX[0], G.snakeY[0], 'O');
    apndArr(buff, strlen(buff));

    for (int i = 1; i < G.snakeLen; i++) {
        snprintf(buff, sizeof(buff), "\x1b[%d;%dH%c", G.snakeX[i], G.snakeY[i], 'o');
        apndArr(buff,strlen(buff));
    }
}


void prtRec(int width, int height) {
    char buff[64];
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
    snprintf(buff, sizeof(buff), "\x1b[%d;%dHscore: %d", ((T.rows - G.rows)/2) + HEIGHT, (T.cols - G.cols)/2, G.score); 
    apndArr(buff, strlen(buff));
}

void draw(void) {
    write(STDOUT_FILENO, "\x1b[2J\x1b[H", 7);

    getTerminalSize(&G.rows, &G.cols);

    if (G.cols > T.cols) G.cols = T.cols;
    if (G.rows > T.rows) G.rows = T.rows-2;

    prtRec(G.cols, G.rows);
    drawSnake();
    prntfruit();
    write(STDOUT_FILENO, gamearr.str, gamearr.indx);
    freeGbff();
}

//----------------------------------------------------//
//##################### MAIN #########################//
//----------------------------------------------------//

void setup() {
    enableRowMode();
    getTerminalSize(&G.rows, &G.cols);

    G.gameOver = false;
    G.cols = WIDTH;
    G.rows = HEIGHT;

    G.score = 0;

    G.B.top_bound = ((T.rows - G.rows)/2)+1;
    G.B.bottom_bound = G.B.top_bound + G.rows -3;
    G.B.left_bound = ((T.cols - G.cols)/2)+1;
    G.B.right_bound = G.B.left_bound + G.cols-3;

    G.xfruit = G.B.top_bound + (rand() % (G.rows -2));
    G.yfruit = G.B.left_bound + (rand() % (G.cols -2));


    G.snakeLen = 1;
    G.snakeX[0] = T.rows/2; 
    G.snakeY[0] = T.cols/2;
}

int main() {
    srand(time(NULL));
    setup();
    while(!G.gameOver) {
        logic();
        draw();
        delay(25);
    }
}
