#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char letter;
    int count;
    struct node *next;
}node;

// append node
void apndNde(node **root, char const letter) {
    node *new_node = NULL;
    new_node = malloc(sizeof(node));
    if(new_node == NULL) { perror("error with malloc"); exit(0);}

    new_node -> letter = letter;
    new_node -> count = 1;
    new_node -> next = NULL;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    node *curr = *root;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }
    curr -> next = new_node;

    return;
}

// print node
void prntNde(node *root) {
    node *curr = root;

    while (curr != NULL) {
        printf("%c: ", curr -> letter);
        for (int i = 0; i < curr -> count; i++) {
            printf("#");
        }
        curr = curr -> next;
        printf("\n");
    }
}

// funciton of check word
void chkwrd(node **root, char chr) {
    node *curr = *root;
    while (curr != NULL) {
        if (curr -> letter == chr) {
            curr -> count++;
            return;
        }
        curr = curr -> next;
    }
    apndNde(root, chr);
} 

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("enter the string between \"\"\n");
        return 0;
    }

    node *root = NULL;

    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++) {
        chkwrd(&root, argv[1][i]);
    }

    prntNde(root);

    return 0;

}


