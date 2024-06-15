#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;

void insert_end(node **root, int value);
void deallocate(node **root);

int main() {
  node *root = NULL;

  insert_end(&root, 23);
  insert_end(&root, 43);
  insert_end(&root, 89);
  insert_end(&root, 76);

  node *i = root;
  while(i != NULL) {
    printf("%d ", i -> value);
    i = i -> next;
  }
  printf("\n");
  return 0;
}

void insert_end(node **root, int value) {
  node *curr = *root;
  node *next_node = malloc(sizeof(node));
  if(next_node == NULL) {
    printf("ERROR NEXT NODE");
    exit(1);
  }

  next_node -> value = value;
  next_node -> next = NULL;

  if(*root == NULL) {
    *root = next_node;
    return;
  }

  while(curr -> next != NULL) {
    curr = curr -> next;
  }
  curr -> next = next_node;
}

void deallocate(node **root) {
  node *curr = *root; // curr = 0x100
  while(curr != NULL) { // cur != NULL
    node *aux = curr; // aur = curr = 0x100, so aur = 0x100
    curr = curr -> next; // cur = 0x200
    free(aux); // free(0x100) questo finche non si arriva a NULL
  }
  *root = NULL;
}
