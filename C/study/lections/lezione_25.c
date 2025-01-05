#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    char tipo;
    void *dato;  // usato per indicare un place holder per essere convertito
} elemento;

typedef struct lista {
    elemento *a;
    int capacity;
    int size;
}lista;

lista init();
lista pop(lista l1);
void prntlst(lista);
lista insert(lista l1, elemento e, int pos);
lista append(lista, elemento);

elemento intero(int d);
elemento fpoint(float d);
elemento stringa(char *d);

int main() {
    lista l1 = init();

    l1 = append(l1, intero(10));
    l1 = append(l1, fpoint(10.343));
    l1 = append(l1, stringa("questa è una stringa"));
    l1 = append(l1, stringa("informatica"));

    prntlst(l1);

}

lista init() {
    lista lista_vuota = {NULL, 0, 0};
    return lista_vuota;
}

lista append(lista l1, elemento e) {
    if (l1.capacity == l1.size) {
        l1.capacity = l1.capacity == 0 ? 2 : l1.capacity*2;
        l1.a = realloc(l1.a, l1.capacity*sizeof(e));
    }
    l1.a[l1.size] = e;
    l1.size++;

    return l1;
}

void prntlst(lista l1) {
    int i;

    for(i = 0; i < l1.size; i++) {
        switch(l1.a[i].tipo) {
            case 'i':
                printf("%d\n", *((int*)l1.a[i].dato));
                break;
            
            case 'f':
                printf("%f\n", *((float*)l1.a[i].dato));
                break;

            case 's':
                printf("%s\n",((char*)l1.a[i].dato));
                break;
        }
    }
}

lista pop(lista l1) {
    if(l1.size > 0) {
        if(l1.size < l1.capacity/4) {
            l1.capacity = l1.capacity/2;
            l1.a = realloc(l1.a, sizeof(lista)*l1.capacity);
        }
        if(l1.a[l1.size-1].tipo != 's') {
            free(l1.a[l1.size-1].dato);
        }
    }
    return l1;
}

lista insert(lista l, elemento e, int pos) {
    int i;
    l = append(l, e);

    for(i = l.size -1; i > pos; i--) {
        l.a[i] = l.a[i-1];
    }
    l.a[pos] = e;

    return l;
}


elemento intero(int d) {
	elemento e ={'i', NULL};
	e.dato = malloc(sizeof(int));
	*((int*)e.dato) = d;
	return e;
}

elemento fpoint(float d) {
	elemento e ={'f', NULL};
	e.dato = malloc(sizeof(float));
	*((float*)e.dato) = d;
	return e;
}

elemento stringa(char *d) {
	elemento e ={'s', NULL};
	e.dato = d;
	return e;
}
