#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

int main() {
    int val1 = 10;
    int val2 = 21;
    int val3 = 32;

    Node *root = NULL;
    root = malloc(sizeof(Node));
    if(root == NULL) {
        return -1;
    }

    Node *node_1 = NULL;

    (*root).val = val1;
    (*root).next = malloc(sizeof(Node));
    (*(*root).next).val = val2;
    (*(*root).next).next = malloc(sizeof(Node));
    (*(*(*root).next).next).val = val3;
    (*(*(*root).next).next).next = NULL;


    printf("%d %d %d\n", (*root).val, (*(*root).next).val, (*(*(*root).next).next).val); 
    // this happens because the dot notation (.) has a higher priority than the differention (*),
    return 0;
}
