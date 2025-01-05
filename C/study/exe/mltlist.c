#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type;
    void *val;
} data;

typedef struct {
    data *ptarr;
    int size;
    int capacity;
} list;

list append(list a, data e);
list init();
list insert(list, data, int);

void printlst(list);

data intval(int val);
data fval(float val);
data strval(char *val);

int main() {
    list a = init();
    a = append(a, intval(9));
    a = append(a, fval(3.14));
    a = append(a, strval("ciaoo"));
    a = append(a, intval(4));
    a = append(a, fval(2.23));
    a = append(a, intval(9));
    //printf("%d\n", ((int*)a.ptarr->val)[1]); understand why work only for the 0 element.
    printlst(a);
}

list init() {
    list root = {NULL, 0, 0};
    return root;
}

list append(list a, data e) {
    if(a.capacity == a.size) {
        a.capacity = (a.capacity == 0) ? 2 : a.capacity*2;
        a.ptarr = realloc(a.ptarr, sizeof(data)*a.capacity);
    }
    a.ptarr[a.size] = e;
    a.size++;
    return a;
}

list insert(list a, data e, int p) {
    int i;
    a = append(a, e);
    if(p < 0) {
        p = 0;
    }
    for(i = a.size-1; i > p; i--) {
        a.ptarr[i] = a.ptarr[i-1];
        a.ptarr[i-1] = e;
    }
    return a;

}

data intval(int val) {
    data e = {'i', NULL};
    e.val = malloc(sizeof(int));
    *((int*)e.val) = val;
    return e;
}

data fval(float val) {
    data e = {'f', NULL};
    e.val = malloc(sizeof(float));
    *((float*)e.val) = val;
    return e;
}

data strval(char *val) {
    data e = {'s', NULL};
    e.val = val;
    return e;
}

void printlst(list a) {
    int i;
    for (i = 0; i < a.size; i++) {
        switch(a.ptarr[i].type) {
            case 'i':
                printf("%d ", *((int*)a.ptarr[i].val));
                break;

            case 'f':
                printf("%f ", *((float*)a.ptarr[i].val));
                break;

            case 's':
                printf("%s ", (char*)a.ptarr[i].val);
                break;
        }
    }
}
