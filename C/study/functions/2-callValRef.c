#include <stdio.h>

void callVal(int*, int*);

int main()
{
  int a, b;
  
  a = 10;
  b = 11;

  printf("%d, %d\n", a, b);
  callVal(&a, &b);
  printf("%d, %d\n", a, b);
  return 0;
}

void callVal(int* a, int* b)
{
 *a = 20;
 *b = 21;
} 
