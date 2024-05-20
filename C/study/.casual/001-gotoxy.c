#include <stdio.h>

// Funzione gotoxy
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    // Clear the screen
    printf("\033[2J");

    // Move the cursor to (10, 5)
    gotoxy(10, 5);
    printf("Hello, World!");

    // Move the cursor to (20, 10)
    gotoxy(20, 10);
    printf("Another text here!\n");

    return 0;
}

