#include <stdio.h>
#include <stdlib.h>

void logicalOperators();

int main()
{

    logicalOperators();
    return 0;
}

void logicalOperators()
{
    int input, a= 1, b = 6;

    system("cls");
    printf("if you put a number higher than 5, i will say hallo world, else... : \n");
    scanf(" %d", &input);

    input > 5 && printf("hello word\n") || printf("not hello\n");
    printf("%d", a-- && b++);
}


