#include <stdio.h>

int main() {
  int arr2D[2][3] = {{1, 2, 3},{4, 5, 6}};
  printf("INSERT THE VALUE INSIDE THE 2D ARRAY\n");

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 3; j++) {
      scanf("%d", &arr2D[i][j]);
    }
  }
  
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d", arr2D[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
