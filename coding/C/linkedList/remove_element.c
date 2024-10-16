#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void remove_element(Node **root, int value);

int main(void) {
  Node *root = NULL;
}

void remove_element(Node **root, int num) {
  if(*root == NULL) {
    return;
  }
  
  if((*root) -> value == num) {
    Node *to_remove = *root;
    *root = (*root) -> next;
    free(to_remove);
    return;
  }

  for(Node *curr = *root; curr -> next != NULL; curr = curr -> next) {
    if(curr -> next -> value == num) {
      Node* to_remove = curr-> next;
      curr -> next = curr -> next -> next;
      free(to_remove);
    }
  }
}
