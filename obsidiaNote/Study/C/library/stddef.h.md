this library defines various variable types and macros. Many of these definition also appear in other headers;

| variable  |                                    definition                                    |
| --------- | :------------------------------------------------------------------------------: |
| size_t    |    this is the unsigned integral type and is the result of the sizeof keyword    |
| ptrdiff_t | this is the unsigned integral type and is the result of two subtracting pointers |
| wchar_t   |              integer type of the size of a wide character constant               |
| NULL      |                           is the value of void pointer                           |
# Macro
## offsetof(type, member-designator)
is the offset in bytes of a structure member from the beginning of the structure. for type means the name of the struct. The offeset is the distance in byte between the start of structure and the member specified 
```C
#include <stdio.h>
#include <stddef.h>

typedef struct Example {
	int x;
	char y;
	int z;
} Example;

int main() {
	printf("offset of 'e' is %llu"\n, offset(Example, x));
	return 0;
}
```