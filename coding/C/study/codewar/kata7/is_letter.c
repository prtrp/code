#include <stdio.h>

int is_it_letter(char c) {
  return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ? 1 : 0; 
}

int main() {
  is_it_letter('?') ? printf("is a letter\n") : printf("is not a letter\n");
  return 0;
}
