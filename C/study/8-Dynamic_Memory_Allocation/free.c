#include <stdio.h>
#include <stdlib.h>

// relese the dynamically allocate memory
// void free(pointer) is not a function that return somethig
// if you try to access to the memory after the free -> UB undefined behaveur
// so after free we will have a dundlign-pointer; so is better to do after ptr = NULL

int main()
{
  int *ptr;
  ptr = (int*)malloc(9*sizeof(int));
  free(ptr);
}
