#include <stdio.h>
#include <string.h>
#include <stddef.h>

int find_short(const char *s) {
  int res = strlen(s);
  int buff = 0;


  for(int i = 0; i < strlen(s); i++) {
    if(s[i] != ' ') {
      buff++;
    }
    else if(res > buff) {
      res = buff;
      buff = 0;
    }
  }
  return res;
}

int main() {
  const char s[] = "ciao, io sono petru, questo solo";
  int len_short = find_short(s);
  printf("%d\n", len_short);
}
