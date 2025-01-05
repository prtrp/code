#include <stdio.h>
#include <stdlib.h>

typedef strcut nodo {
    flaot val;
    nodo *succ;
} nodo;


typedef *nodo clista;

clist clista_nuova();

int main() {
    clista l = clista_vuota();

    nodo q = {3.14, NULL};
    nodo p = {0.0, NULL};

    l = &q; // q in testa alla lista
    
    
    
}

clista clista_nuova() {
    return NULL;
}
