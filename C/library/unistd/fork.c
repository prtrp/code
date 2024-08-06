#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void) {
  fork();
  printf("hello world\n");
  return 0;
}
