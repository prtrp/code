#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *fp = NULL;
  char str[50];

  fp = fopen("abc.txt", "w");
  if(fp == NULL) {
    printf("error\n");
    exit(1);
  }

  printf("enter the string\n>> ");
  fgets(str, sizeof(str), stdin);
  
  fputs(str, fp);
  fclose(fp);
}
