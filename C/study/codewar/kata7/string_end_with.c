#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool solution(const char* string, const char* ending);

int main() {
  char string[] = "abcdefg";
  char ending[] = "ef";
  

  if(solution(string, ending)) {
    printf("end with this string");
  }
  else{
    printf("dont end with this string");
  }

  return 0;
}

bool solution(const char *string, const char *ending)
{
  int size_string = strlen(string);
  int size_ending = strlen(ending);

  printf("size compare is: %d\n", size_string);
  printf("size ending is: %d\n", size_ending);
  
  for(int i = 0; i < size_ending ; i++) {
    if(string[size_string - size_ending + i] != ending[i]) {
      return false;
    }
  }
  return true;
}
