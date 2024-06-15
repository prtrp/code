#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void insert_end(Node **, int);
void insert_start(Node **, int);
void insert_node(Node *, int); 

int main() {
  Node *root = NULL;

  insert_end(&root, 44);
  insert_end(&root, 54);
  insert_end(&root, 64);
  insert_node(root, 34);
  insert_end(&root, 74);
  insert_end(&root, 54);
  insert_node(root, 34);
  insert_node(root, 44);
  insert_node(root, 14);

  Node *i = root;
  while(i != NULL) {
    printf("%d ", i -> value);
    i = i -> next;
  }
  printf("\n");
}

void insert_end(Node **root, int num){
  Node *next_node = malloc(sizeof(Node));
  if(next_node == NULL) {
    printf("ERROR WITH NEXT NODE");
    return;
  }
  next_node -> value = num;
  next_node -> next = NULL;

  if(*root == NULL) {
    *root = next_node;
    return;
  }

  Node *curr = *root;
  while(curr -> next != NULL) {
    curr = curr -> next;
  }
  curr -> next = next_node;
}

void insert_start(Node **root, int num) {
  Node *start_node = malloc(sizeof(Node));
  if(start_node == NULL) {
    printf("ERROR WITH START POINTER");
    exit(4);
  }

  start_node -> value = num;
  start_node -> next = *root;
  *root = start_node;
}

void insert_node(Node *node, int num) {
  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
    printf("ERROR WITH NEW NODE");
    exit(4);
  }

  if(node == NULL) {
    insert_start(&node, num);
    return;
  }
  new_node -> value = num;
  new_node -> next = node -> next;
  node -> next = new_node;
  return;
}

