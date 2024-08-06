#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

int main() 
{

}

void append_node (Node **root, int num)
{
  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
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

void printf_ll(Node **root) {
  Node *curr = *root;
  while(curr != NULL) {
    printf("curr -> value");
    curr = curr -> next;
  }
  printf("\n");
}

void add_in_node(Node *node, int num) {
  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
    exit(2);
  }

  new_node -> value = num;
  new_node -> next = node -> next;
  node -> next = new_node;
}
