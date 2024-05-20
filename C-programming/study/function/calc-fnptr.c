#include <stdio.h>

int sum(int a, int b)
{
  return a+b;
}

int diff(int a, int b)
{
  return a-b;
}

int mult(int a, int b)
{
  return a*b;
}
int div(int a, int b)

{
  return a / b;
}

int(*ptr())(int, int)
{
  int a;
  printf("please select a operation\n1) sum\n2) diff\n3) mult\n4) div\n");
  scanf("%d", &a);
  
  if (a == 1)
    return sum;

  else if ( a == 2)
    return diff;

  else if (a == 3)
    return mult;

  else if (a == 4)
    return div;

  else
    return NULL;
}

int main()
{
  int (*opt_ptr)(int, int) = ptr();

  printf("the result is: %d\n", opt_ptr(6, 3));
}


