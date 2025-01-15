#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    char type;
    void *dtval;
}data;

typedef struct Node {
    data *llval;
    struct Node *next;
}Node;


Node* nodealloc(void);

void apndll(Node **root, data *val);
void printll(Node *root);
void freell(Node **root);

data *sval(char *val);
data *intval(int val);
data *fval(float val);



int main() {

    Node *root = NULL;
    apndll(&root, intval(12));
    apndll(&root, fval(3.14));
    apndll(&root, sval("hello from me lol, i am so glad to write this"));
    apndll(&root, intval(34));
    apndll(&root, intval(12));
    printll(root);
    freell(&root);
    return 0; 
}

Node* nodealloc(void) {

    Node *next_node = NULL;
    next_node = malloc(sizeof(Node));
    if(next_node == NULL) {
        printf("ERROR allocating next node\n");
        exit(1);
    }
    return next_node;
}

void apndll(Node **root, data *val) {

    Node *next_node = nodealloc();
    next_node -> llval = val;
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

data *intval(int val) {

    data *ipval = NULL;
    ipval = malloc(sizeof(data));
    if(ipval == NULL) {
        printf("ERROR MALLOC IPVAL\n");
        exit(1);
    }

    int *pint =  NULL;
    pint = malloc(sizeof(int));
    if(pint == NULL) {
        printf("ERROR INT MALLOC\n");
        exit(1);
    }
    *pint = val;

    ipval -> type = 'i';
    ipval -> dtval = pint;

    return ipval;
}

data *fval(float val) {

    data *fpval = NULL;
    fpval = malloc(sizeof(data));
    if(fpval == NULL) {
        printf("ERROR MALLOC FPVAL\n");
        exit(1);
    }

    float *pfloat = NULL;
    pfloat = malloc(sizeof(float));
    if(pfloat == NULL) {
        printf("ERRORO FLOAT MALLOC\n");
        exit(1);
    }
    *pfloat = val;

    fpval -> type = 'f';
    fpval -> dtval = pfloat;
    return fpval;
}

data *sval(char *val) {

    data *spval = NULL;
    spval = malloc(sizeof(data));
    if(spval == NULL) {
        printf("ERROR MALLOC SPVAL\n");
    }

    spval -> type = 's';
    spval -> dtval = val;

    return spval;
}

void printll(Node *root) {
    
    Node *curr = root;
    while(curr != NULL) {
        switch(curr -> llval -> type) {
            case 'i': {
                printf("%d ", *((int*)curr -> llval -> dtval));
                break;
            }

            case 'f': {
                printf("%f ", *((float*)curr -> llval -> dtval));
                break;
            }

            case 's': {
                printf("%s ", ((char*)curr -> llval -> dtval));
                break;
            }
        }
        curr = curr -> next;
    }
    printf("\n");
}

void freell(Node **root) {
    Node *curr = *root;
    while (curr != NULL) {
        Node *tmp = curr;
        curr = curr -> next;

        if(tmp->llval->type != 's') {
            free(tmp->llval->dtval);
        }

        free(tmp->llval);
        free(tmp);
    }
    *root = NULL;
}
