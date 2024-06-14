#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  int a = 13;
  int *b = &a;

  int c = 45;
  int *p = &c;

  int **ptr = &p;
  printf("%p, %d\n", *ptr, **ptr);

  ptr = &b;
  printf("%p, %d\n", *ptr, **ptr);
}
