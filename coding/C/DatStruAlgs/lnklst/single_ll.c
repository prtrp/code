#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct endPnt {
  struct Node *root;
  struct Node *end;
} endPnt;

Node* createNde(int);
void appndNde(endPnt *list, int value, int pos);
void printLL(endPnt list);
void rmNde(endPnt *list, int pos);
void revLnklst(endPnt *list);

int main() {
  endPnt list = {NULL, NULL};
  appndNde(&list, 34, -1);
  appndNde(&list, 35, -1);
  appndNde(&list, 36, -1);
  appndNde(&list, 37, -1);
  appndNde(&list, 33, 0);
  appndNde(&list, 31, 0);
  appndNde(&list, 32, 1);
  printLL(list);
  rmNde(&list, -1);
  printLL(list);
  rmNde(&list, 0);
  printLL(list);
  revLnklst(&list);
  printLL(list);
}
// it is used for alloc memory for Nodes
Node* createNde(int num) {
  Node *new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL) {
    perror("ERROR WITH NODE");
    exit(EXIT_FAILURE);
  } 
  new_node -> next = NULL;
  new_node -> value = num;
  return new_node;
}

void appndNde(endPnt *list, int num, int pos){
  Node* new_node = createNde(num);
  if((list -> root ) == NULL) {
    list -> root = new_node;
    list -> end = new_node;
    return;
  }

  // append at the last node of ll
  if(pos == -1) {
    list -> end ->next = new_node;
    list -> end = new_node;
  }
  // append at the beginning
  else if (pos == 0){
    new_node -> next = list -> root;
    list -> root = new_node;
  }
  // append inside a ll
  else {
    Node *curr = list -> root;
    for(int i = 1; i < pos; i++) {
      curr = curr -> next; 
    }
    new_node -> next = curr -> next;
    curr -> next = new_node;
  }
}
// remove a node inside the ll
void rmNde(endPnt *list, int pos) {
  Node *curr = list -> root;
  Node *aux = NULL;

  // check if there are no value
  if(list -> root == NULL) {
    printf("there are nothing do remove\n");
    return;
  }

  // remove the ll if are only one value
  if(list -> root == list -> end) {
    printf("there are only one node\n");
    free(list -> root);
    list -> root = NULL;
    list -> end = NULL;
    return;
  }

  // remove the last element of ll
  if(pos == -1) {
    while((curr -> next -> next) != NULL) {
      curr = curr -> next;
    }
    aux = curr -> next;
    curr -> next = NULL;
    list -> end = curr;
    free(aux);
    return;
  } 
  // remove the first element of ll
  else if(pos == 0) {
    aux = list -> root;
    list -> root = list -> root -> next;
    free(aux);
    return;
  }
  // remove a index inside the ll
  else {
    for(int i = 1; i < pos; i++) {
      curr = curr -> next; 
    }
    aux = curr -> next;
    curr -> next = curr -> next -> next;
    free(aux);
  }
  
}
// reverse the linked list 
void revLnklst(endPnt *list) {
  Node *curr = list -> root;
  Node *prev = NULL, *next;
  list -> end = list -> root;

  while(curr != NULL) {
    next = curr -> next;
    curr -> next = prev;
    
    prev = curr;
    curr = next;
  }
  list -> root = prev;
}

// for print the ll
void printLL(endPnt list) {
  Node *curr = list.root;
  while(curr != NULL) {
    printf("%d ", curr -> value);
    curr = curr -> next;
  }
  printf("\n");
}
