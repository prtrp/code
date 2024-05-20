#include <stdio.h>

int main() {

	char i = 10;

	switch (i)
	{
	case 5: case 6: case 7: case 8: case 9: case 10:
		printf("the number is: %d", i);
		break;
	
		case 11:
			printf("the number is: %c", i);
	default:
		break;
	}	
}