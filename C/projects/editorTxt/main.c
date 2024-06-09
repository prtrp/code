#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 1024

char *FileName();
char *read_file(const char *fileName);

//----------------
int main() {
  const char *fName = "example.txt"; 
  FILE *fptr = NULL;
  fptr = fopen(fName, "r+");
  char c;

  if(fptr == NULL) {
    fptr = fopen(fName, "w+"); 
    
    while((c = fgetc(stdin)) != EOF) {
      fputc(c, fptr);
    }
    fclose(fptr);
  }
  fclose(fptr);

  char *buffer = read_file(fName);
  
  return 0;
}

//----------------
char *FileName() {
  static char Name[128];
  printf("insert the name about the file to open or create, max 127 words\n");
  scanf("%s", Name);
  return Name;
}

//----------------
char *read_file(const char *fileName) {
  FILE *file = fopen(fileName, "r");
  if(file == NULL) {
    fclose(file);
    return NULL;
  }

  char *buffer = (char*)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
  if(file == NULL) {
    fclose(file);
    return NULL;
  }
  size_t buffer_size = INITIAL_BUFFER_SIZE;
  size_t content_size = 0;
  int c;

  while((c = fgetc(file)) != EOF) {
    buffer[content_size++] = (char)c;
    if(content_size == buffer_size) {
      buffer_size *= 2;
      buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
      if (buffer == NULL) {
        free(buffer);
        fclose(file);
        return NULL;
      }
    }
  }

  buffer[content_size] = '\0';
  fclose(file);
  return buffer;
}

