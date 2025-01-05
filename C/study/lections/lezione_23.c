#include <stdio.h>
#include <stdlib.h>

struct list {
  float *a;
  int c;
  int n;
};
typedef struct list list;

list append(list l, float e );
list init();

int main() {
  int i;
  list l1;

  l1 = init();

  for(i = 0; i < 20; i++) {
    l1 = append(l1, i*10);
  }

  for (i=0; i < l1.n; i++) {
    printf("%f, %d, %d\n", l1.a[i], l1.c, l1.n);
  }
}

list init() {
  list lista_vuota = {NULL, 0, 0};
  return lista_vuota;
}

list append(list l, float e )  {
  if (l.n == l.c) {
    l.c = 2*(l.c+2);
    l.a = realloc(l.a, l.c*sizeof(float));
  }

  l.a[l.n] = e;
  l.n++;

  return l;
}
