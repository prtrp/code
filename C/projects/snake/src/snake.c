#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>

struct game {
    bool gameOver;   

    // snake position
    int snakeX[120];
    int snakeY[120];

    // len of snake
    int snakeLen;

    // snake last move
    int lastMove;

    /* cols and rows of the gameScreen*/
    int col, row;

    // position of fruits
    int fruitX;
    int fruitY;

    int score;
};

struct game gm;


struct terminal {
    int rows, cols;
    struct termios orig_term;
};
struct terminal term;


struct dnarr {
    int capacity;
    int indx;
    char *arr;
};

struct dnarr dnarr;

enum key {
    QUIT = 1000,
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

void die (const char *str) {
    write(STDOUT_FILENO, "\x1b[?25h", 6);
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    perror(str);
    exit(1);
}


//------------------------------------------------------------------
//####################### TERMINAL #################################
//------------------------------------------------------------------

void disableRawMode(void) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term.orig_term) == -1) die("tcsetattr");
    write(STDOUT_FILENO, "\x1b[?25h", 6);
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
}

void enableRawMode(void) {
    if (tcgetattr(STDIN_FILENO, &term.orig_term) == -1) die("tcgetattr");

    atexit(disableRawMode);

    struct termios raw = term.orig_term;

    raw.c_iflag &= ~(IGNBRK | BRKINT| PARMRK| ISTRIP| INLCR| IGNCR| ICRNL| IXON);
    raw.c_lflag &= ~(ISIG | ICANON | ECHO | IEXTEN);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);

    raw.c_cc[VTIME] = 1;
    raw.c_cc[VMIN] = 0;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die ("tcsetattr");
}

int getCursorPosition(void) {
    unsigned int i = 0;
    char buff[32];
    if (write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;

    while (i < sizeof(buff) -1) {
        if (1 || read(STDIN_FILENO, &buff[i], 1) != 1) return -1;

        if (buff[i] == 'R') break;
        i++;
    }

    buff[i] = '\0';
    if (buff[0] != '\x1b' || buff[1] != '[') return -1;

    sscanf(&buff[2], "%d;%d", &term.rows, &term.cols);
    return 0;
}

void terminalSize(void) {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_row == 0) {
        write(STDOUT_FILENO, "\x1b[999B\x1b[999C", 12);
        getCursorPosition();
    }
    else {
        term.cols = ws.ws_col;
        term.rows = ws.ws_row;
    }
}

//------------------------------------------------------------------
//####################### DYNIMIC ARRAY ############################
//------------------------------------------------------------------

void apArr(const char *str, int len) {
    if (!str || len <= 0) {
        return;
    }

    int newCapacity = dnarr.capacity;
    while ((newCapacity - dnarr.indx) <= len+1) {
        newCapacity = newCapacity == 0 ? 2 : newCapacity * 2;
    }

    char *new = NULL;
    new = realloc(dnarr.arr, sizeof(char) * (newCapacity));
    if (new == NULL) die("relloc");

    dnarr.capacity = newCapacity;
    dnarr.arr = new;

    memcpy(&dnarr.arr[dnarr.indx], str, len);
    dnarr.indx += len;
    dnarr.arr[dnarr.indx] = '\0';
    
}

void freeArr(void) {
    free(dnarr.arr);
    dnarr.arr = NULL;

    dnarr.indx = 0;
    dnarr.capacity = 0;
} 


//------------------------------------------------------------------
//########################### LOGIC ################################
//------------------------------------------------------------------

int keyRead(void) {
    char ch;
    int nread;

    nread = read(STDIN_FILENO, &ch, 1);
    if (nread == -1 && errno != EAGAIN) die ("read");

    switch(ch) {
        case 'q': return QUIT; break;
        case 'w': return UP; break;
        case 's': return DOWN; break;

        case 'a': return LEFT; break;
        case 'd': return RIGHT; break;

        default : return 0;
    }
}

void moveSnake(void) {
    int key = keyRead();

    if (key == UP && gm.lastMove != DOWN) {
        gm.lastMove = key;

    }else if (key == DOWN && gm.lastMove != UP) {
        gm.lastMove = key;

    } else if (key == LEFT && gm.lastMove != RIGHT) {
        gm.lastMove = key;

    }else if (key == RIGHT && gm.lastMove != LEFT) {
        gm.lastMove = key;
    }

    else if (key == QUIT) {
        gm.lastMove = QUIT;
    }

    switch (gm.lastMove) {
        case QUIT: gm.gameOver = true; break;

        case UP: 
            if (gm.snakeY[0] < 3) gm.snakeY[0] = term.rows;
            else gm.snakeY[0]--; 
            break;

        case DOWN:
            if (gm.snakeY[0] >= term.rows-1) gm.snakeY[0] = 2; 
            else gm.snakeY[0]++;
            break;

        case LEFT: 
            if (gm.snakeX[0] == 1) gm.snakeX[0] = term.cols;
            else gm.snakeX[0]--; 
            break;

        case RIGHT: if (gm.snakeX[0] == term.cols) gm.snakeX[0] = 0;
            gm.snakeX[0]++; 
            break;

        default: break;
    }
}

void moveTail(void) {
    for(int i = gm.snakeLen-1; i > 0; i--) {
        gm.snakeX[i] = gm.snakeX[i-1];
        gm.snakeY[i] = gm.snakeY[i-1];
    }
}

bool isPositionFree(void) {
    for(int i = 0; i < gm.snakeLen; i++) {
        if (gm.fruitX == gm.snakeX[i] && gm.fruitY == gm.snakeY[i]) {
            return false;
        }
    }
    return true;
}

void fruitSpown(void) {
    do {
        gm.fruitX = (rand() % (term.cols-1))+1;
        gm.fruitY = (rand() % (term.rows-1))+1;
    } while (!isPositionFree());
}

void lose(void) {
    for(int i = 1; i < gm.snakeLen; i++) {
        if (gm.snakeX[0] == gm.snakeX[i] && gm.snakeY[0] == gm.snakeY[i]) {
            gm.gameOver = true;
        }
    }
}


void logic (void) {
    if (gm.snakeX[0] == gm.fruitX && gm.snakeY[0] == gm.fruitY) {
        fruitSpown();
        gm.score += 10;
        gm.snakeLen++;
    }  
    lose();
    moveTail();
    moveSnake();
}

//------------------------------------------------------------------
//########################### DRAW #################################
//------------------------------------------------------------------

void drawSnake(void) {
    char buff[64];
    snprintf(&buff[0], sizeof(buff), "\x1b[%d;%dH%c", gm.snakeY[0], gm.snakeX[0], '@');
    apArr(buff, strlen(buff));

    for(int i = 1; i < gm.snakeLen; i++) {
        snprintf(&buff[0], sizeof(buff), "\x1b[%d;%dH%c", gm.snakeY[i], gm.snakeX[i], 'O');
        apArr(buff, strlen(buff));
    }
}

void drawFruit(void) {
    char buff[32];
    snprintf(&buff[0], sizeof(buff), "\x1b[%d;%dH%c", gm.fruitY, gm.fruitX, '*');
    apArr(buff, strlen(buff));
}

void drawScore(void) {
    char buff[32];
    snprintf(&buff[0], sizeof(buff), "\x1b[0;0HScore: %d", gm.score); 
    apArr(buff, strlen(buff));
}

void draw(void) {
    apArr("\x1b[2J\x1b[?25l", 10);
    drawScore();
    drawSnake();
    drawFruit();
    write(STDOUT_FILENO, dnarr.arr, dnarr.indx);
    freeArr();
}


//------------------------------------------------------------------
//########################## MAIN ##################################
//------------------------------------------------------------------

void setup(void) {
    enableRawMode();
    terminalSize();

    // srand() function is used for initialize the random number generator
    // by takeing the seed from where start, usualy use the 0 for indicate
    // the current time
    // time() function return the curretn time as the number of seconds snce
    // the unix epoch 1970 better to use only once.

    srand(time(0));
    fruitSpown();

    gm.gameOver = false;

    gm.lastMove = 0;

    gm.snakeLen = 1;
    gm.score = 0;

    gm.snakeX[0] = term.cols/2;
    gm.snakeY[0] = term.rows/2;
}


int main() {

    setup();

    while (!gm.gameOver) {
        logic();
        draw();
    }
}












