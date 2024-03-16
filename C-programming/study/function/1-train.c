#include <stdio.h>

int sum(int a, int b)
{
  return a + b;
}

int diff(int a, int b)
{
  return a - b;
}

int (*ptr())(int, int)
{
  int selector = 0;
  printf("intser\n1 for sum\n2 for diff\n");
  scanf("%d", &selector);

  if(selector == 1)
    return sum;
  
  else if(selector == 2)
    return diff;

  else
    return NULL;
}

int main()
{
  int (*operator)(int, int) = ptr();
  printf("the result is: %d\n", operator(12, 34));
  return 0;
}
