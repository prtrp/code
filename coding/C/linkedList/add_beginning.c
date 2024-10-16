#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void insert_beginning(Node **root, int num);
void append_node(Node **root, int num);
void printf_ll(Node **root);
void dealloc_ll(Node **root);

int main() {
  Node *root = NULL;
  append_node(&root, 23);
  append_node(&root, 43);
  append_node(&root, 63);
  append_node(&root, 93);
  append_node(&root, 33);
  printf_ll(&root);

  insert_beginning(&root, 12);
  printf_ll(&root);

  dealloc_ll(&root);
};

void printf_ll(Node **root) {
  Node *curr = *root;
  while (curr != NULL) {
    printf("%d ", curr -> value);
    curr = curr -> next;
  }
  printf("\n");
}

void append_node(Node **root, int num) {
  Node* new_node = malloc(sizeof(Node));
  
  new_node -> value = num;
  new_node -> next = NULL;

  if(*root == NULL) {
    *root = new_node;
    return;
  }
  
  Node *curr = *root;
  while(curr -> next != NULL) {
    curr = curr -> next;
  }
  curr -> next = new_node;
}

void insert_beginning(Node **root, int num) {
  Node* new_node = malloc(sizeof(Node));
  new_node -> value = num;
  new_node -> next = *root;

  *root = new_node;
}

void dealloc_ll(Node **root) {
  Node *curr = *root;
  while (curr != NULL){
    Node *aux = curr;  
    curr = curr -> next;
    free(aux);
  }
  root = NULL;
} 
