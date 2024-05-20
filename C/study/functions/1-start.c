#include <stdio.h>

int sum(int, int); // it is the declaration

int sum(int a, int b) // definition
{
  return a + b;
}

int main()
{
  printf("the sum is: %d\n", sum(3, 5)/*calling the function*/);
}
