#include <stdio.h>

int sumArr(int[]);  // i can write in this way

int main() {
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  printf("%d ", sumArr(arr));
}

int sumArr(int *arr1) { // and also in this way
  int result = 0;

  for(int i = 0; i < 10; i++) {
    result += arr1[i];
  }
}

