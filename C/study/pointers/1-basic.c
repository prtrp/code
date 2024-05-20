#include <stdio.h>

int main()
{
  int a = 10;
  int *ptr = &a;
  int **q = &ptr;
  printf("the pointer is: %x, the value is: %d, ptr to ptr %x\n", ptr, *ptr, q);

}

