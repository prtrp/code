#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int stack_arr[MAX];
int top = -1;

void push(int data);
void pushBg(int data);
int pop(void);
void printStk(void);

int isFull(void);
int isEmpty(void);

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  pushBg(3);
  printStk();
}

void push(int data) {
  if(isFull()) {
    printf("Stack overflow\n");
    return;
  }
  top += 1;
  stack_arr[top] = data;
}

int pop(void) {
  if(isEmpty()) {
    printf("Stack underflow\n");
    exit(1);
  }
  int value = stack_arr[top];
  top = top - 1;
  return value;
}

int isFull(void) {
  if(top == MAX - 1) {
    return 1;
  }
  return 0;
}

int isEmpty(void) {
  if(top == -1) {
    return 1;
  }
  return 0;
}

void pushBg(int data) {
  for(int i = top; i > 0; i--) {
    stack_arr[i+1] = stack_arr[i];
  } 
  stack_arr[0] = data;
}

void printStk(void) {
  int i = 0;
  if(top == -1) {
    printf("Stack underflow\n");
    return;
  }
  for(int i = top; i > -1; i--) {
    printf("%d ", stack_arr[i]);
  }
  printf("\n");
}
