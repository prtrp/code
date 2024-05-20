#include <stdio.h>
#include <stdlib.h>

 int main()
{
  FILE *fp;
  fp = fopen("frasi_impiccato.txti", "a");
  fprintf(fp, "hello, i am petru");
  return 0;

}

