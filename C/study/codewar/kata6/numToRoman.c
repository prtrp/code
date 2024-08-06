#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(int n) {
  char *result = (char *)calloc(16, sizeof(char));
  char buff[16] = {0};
  sprintf(result, "%d", n);
  int len = strlen(result);

  
  
}

int main() {
  printf("%s\n", solution(83));
  return 0;
}
