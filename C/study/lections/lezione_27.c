#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type;
    void *val;
}data;

typedef struct {
    data *ptarr;
    int size;
    int capacity;
}list;

list init();
char srcType(char *b);
void printlst(list a);
list append(list, data);
data intval(int);
data fval(float);
data strval(char *);

int main() {
    list a = init();
    char buff[1024];

    while(1) {
        printf("inserisci un int, float o stringa e premi invio: ");

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            break; // Gestione EOF (Ctrl+D)
        }

        // Rimuovi il newline (\n) se presente
        size_t len = strlen(buff);
        if (len > 0 && buff[len - 1] == '\n') {
            buff[len - 1] = '\0';
        }

        // Esci se l'input è vuoto
        if (buff[0] == '\0') {
            break;
        }
        int e;
        float f;
        char *s;

        switch(srcType(buff)) {
            case 'i':
                a = append(a, intval(e));
                break;

            case 'f':
                sscanf(buff, "%f", &f);
                a = append(a, fval(f));
                break;

            default:
                s = malloc(sizeof(char)*(strlen(buff)+1));
                strcpy(s, buff);
                a = append(a, strval(s));


        }
    }
    printlst(a);
    printf("\n");
}


list init() {
    list root = {NULL, 0, 0};
    return root;
}

char srcType(char *b){
    int i = 0, nmPoint = 0;
    
    while(b[i] != '\0') {
        if(b[i]=='.') {
            if(nmPoint > 0) {
                return 's';
            }
            else {
                nmPoint++;
            }
        }
        else if(b[i] < '0' || b[i] > '9') {
            return 's';
        }
        i++;
    }
    if (nmPoint == 0) {
        return 'i';
    }
    else {
        return 'f';
    }
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
