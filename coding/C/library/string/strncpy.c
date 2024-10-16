#include <stdio.h>
#include <string.h>

int main() {
  char src[10] = "123456789";
  char dest2[50];

  strncpy(dest2, src, 10);
  printf("dest2 is: %s", dest2);
  return 0;
}
