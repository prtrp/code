#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dnarr {
    int capacity;
    int indx;
    char *str;
}dnarr;

dnarr gamearr = {0, 0, NULL};


void apndArr(char *str, int len) {
    while ((gamearr.capacity - gamearr.indx) <= len+1)
        gamearr.capacity = gamearr.capacity == 0 ? 2 : gamearr.capacity*2;

    char *new = NULL;
    new = realloc(gamearr.str, sizeof(char)*gamearr.capacity);
    if (new == NULL) {
        exit(1);
    }

    gamearr.str = new;

    memcpy(&gamearr.str[gamearr.indx], str, len);
    gamearr.indx += len;

}

int main() {
    char *str = "hello world i am petru";
    apndArr(str, 22);
    char *str2 = "hello world i am michele";
    apndArr(str2, 24);
    apndArr("\x1b[7m", 4);
    char *str3 = "hello world i am lol";
    apndArr(str3, 20);
    printf("%s\n", gamearr.str);

}
