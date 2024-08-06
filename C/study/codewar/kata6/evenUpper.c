#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *to_weird_case(char *string) 
{
  int arrLen = strlen(string);
  int status, index = 0;


  for(int i = 0; i < arrLen; i++)
  {
    if(string[i] != ' ') {
      status = IN;

      if(index %2 == 0) {
        string[i] = toupper(string[i]);
        index++;
      }
      else {
        string[i] = tolower(string[i]);
        index++;
      }
    }
    else {
      index = 0;
    }
  }
  return string;
}

int main()
{
  char str[] = "weird string case";
  printf("%s\n", to_weird_case(str));
  return 0;
}
