#include <stdio.h>

void initialization(void);
void avrg(void);

int main(){
  avrg();
}


void initialization(void)
{
  //-compile time initialization
  int arr[5] = {1,2,3,4,5};
  int arr2[] = {0,1,2,3,4,5,6,7,8,9,10};

  //-run time intialization
  int arr3[64];

  for(int i = 0; i < 64; i++)
  {
    if(i < 32) {
      arr3[i] = 0;
    }

    else 
    {
      arr3[i] = 1;
    }

  }


 for(int i = 0; i < 64; i++)
   printf("%d ", arr3[i]);
}

void avrg(void)
{
  int marks[5];
  float sum = 0, avg;
  
  for(int i = 0; i < 5; i++)
    scanf("%d", &marks[i]);

  for(int i = 0; i < 5; i++)
    sum = sum + marks[i];
  
  avg = sum / 5;
  printf("%f\n", avg);
  
}


