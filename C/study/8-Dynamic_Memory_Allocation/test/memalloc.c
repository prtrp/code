#include <stdio.h>
#include <stdlib.h>

void insert_value(int *cont_size, int **arr,int *arr_size, int position, int value);

int main(int argc, char* argv[]) {
  int cont_size = 10, position = 2, value = 8;
  int arr_size = 10;

  int *arr_num = malloc(10 * sizeof(int));
  if(arr_num == NULL) {
    printf("Array null\n");
    exit(1);
  }

  for(int i = 0; i < 10; i++) {
    arr_num[i] = i + 1;
  }


  for(int i = 0; i < cont_size; i++){
    printf("%d ", arr_num[i]);
  }
  printf("\n");

  insert_value(&cont_size, &arr_num, &arr_size, position, value);
  insert_value(&cont_size, &arr_num, &arr_size, 3, 4);
  insert_value(&cont_size, &arr_num, &arr_size, 8, 2);

  /*
  printf("Insert the position and the value\n>> ");
  scanf("%d %d", &position, &value);
  */
  
  for(int i = 0; i < cont_size; i++){
    printf("%d ", arr_num[i]);
  }
  printf("\n");
  free(arr_num);
  return 0;
}

void insert_value(int *cont_size, int **arr, int *arr_size, int position, int value) {
  if(*cont_size >= *arr_size){
    int new_size = (*arr_size) + 1;
    int *new_arr = realloc(*arr, new_size * sizeof(int));
    if(new_arr == NULL) {
      printf("Array null 2\n");
      exit(1);
    }
    *arr = new_arr;
    *arr_size = new_size;
  }

  
  for(int i = (*cont_size) -1; i >= position -1; i--) {
    (*arr)[i+1] = (*arr)[i];
  }
  (*arr)[position-1] = value; 
  (*cont_size) += 1;
}
