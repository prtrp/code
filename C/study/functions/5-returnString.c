#include <stdio.h>

char* display();

int main() {
  char* str;
  str = display();
  printf("str %s\n", str);
}

char* display() {
  static char str[] = "petru";
  return str;
}
