#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long square_digits(unsigned n);

int main() {
  printf("%llu\n", square_digits(3210987654u));
  return 0;
}

unsigned long long square_digits(unsigned n) {
  char result[200] = {0};
  char str_buff[20]; // i create a buffer for the result and sett all to 0 at the start;

  char numStr[30];
  sprintf(numStr,"%u", n); // i convert the number in a string;

  for(int i = 0; i < strlen(numStr); i++) {
    int num_buff = numStr[i] - '0';
    num_buff = num_buff * num_buff;
    
    sprintf(str_buff, "%d", num_buff);
    strcat(result, str_buff);
    
  }
    unsigned long long int_result = strtoull(result, NULL, 10);
    return int_result;
}
