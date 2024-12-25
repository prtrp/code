#include <stdio.h>
#include <stdlib.h>

int *two_sum(int *nums, int numSize, int target, int *returnSize);

int main() {
  int nums[10] = {8, 5, 10, 1, 3, 7, 6, 9, 2, 4}; 
  int numSize = 10;
  int target = 18;
  int returnSize = 0;

  int *result = two_sum(nums, numSize, target, &returnSize);
  if(result == NULL){
    printf("error of resul\n");
    exit(1);
  }
  for(int i = 0; i < returnSize; i++) {
    printf("%d ", result[i]);
  }
  free(result);
  return 0;
  
}

int *two_sum(int *nums, int numSize, int target, int *returnSize) {
  int *arr_result = malloc(2 * sizeof(int));
  if(arr_result == NULL) {
    printf("error of resul\n");
    exit(1);
  }

  for(int i = 0; i < numSize; i++) {
    for(int j = i+1; j < numSize; j++) {
      if(nums[i] + nums[j] == target){
        arr_result[0] = i;
        arr_result[1] = j;
        *returnSize = 2;
        return arr_result;
      }
    }
  }
  *returnSize = 0;
  free(arr_result);
  return NULL;

}
