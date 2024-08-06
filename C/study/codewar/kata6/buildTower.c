#include <stdio.h>

void build_tower(unsigned n, char tower[n][2*n-1]) {
  for(int i = 0; i <= n; i++) {
    unsigned num_sapces =
    for(int k = n -i; k > 0; k--){
      tower[i][k] = ' ';
    }
    for(int j = 0; j < 2*i-1; j++) {
      tower[i][j] = '*';
    }
    for(int k = n -i; k > 0; k--){
      tower[i][k] = ' ';
    }
  } 
}

void print_tower(unsigned n, char tower[n][2*n-1]) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < 2 * n - 1; j++) {
            printf("%c", tower[i][j]);
        }
        printf("\n");
    }
}

int main() {
    unsigned levels = 4;
    char tower[levels][2*levels-1];
    
    build_tower(levels, tower);
    print_tower(levels, tower);
    
    return 0;
}


