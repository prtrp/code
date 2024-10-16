#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
  struct Node *prev;
  int value;
  struct Node *next;
}Node;

void dblnklst(void);

int main() {
 dblnklst(); 
}

void dblnklst(void) {
  Node *root = NULL;
  root = (Node*)malloc(sizeof(Node));

  root -> prev = NULL;
  root -> value = 13;
  root -> next = (Node*)malloc(sizeof(Node));
  
  root -> next -> prev = root;
  root -> next -> value = 14;
  root -> next -> next = (Node*)malloc(sizeof(Node));

  root -> next -> next -> prev = root -> next;
  root -> next -> next -> value = 15;
  root -> next -> next -> next = NULL;

  Node *curr = root;
  while(curr != NULL) {
    printf("%d ", curr -> value);
    curr = curr -> next;
  }
}
