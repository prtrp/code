#include <stdio.h>
#include <stdlib.h>

int main()
{
  char ch;
  FILE *pf = NULL;
  pf = fopen("abc.txt", "r");
  
  if(pf == NULL)
  {
    printf("error with file\n");
    exit(1);
  }

  while(!feof(pf))
  {
    ch = fgetc(pf);
    printf("%c", ch);
  }

}
