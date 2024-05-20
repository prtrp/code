#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int maxValue = 50;	
	srand(time(NULL));
	int randomNumber = rand() % maxValue + 1;

	printf("%d\n", randomNumber);

	printf("Guess a number 0-%d: ",  maxValue);
	int input;
	scanf("%d", &input);

	if(input == randomNumber) {
		printf("you win!\n");
	
	}else {
		printf("You don't win! Try again!\n");
	}
	return 0;	
}
