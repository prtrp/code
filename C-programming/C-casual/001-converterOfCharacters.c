#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input;
    char x;

    system("cls");
    printf("se vuoi convertire da c a d -> c, altrimenti d: ");
    scanf(" %c", &input);

    if(input == 'c')
    {
        printf("inserire un numer da converire secondo la ASCII: ");
        scanf(" %c", &x);
        printf("il valre achii di '%c' e %d\n", x, x);
    } 
    
    else
    {

        printf("inserire un carattere da convertire secondo la ASCII: ");
        scanf(" %d", &x);
        printf("Il carattere corrispondente al valore ASCII %d e '%c'\n", x, x);
    }

    return 0;
}
