# what is
stands for standard symbolic constants and types, give access to the API POSIX (Portable Operating System Interface). Allow us to interact with the low level OS.
## fork()
is like forking a execution line, a child process born and start executing the following lines. The child process is always be 0. the process IS of the new process is the old process. 0 -> child process, != 0 -> process dad.
```C
int main(void) {
  int id = fork();
  id == 0 ? printf("hello form child\n") : printf("hello from main\n");
  return 0;
}
```

if we call 2 times fork() it will do the last process * 2, so 2^n
```C
int main(void) {
  fork();
  fork();
  printf("hello world\n");
  return 0;
}
```
for prevent it we can check if the id is 0; if it is we don' t call it.
```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int id =  fork();
  if(id != 0) {
    fork();
  }
  printf("hello Work");
  return 0;
}
```
## wait()
say stop the execution until the child process finish his process.
```C
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
```
