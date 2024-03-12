#include <stdio.h>

int main() {

	int slices = 3;
	
	switch(slices) {

		case 1:
			printf("you did a great jobi\n");
			break;
		case 2:
			printf("you did an ok job\n");
			break;
		case 3:
			printf("you did a bad job, try ti eat 2 nex time\n");
			break;
		case 4:
			printf("you're a dissapointment\n");
			break;
		default:
			printf("enjoy your heart disease\n");
			break;
			
	}
	
	return 0;
}
