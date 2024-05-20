#include <stdio.h>

int main() {

	// implicit type convertion - promotion

	float x = 50.0;

	prinf("%f", x); // printf take a double
	//x is PROMOTED - the value of x is stored as as a duoble 
	return 0;

}
/*
void prinf(char tacos[], double x) {

	
}
*/
