#include <stdio.h>

/* 

it is an application of pointer functions; it means

int sum(){}

int sub(){}

void display()
{
--> there we wont to display the result of the sub or sum function; so we have to pass a functon to another function
--> so we have to pass the memory address of functions for display this
}

*/

//int sum(int, int);
//int sub(int , int);

//void display(int(*ptr)(int, int));

int sum(int a, int b)
{
  return a + b;
}

int sub(int a, int b)
{
  return a - b;
}

void display(int(*ptr)(int, int))
// |   |      |          | 
// |   |      |        the data type of arguments inside the call back funciton 
// |   |      | 
// |   |    what value exit form the call back function 
// |   |
// |   name of this function
// |
// what is the data type of this function
{
  printf("%d\n", (*ptr)(5, 1));
}

int main()
{
  display(sum);
  // call the function with in the function that we want to call;
}

