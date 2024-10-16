#include <stdio.h>
#include <stdlib.h>

//elements for the stack
#define MAX 4
int arr_stack[MAX];
int top = -1;

//function add elements
void push(int element);
//function print stack
void printStk(void);
//function delete element
void pop(void);

int main() {
  int choice = 0, element = 0;
  while(1) {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the top element\n");
    printf("4. Print all the elements\n");
    printf("5. Quit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1 : 
        printf("enter a integer to insert: ");
        scanf("%d", &element);
        push(element);
        break;

      case 2 :
        pop();
        break;

      case 3 :
        printf("%d\n", arr_stack[top]);
        break;

      case 4 :
        printStk();
        break;

      case 5 :
        exit(0);

      default:
        printf("Invalid chice, please try again.\n");
    }
  }
}

void push(int element) {
  if(top == MAX - 1) {
    printf("Stack overflow, can't push\n");
    return;
  }
  arr_stack[++top] = element;
  return;
}

void printStk(void) {
  for(int i = top; i > -1; i--) {
    printf("%d ", arr_stack[i]);
  }
  printf("\n");
}

void pop(void) {
  if(top == -1) {
    printf("Stack underflow, can't pop\n");
    return;
  }
  top--;
}
