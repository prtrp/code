#include <stdio.h>

void add(int a, int b){printf("%d\n", a + b);}
void sub(int a, int b){printf("%d\n", a - b);}
void div(int a, int b){printf("%d\n", a * b);}
void mult(int a, int b){printf("%d\n", a / b);}


int main()
{
  int ch, a,b;
  void (*fptr[10])(int, int) = {add, sub, mult, div};
  // there we ar saying that we create an array of pointers, which inside
  // have functions that have 2 parameters 

  printf("press:\n 0 for add\n 1 for sub\n 2 for div\n 3 for mult\n enter a choice:\n");
  scanf("%d", &ch);
  printf("enter a and b:\n");
  scanf("%d %d", &a, &b);
  (*fptr[ch])(a,b);


  
}
