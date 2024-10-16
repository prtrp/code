#include <stdio.h>

void insertArr(void); 

int main() {
  insertArr(); 
  return 0;
}

void insertArr(void) {
  int arrNum[10] = {1, 2, 3, 4, 5};
  int contSize = 5;
  int num, position;

  printf("INSERT NUM TO INSERT AND POSITION\n>> ");
  scanf("%d%d", &num, &position);

  for(int i = 0; i < contSize; i++)
    printf("%d ", arrNum[i]);
  printf("\n");
  
  for(int i = contSize-1; i >= position - 1; i--) {
    arrNum[i+1] = arrNum[i]; 
  }
  arrNum[position-1] = num;

  for(int i = 0; i < contSize; i++)
    printf("%d ", arrNum[i]);
  printf("\n");
}

void delArr(void) {
  int arrNum[10] = {1, 2, 3, 4, 5};
  int position, contSize = 5;
  printf("ENTER THE POSITION TO DELETE%d");
  scanf("%d", &position);
  
  for(int i = 0; i < contSize; i++)
      printf("%d ", arrNum[i]);
  printf("\n");

  for(int i = position-1; i < contSize; i++) {
      arrNum[i] = arrNum[i+1];
  }

  for(int i = 0; i < contSize; i++)
      printf("%d ", arrNum[i]);
  printf("\n");
}

