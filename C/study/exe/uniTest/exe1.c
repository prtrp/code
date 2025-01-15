#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "hello";

    int n = strlen(a);
    char *b = a+n/2;
    *b = '\0';
    printf("%ld\n", strlen(a)-strlen(b));
}
