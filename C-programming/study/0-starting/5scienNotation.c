#include <stdio.h>

int main(){
	printf("insert the number of dogs: ");
	double dogs = 2.5e4;
	scanf("%lf", &dogs);
	printf("%f\n%e\n%g\n", dogs, dogs, dogs);

	return 0;
}
