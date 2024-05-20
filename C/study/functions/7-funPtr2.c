#include <stdio.h>

int sum (int a, int b) {
  return a + b;
}

int diff (int a, int b) {
  return a - b;
}

int mult (int a, int b) {
  return a * b;
}

int div (int a, int b) {
  return a / b;
}

int (*ptrFn()) (int, int) {
  int result;
  printf("insert:\n1) sum\n2) diff\n3) mult\n4) div\n");
  scanf("%d", &result); 

  switch(result) {
    case 1: return sum;
    case 2: return diff;
    case 3: return mult;
    case 4: return div;
  }
}

int main(void) {
  int (*ptr)(int, int) = ptrFn();
  printf("the result is: %d\n", ptr(3, 5));
  return 0;

} 
