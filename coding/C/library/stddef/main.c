#include <stdio.h>
#include <stddef.h>

typedef struct Example {
  int x;
  char y;
  int z;
} Example;

int main() {
  printf("the size between the member and the start of structure is: %llu", offsetof(Example, z));
}
