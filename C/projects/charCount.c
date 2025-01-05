#include <stdio.h>
#include <stdlib.h>

// struct for the data inside the array
// with the letter and his count
typedef struct data {
    char letter;
    int count;
}data;

// the array of data 
// whith the size of the array
typedef struct list {
    data *dtarr;
    int size;
}list;

// prototype of functions
list* init();
void countChr(list* lst, char val);
void printlst(list* lst);

int main() {
    list *a = init();

    char s[1024];
    char c;

    int i = 0;
    while((c = getchar()) != EOF) {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    for(int j = 0; j < i; j++) {
        countChr(a, s[j]);
    }
    printlst(a);
    return 0;
}

void printlst(list* lst) {
    printf("\n");
    for(int i = 0; i < lst->size; i++ ) {
        printf("%c: ", lst->dtarr[i].letter);
        for(int j = 0; j < lst->dtarr[i].count; j++) {
            printf("#");
        }
        printf("\n");
    }
}

// i have to create a way for count and insrt char
void countChr (list* lst, char val) {
    int i;
    for( i = 0; i < (*lst).size; i++ ) {
        if(lst->dtarr[i].letter == val) {
            lst->dtarr[i].count++;
            return;
        }
    }

    lst->size++;
    lst->dtarr = realloc(lst->dtarr, sizeof(data)*lst->size);
    lst->dtarr[lst->size-1].letter = val;
    lst->dtarr[lst->size-1].count = 1;
}

// create the root of the list
list* init(){
    list *root = malloc(sizeof(list));
    (*root) = (list){NULL, 0};
    return root;
}
