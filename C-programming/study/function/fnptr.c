#include<stdio.h>

int sum(int a, int b)
{
  return a + b;
}

void displaySum(int(*ptr)(int, int), int a, int b)
{
  printf("the result is: %d\n", ptr(a, b));
}

int main()
{
  displaySum(sum, 3, 7);
}
