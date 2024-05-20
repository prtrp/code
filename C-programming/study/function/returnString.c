
#include <stdio.h>

char* display();

int main() {
    char* str;
    str = display();
    printf("string is %s", str);
    return 0;
}

char* display() {
    char* str = "Jenny";
    return str;
}

