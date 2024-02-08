#include <stdio.h>

// a function pointer is a function that store the address of a function
// return type of function (*pointer_name)(dataType of arguments);

// int *p = & -name of variable- --> how to declare a pointer
// int (*ptr)(int, int) = &-name of function-

int sum(int, int);

void main()
{
  int s = 0;
  int (*ptr)(int, int) = &sum;
  s = (*ptr)(1,2);
  printf("sum = %d\n", s);
}

int sum(int a, int b)
{
  return a + b;
}
