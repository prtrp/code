#include <stdio.h>
int binary_search(int *arr, int size, int val);

int main() {
  int arr[32] = {2, 5, 10, 14, 23, 25, 45, 50, 102, 104};
  printf("%d\n", binary_search(arr, 10, 2));
  return 0;
}

int binary_search(int *arr, int size, int val) {
  int lx = 0;
  int rx = size-1;

  while(lx <= rx) {

    int m = (lx + rx) / 2;
    if( arr[m] == val) {
      return m;
    }
    else if(arr[m] > val) {
      rx = m-1;
    }
    else if (arr[m] < val) {
      lx = m+1;
    }
  }
  return -1;
}
