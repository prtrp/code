#include <stdio.h>
#include <string.h>

int main() {
  char src[10] = "123456789";
  char dest1[50];
  strcpy(dest1, src);
  printf("the string is: %s", dest1);
  
  return 0;
}
