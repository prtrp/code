#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* stralcpy(char *dst, char *src);
int strsize(char *str);

int main() {
    char *a = "hello ";
    char *b = "from me";
    char* c = stralcpy(a, b);
    printf("%s, %d\n", c, strsize(c));
    printf("%d\n", strlen(c));
    return 0;
    
}

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char* stralcpy(char *dst, char *src) {
    int lenDst = strsize(dst);
    int lenSrc = strsize(src);

    char* cpy = malloc(sizeof(char)*(lenDst + lenSrc + 1));
    
    for(int i = 0; i < lenDst; i++) {
        cpy[i] = dst[i];
    }

    for (int j = 0; j < lenSrc; j++){
        cpy[(j+lenDst)] = src[j];
    }
    cpy[lenDst+lenSrc+1] = '\0';


    return cpy;
}
