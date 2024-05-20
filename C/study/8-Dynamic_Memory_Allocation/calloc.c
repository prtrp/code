#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n, i, *ptr;

  printf("insert the number of element to insert");
  scanf("%d", &n);

  ptr = (int*)calloc(n, sizeof(int));

  printf("insert the %d numbers\n>> ", n);
  for(i = 0; i < n; i++)
    scanf("%d", (ptr + i));

  printf("the nubers are:\n");

  for(i = 0; i < n; i++)
    printf("%d ", *(ptr + i));
}
