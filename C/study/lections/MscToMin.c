#include <stdio.h>

int main() {
  char buff = 'R';
  char minusc;
  if (buff >= 'A' && buff <= 'Z') {
    char k = 'a' - 'A';
    minusc = buff + k;
    printf("%c\n", minusc);
  }

}
