#include <stdio.h>

int fn(int [], int);

int main()
{
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  printf("the sume of number is: %d", fn(arr, 10));
}


int fn(int a[], int b)
{
  int sum = 0, average = 0;

  for (int i = 0; i < b; i++) 
    sum = sum + a[i];

  average = sum / b;

  return average;
  
}
