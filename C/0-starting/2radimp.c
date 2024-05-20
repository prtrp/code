#include <stdio.h>
int main() {

	int radius;
	printf("please enter a value: ");
	scanf("%i", &radius); //address-of operator

	double area = 3.14159 * (radius * radius);
	printf("The area of a circle with %i radius is %f\n", radius, area);
	return 0;
}
