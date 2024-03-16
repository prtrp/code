#include <stdio.h>

int main()
{
  int i, k;
  int array[6];
  
  for(int j = 0; j < 6; j ++)
    scanf("%d", &array[j]);
    
  for(int j = 0; j < 6; j ++)
    printf("%d ", array[j]);

  printf("\n");

  for (i = 0; i < 6 ; i++)
  {
    for(k = i+1; k < 6; k++)
    {
      printf("array[%d] = array[%d]\n", array[i], array[k]);
      if(array[i] == array[k])
      {
        printf("\n-----------------------------\nwe have the same number\n");
        return 0;
      }
    }
    printf("\n");
    k+=1;
  }
  printf("\n-----------------------------\nwi do not have the same number\n");
  return 0;
}

    


  

