is a header file that contains functions for manipulating strings (array or character).
# strlen()
`size_t strlen(const char* str)` -> it is the declaration of function
is used for calculate the size of a giving string. It don't count the `\0` character. 

```C
#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "It is a normal string";
  int length = strlen(str);
  printf("The string str is big %d char\n", length); 
}
```

`>> The string str is big 21 char`
# strcpy()
`char *strcpy(char *dest, const char *src)`
copies a string from one location to another. The function takes 2 arguments: a destination buffer (copied string will be stored) and a source, that will be copied. copy the entire source string, including the null terminator, into the destination buffer.
```C
#include <stdio.h>
#include <string.h>

int main() {
  char src[10] = "123456789";
  char dest1[50];
  strcpy(dest1, src);
  printf("the string is: %s", dest1);
  
  return 0;
}
```

but if the destination array is not enough big, the program will crush.
For this reason is better use:
# strncpy()
`char *strncpy(char *dest, const char *src, size_t n);`
is like strcpy, but can chose how many elements copy. Better to use when you want to control the number of characters 
```C
#include <stdio.h>
#include <string.h>

int main() {
  char src[10] = "123456789";
  char dest2[50];

strncpy(dest2, src, 10);
  printf("dest2 is: %s", dest2);
  return 0;
}
```
# strcmp()
`int strcmp(const char *str1, const char *str2);`
If we have 2 string like:
```C
char str[] = {"1, 2, 3, 4, 5"};
char str2[] ={"1, 2, 3, 4, 5"};
```
we cannot do `if(str == str2)` because ti will compare the memory allocation value, not the elements inside; for this reason we have to use this function(), it convert the string in a binary value, after that compare the binary value
```C
int main() {
  char s1[] = "this is an array";
  char s2[] = "this is an array";

  if(strcmp(s1, s2))
}
```
if lower ascii value in s1 than s2 will give value < 0
if the string are equal will give value 0
if is bigger ascii value in s1 than s2 will give value > 0

