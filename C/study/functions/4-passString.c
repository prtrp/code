#include <stdio.h>

void display(char *);

int main() {
  char str[32] = "hi, my name is petru";
  display(str);
}

void display(char *str) {
  printf("%s\n", str);
}
