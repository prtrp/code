#include <stdio.h>
#include <stdbool.h>

int main()
{

  int i;
  char text[24];
  bool contain_space = false;
  FILE *ptr = fopen("firstFile.txt", "w");

  printf("insert what do you want to write inside the file\n");
  for(i = 0; i < 23; i++)
    scanf("%c", &text[i]); 
  
  for(i = 0; i < 23; i++)
    if(text[i] == ' ')
    {
      contain_space = true;
    }

  if(contain_space == true)
  {
    printf("error, you cannot put spaces\n");
    return -1;
  }

  for(int i = 0; i < 23; i++)
  {
    fputc(text[i], ptr);
  }

}
