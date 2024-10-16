#include <stdio.h>

int get_sum(int a, int b) {

  int result = 0;
  int start, end;

  if(a < b) {
    start = a;
    end = b;
  }
  else {
    start = b;
    end = a;
  }

  while(start <= end) {
    result += start;
    start++;
  }
  return result;
}

int main() {
  printf("%d\n", get_sum(505, 4));
  return 0;
}
