#include <stdio.h>
#include <math.h>

int main() {
	double C1;
	double C2;
	double result;

	printf("please enter the C1: ");
	scanf("%lf", &C1);
	printf("please enter the C1: ");
	scanf("%lf", &C2);

	result = sqrt((C1*C1) + (C2*C2));
	printf("the hypotenuse is %lf\n", result);

	return 0; 
}
