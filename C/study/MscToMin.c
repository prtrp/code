#include <stdio.h>

char maiuscToMin(char a) {
  if( a >= 'A' && a <= 'Z') {
    int c = a - 'A';
    return 'a'+ c;
  }
  return -1;
}

int main() {
  char a = 'R';
  printf("%c, hellow\n", maiuscToMin(a));
  return 1;
}
