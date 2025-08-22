//############################################################
//-----------------------INCLUDES-----------------------------
//############################################################


#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>



//############################################################
//--------------------------DATA------------------------------
//############################################################


/* creating the original settings terminal */
struct termios orig_termios;



//############################################################
//-----------------------TERMINAL-----------------------------
//############################################################


void die(const char *s) {
    perror(s);
    exit(1);
}

void disableRawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) die("tcsetattr");     
}

void enableRawMode() {

    /* read attributes of terminal
     * take inital attributes*/
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");

    /* before exit call this function 
     * comes from stdlib.h */
    atexit(disableRawMode);

    /* create the raw mode terminal attribtes*/
    struct termios raw = orig_termios;

     /* change the attributes inside the place holder 
     * c_lflag means local flags
     *
     * ~(ECHO)      Disable echoing of typed characters
     *
     * ~(ICANON)    read byte by byte and not buffering
     *
     * ~(ISIG)      Disable SIGINT (Ctrl+C) and SIGTSTP (Ctrl+Z) signals
     *
     * ~(IEXTEN)    disable extended input processing (Ctrl+V) */
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);

    /* c_iflag means input flag 
     *
     * ~(IXON)      disable stop or resume stram data ctrl-S or ctrl-Q
     *
     * ~(ICRNL)     disabled do not translate CR to NL
     *
     * ~(BRKINT)    if turned on, a SIGINT can kill the program like Ctrl-C
     *
     * ~(ISTRIP)    disable stripping of 8th bit
     *
     * ~(INPCK)     disabile parity checking */
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

    /* c_cflag means control flag 
     * (CS8) is a bit mask, sets character size to 8 bits per bytes */
    raw.c_cflag |= (CS8);

    /* c_oflag means output flag
     * ~(OPOST) do not process the output (not convert \n to \r\n */
    raw.c_oflag &= ~(OPOST);

    /* c_cc stands for control character 
     * VMIN     sets the minimum bytes of input needed before read() can return
     * VTIME    sets the maximum amout of time to wait before read() can return */
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    /* set attributes for terminal of out place holder into
     * the actual terminal 
     * TCSAFLUSH specifies when to apply the changes, in this 
     * case waits for all pending output to be written to the terminal,
     * discard any input that hasn't been read */
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}



//############################################################
//--------------------------INIT------------------------------
//############################################################


int main() {
    enableRawMode();

    /* read() and STDIN_FILENO comes from unistd.h
    *  read() will read 1 byte from standard input inside c
    *  and will do it unitll have no bytes to read 
    *  it by defoult uses coocked mode, but we need raw mode */
    
    while (1) {
        char c = '\0';
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");

        if (iscntrl(c)) printf("%d\r\n", c);
        else printf("%d ('%c')\r\n", c, c);

        if (c == 'q') break;
    }

    return 0;
}
