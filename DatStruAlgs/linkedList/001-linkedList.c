#include <stdio.h>
#include <stdlib.h>

// create a structure
typedef struct Node {
  int value;
  struct Node* next;
} Node;

// Function declaration
void link_list1(void);
void link_list2(void);
void insert_end(Node**, int);

// start to coding linked Lists
int main(int argc, char *argv[]) {
  Node *root;
  root = NULL;

  insert_end(&root, 15);
  insert_end(&root, 25);
  insert_end(&root, 666);

  for(Node *curr = root; curr != NULL; curr = curr -> next) {
    printf("%d ", curr -> value);
  }
  printf("\n");
  return 0;

}


void insert_end(Node** root, int value) {
  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
    printf("new Node is null\n");
    exit(1);
  }
  new_node -> next = NULL;
  new_node -> value = value;

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

void link_list1(void) {
  Node root, elem2, elem3;
  root.value = 5;
  root.next = &elem2;

  elem2.value = 12;
  elem2.next = &elem3;

  elem3.value = 334;
  elem3.next = NULL;

  printf("%d\n", root.value);
  printf("%d\n", root.next -> value);
  printf("%d\n", (*(*root.next).next).value );
}

void link_list2(void) {
  Node root;
  root.value = 15;
  root.next = malloc(sizeof(Node));
  
  root.next -> value = 23;
  root.next -> next = malloc(sizeof(Node));

  root.next -> next -> value = 345;
  root.next -> next -> next = malloc(sizeof(Node));

  root.next -> next -> next -> value = 645;
  root.next -> next -> next -> next = NULL;

  /*
  printf("%d\n", root.value);
  printf("%d\n", root.next -> value);
  printf("%d\n", root.next -> next -> value);
  printf("%d\n", root.next -> next -> next -> value);
  we can write this like:
  */ 

  for(Node *curr = &root; curr != NULL; curr = curr -> next) {
    printf("%d", curr -> next);
  }

  printf("\n");

  free(root.next);
}

