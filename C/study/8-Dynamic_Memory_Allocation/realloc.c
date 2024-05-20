#include<stdio.h>
#include<stdlib.h>

// it means reallocation of memory for increse or decreise the size without loosing the preveious content
// realloc(void*pointer, size of size)

int main()
{
  int *ptr, *ptr2;
  ptr = (int*)malloc(5*sizeof(int));
  ptr2 = (int*)realloc(ptr, 7*sizeof(int));
  
  for(int i = 0; i < 5; i ++)
    *(ptr + i) = i;

  for(int i = 4; i < 7; i ++)
    *(ptr2 + i) = i;

  
  for(int i = 0; i < 5; i ++)
    printf(" %d", *(ptr + i));

  printf("\n");
  
  for(int i = 0; i < 7; i ++)
    printf(" %d", *(ptr2 + i));
}

