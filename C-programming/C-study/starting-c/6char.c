#include <stdio.h>

int main() {

	char ascii; // char with only ''
	printf("please enter a character: ");
	scanf("%c", &ascii);
	printf("%i\n", ascii);

	int integer;
	printf("Please enter a number between 0 and 127: ");
	scanf("%d", &integer);
	printf("%c\n", integer);
	
	// math with ascii:
	char mathz = 'A' + '\t';
	printf("A(65) + \\t(11) = %c(%d)\n", mathz, mathz);
	return 0;
}
