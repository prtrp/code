#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char* argc[]) {
  int arr1[] = {2, 4};
  int arr2[] = {4, 5};
  if(memcmp(arr1, arr2, 2*sizeof(int)) == 0){ // return a number, 1 or 0
    printf("are the same\n");
  } else {
    printf("are not the same\n");
  }
       //dest //form  // how many
  memcpy(arr1, arr2, 2*sizeof(int));
  printf("%d %d\n", arr1[0], arr1[1]);

  if(memcmp(arr1, arr2, 2*sizeof(int)) == 0){ // return a number, 1 or 0.
    printf("are the same\n");
  } else {
    printf("are not the same\n");
  }

  //memeset()
  return 0;
}
