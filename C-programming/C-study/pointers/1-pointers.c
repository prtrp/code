#include <stdio.h>

void startPointers()
{
  int a = 10;
  float b = 1;

  // datatype *pointer-name; --> for declare a pointer

  int *p; // naw p is a pointer (declaration)
  p = &a; // i am saying thath in p have memory address a (initialization)
  // naw p point to a

  float *j = &b;

  printf("%d, %f\n", *p, *j); // dereferencing
}

void pointersToPointers()
{
  int a = 10;
  int *p = &a;
  int **q = &p;
  int ***j = &q;
  printf("%d, %d, %d\n", *p, *(*q), *(*(*j)));
}


int main()
{
  // startPointers();
  pointersToPointers();
}
