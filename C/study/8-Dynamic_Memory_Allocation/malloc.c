#include <stdio.h>
#include <stdlib.h>

// malloc(size_t size) --> from heap section
// the return type will be a void pointer, generic one

int main()
{
  int n, i, *ptr;
  
  printf("enter the number of numbers that you want to store\n>> ");
  scanf("%d", &n);
  ptr = (int*)malloc(n*sizeof(int));
  
  printf("enter values: ");
  for(i = 0; i < n; i++)
    scanf("%d", (ptr + i));

  printf("the entered values are:\n");
  for(i = 0; i < n; i++)
    printf("%d ", *(ptr + i));

  printf("\n"); free(ptr);

}
