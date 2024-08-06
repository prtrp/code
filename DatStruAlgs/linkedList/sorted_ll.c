#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
}Node ;

void append_node(Node **root, int num);
void dealloc_ll(Node **root);
void insert_beginning(Node **root, int num);
void insert_sorted(Node **root, int num);
void insert_after(Node *node, int num);

int main(void) {
  Node *root = NULL;

}

void insert_sorted(Node **root, int num) {
  if(*root == NULL || (**root).value >= num) {
    insert_beginning(root, num);
    return;
  }

  Node *curr = *root;
  while (curr -> next != NULL) {
    if(curr -> next -> value >= num) {
      insert_after(curr, num);
      return;
    }
    curr = curr -> next;
  }
  
}

void insert_after(Node *node, int num) {
  Node *new_node = malloc(sizeof(Node));
  Node *aux = NULL;

  if(new_node == NULL) {
    printf("ERROR CREATING NEW NODE\n");
    exit(2);
  }

  new_node -> value = num;
  new_node -> next = node -> next;
  node -> next = new_node;
} 

void append_node(Node **root, int num) {
  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
    printf("ERROR CREATING NEW NODE\n");
    exit(2);
  }

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

void dealloc_ll(Node **root) {
  Node *curr = *root;
  while(curr != NULL) {
    Node *aux = curr;
    curr = curr -> next;
    free(aux);
  }
  root = NULL;
}

void insert_beginning(Node **root, int num) {
  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
    printf("ERROR CREATING NEW NODE\n");
    exit(2);
  }

  new_node -> value = num;
  new_node -> next = NULL;

  if(*root == NULL) {
    *root = new_node;
    return;
  }

  new_node -> next = *root;
  *root = new_node;
}
