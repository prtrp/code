#include <stdio.h>
#include <stdlib.h>
#include "../lib/fun_ll.h"

void append_node(Node **root, int num)
{
  Node* next_node = malloc(sizeof(Node));
  if(next_node == NULL) {
    exit(2);
  }
  
  next_node -> value = num;
  next_node -> next = NULL;

  if((*root) == NULL) {
    *root = next_node;
    return;
  }
  
  Node* curr = *root;
  while(curr -> next != NULL){ 
    curr = curr -> next;
  }
  curr -> next = next_node;
}


void printf_ll(Node **root)
{
  Node* curr = *root;
  while(curr != NULL) {
    printf("%d ", curr -> value);
    curr = curr -> next;
  }
  printf("\n");
}

void dealloc_ll(Node **root)
{
  Node* curr = *root;

  while(curr != NULL) {
    Node* aux = curr;
    curr = curr -> next;
    free(aux);
  }
}

void add_beginning(Node **root, int num)
{
  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
    printf("New node is null");
    exit(2);
  }
  new_node -> value = num;
  new_node -> next = *root;

  *root = new_node;
} 
