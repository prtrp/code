#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file = fopen("readFile.txt", "r");
  if (file == NULL) {
    perror("Errore nell'apertura del file");
    return 1;
  }


  fclose(file);
  return 0;
}

