#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *find_odd (size_t length, const int array[length]) {
  int *result = (int*)malloc(sizeof(int));
  
  for(int i = 0; i < length; i++){
    if(array[i] == array[i+1]){
      continue;
    }
    else {
      int j  = 0;
      result = realloc(result, (length+1)*sizeof(int));
      result [j] = array[i];
    } 
  }
  return result;
}

int main() {
  const int arr[11] = {1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5};
  int *res = find_odd(11, arr);
  int length = (sizeof(res)/sizeof(int));
  for(int i = 0; i < length; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
  return 0;
}
