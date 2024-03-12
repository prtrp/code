#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *ptr = NULL;
  char str[32];

  ptr = fopen("abc.txt", "a");
  if(ptr == NULL)
  {
    printf("error");
    exit(1);
  }

  printf("Enter your name, no more than 32 characters:\n>> ");
  scanf("%31s", str); // Leggi fino a 31 caratteri per evitare buffer overflow

  fprintf(ptr, "%s", str);
  printf("Successfully appended\n");

  fclose(ptr);

  return 0;
}

