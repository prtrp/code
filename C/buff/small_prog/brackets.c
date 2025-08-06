#include <stdlib.h>
#include <stdio.h>

typedef struct stack {
    int *ptr;
    int size;
    int indx;

}stack;

void push_stk(stack **a, int b) {
    int *new_elmnt = malloc(sizeof(int));

    if (*a == NULL) {
        *a = malloc(sizeof(stack));
        (*a)->ptr = new_elmnt;
        (*a)->ptr[0] = b; 
        (*a)->size = 1;
        return;
    }


}

void prnt_stk(stack *a) {

    printf("%d", a -> ptr);
    printf("\n");
}

int main() {
    stack *st = NULL;
    printf("%d\n", &st);

    push_stk(&st, 3);
    prnt_stk(st);
    
    free(st);
    return 0;
}
