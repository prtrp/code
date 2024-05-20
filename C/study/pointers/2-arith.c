#include <stdio.h>

void voidPtr();
void addition();
void substraction();

int main()
{
  voidPtr();
  addition();
  substraction();
  return 0;
}

void addition()
{
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  int *p = a;
  
  p = p + 1;
  printf("the number is: %d\n", *p);
} 

void substraction()

{   
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  int *p = a;
  int *q = &a[3];

  printf("the distance is: %d\n", p-q);
  printf("the number is: %d\n", *(q-2));

  printf("%d\n", *p);
  printf("%d\n", *p++);
  printf("%d\n", *p);
}

void voidPtr()
{
  void *vp;
  char a = '\n';
  vp = &a;
  printf("if it work i will printf %d this in the next line\n", *(char*)vp);
}
