#include <stdio.h>
#include <stdlib.h>

FILE *createFile(const char *name_File)
{
  FILE *fptr = NULL;
  fptr = fopen(name_File, "w");

  if(fptr == NULL)
  {
    printf("error with pointer\n");
    exit(1);
  }
  else
  {
    printf("file successfully.\n");
    fclose(fptr);
  }
  

  return fptr;
}

int main(int argc, char *argv[])
{
  if (argc != 2) // Check if exactly one argument is provided
  {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1; // Return error code
  }
  FILE *fptr = createFile(argv[1]);
  fopen(argv[1], "a");
  fputs("string", fptr);
  return 0;
  fclose(fptr);
}
