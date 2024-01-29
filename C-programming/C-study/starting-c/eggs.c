#include <stdio.h>

int main() {

	int eggs;
	printf("the numbers of eggs for day ");
	scanf("%i", &eggs);

	double dozen = (double) eggs / 12;

	printf("you have %f dozen eggs. \n", dozen);
	return 0;
}
