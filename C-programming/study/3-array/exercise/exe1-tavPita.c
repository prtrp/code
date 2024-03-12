#include <stdio.h>

int main()
{
  int pita[10][10];

  for(int i = 1; i < 11; i++)
  {
    for(int j = 1; j < 11; j++)
    {
      pita[i-1][j-1] = i*j;
      printf("%d\t", pita[i-1][j-1]);
    }
    printf("\n");
  }
}

