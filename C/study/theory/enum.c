#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef enum color {
  red = 10, // can only have integers 
  blue, // if you dont sepcipy any number, will add 1 to previous memeber
  yellow = 20 
} color;

int main(void) { 
  color c = red;
  printf("%d\n", c);
  return 0;
}
