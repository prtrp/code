#ifndef FUN_LL_H
#define FUN_LL_H

typedef struct Node {
  int value;
  struct Node* next;
}Node;

void append_node(Node **root, int num);
void printf_ll(Node **root);
void dealloc_ll(Node **root);
void add_beginning(Node **root, int num);
#endif
