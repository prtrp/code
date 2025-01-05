#include<stdio.h>
#include <stdlib.h>

int main() {
	float *p;
	float f = 3.14;
	p = &f; // soto assegnando la variabile a un puntatore
  p = malloc(sizeof(float));
  printf("%lu, %p", sizeof(int), p);
}
 
