## static memory
memory allocated during compile time is called static memory; cannot change the memory during run time.
## dynamic memory
1. Allocating memory during the time of executing.

2. heap is the segment of memory where dynamic memory allocation takes place. Unlike stacks, heap is an area where memory is allocated or deallocated without any order (randomly).

|       heap        |         free store of memory          |
|:-----------------:|:-------------------------------------:|
|                   |                                       |
|       stack       |    function calls local varaibles     |
|   static/global   | the variable that have hole life time |
| text/code segment |   store the instruction to execute    |
### example of execution
```C
#include <stdio.h>
int total;

int square(int x) {
	return x*x;
}

int squareOfSum(int x, int y) {
	int z = Square(x + y);
	return z;
}

int main() {
	int a = 4, b = 8;
	int total = squareOfSum(a, b);
	printf("output = %d", total);
}
```
### representation of code:

| stack         |                     |
| ------------- | ------------------- |
|               |                     |
| square(): x   | first executing     |
| sos(): x,y.z  | after this one      |
| main():  a, b | and finish this one |
|               |                     |
| global: Total |                     |

1. when the program is starting executing the main function is invoked, after store the global variable, main -> stack-frame, the size of stack-frame is calculated in compiling. The function at the top of the stack is executing and other is like paused. Use global variable only if you need in multiple places.

2. Heap is the pool for memory, have nothing to do with heap data structure. 
### functions
malloc() -> is used of add memory form the heap.
```C
int main() {
  int a;
  int *p;
  p = (int*)malloc(sizeof(int));
  *p = 10;
  free(p);
  p = (int*)malloc(sizeof(int));
  *p = 20; 
}
```
