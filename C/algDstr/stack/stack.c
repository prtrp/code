#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct stack {
    int *arr;
    int top;
} stack;

int isEmpty(stack *stk) {
    return stk->top == -1;
}

int isFull(stack *stk) {
    return stk -> top == MAX_SIZE-1;
}

void initialize(stack **stk) {
    if (*stk == NULL) {
        (*stk) = malloc(sizeof(stack));
        (*stk) -> arr = malloc(sizeof(int)*MAX_SIZE);
        (*stk) -> top = -1;
        return;
    }
    printf("stack alredy initialized\n");
    return;
}

void push (stack **stk, int n) {
    if (*stk == NULL) { printf("not initialized\n"); return; }
    if (isFull(*stk)) {
        printf("stack overflow\n");
        return;
    }
    (*stk)->arr[++(*stk)->top] = n;
}

int pop(stack **stk) {
    if (*stk == NULL) { printf("not initialized\n"); return -1; }
    if (isEmpty(*stk)) { printf("nothing to remove, is empty\n"); return -1; }

    int ret = (*stk) -> arr[(*stk)-> top];
    (*stk) -> top--;

    return ret;
}

int peek(stack *stk) {
    if (stk == NULL) { printf("not initialized\n"); return; }
    if (isEmpty(stk)) { printf("nothing to print, is empty\n"); return; }

    int top_num = stk -> arr[stk -> top];
    printf("top element in stack: %d", top_num);
    return ;
}

void freeStk(stack **stk) {
    if (*stk == NULL) { printf("nothing to free"); return; }
    free((*stk) -> arr);
    free(*stk);
    *stk = NULL;
    return;
}

int main() {
    stack *stk = NULL;

    initialize(&stk);
    push(&stk, 100);
    freeStk(&stk);
    return 0;
}
