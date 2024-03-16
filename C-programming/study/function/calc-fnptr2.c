#include <stdio.h>

int add(int a, int b)
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
  return a/b;
}


int(*opr_ptr())(int, int)
{
  int select;

  printf("insert a number:\n1 -> sum\n2 -> diff\n3 -> mult\n4 -> div\n>> ");
  scanf("%d", &select);

  switch(select){
    case 1:
      return add;
      break;

    case 2:
      return diff;
      break;

    case 3:
      return mult;
      break;

    case 4:
      return div;
      break;

    default:
      return NULL;
      break;

  }
}


int main()
{
  int(*opt)(int, int) = opr_ptr();

  printf("the result is: %d\n", opt(4, 3));
}
