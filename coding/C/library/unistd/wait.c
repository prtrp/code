#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
  int id = fork();
  int n;
  if (id == 0) {
    n = 1;
  }
  else {
    n = 6;
  }
  if(id != 0) {
    wait(NULL);
  }
  int i;
  for(i = n; i < n + 5; i++) {
    printf("%d ", i);
    // fflush(stdout) is used for empty the buffer standard out immediately.
    fflush(stdout);
  }
  if(id != 0) {
    printf("\n");
  }
  return 0;
}
