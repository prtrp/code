#include <stdio.h>

int sum(int a, int b) {
  return a + b;
}

int diff(int a, int b) {
  return a - b;
}

int mult(int a, int b) {
  return a * b;
}

int div(int a, int b) {
  return a / b;
}

int main(void) {
  printf("[1] sum\n[2] diff\n[3] mult\n[4] div\n>> ");
  int result;
  scanf("%d", &result);
  int (*ptrFn[4]) (int, int) = {sum, diff, mult, div};
  printf("the result is: %d\n", ptrFn[result-1](2, 5));
}
