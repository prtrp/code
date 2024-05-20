#include <stdio.h>

int* returnPtr(int[]);

int main() {
  int *ptr;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  ptr = returnPtr(arr);
  printf("%d\n", *ptr);
}

int* returnPtr(int a[]) {
  a = a + 2;
  return a;
}
