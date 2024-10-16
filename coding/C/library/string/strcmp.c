#include <stdio.h>
#include <string.h>

int main() {
  char s1[] = "This is the way";
  char s2[] = "This is the way";
  
  if(strcmp(s1, s2) == 0) {
    printf("this strings are the same\n");
  }
  return 0;
}
