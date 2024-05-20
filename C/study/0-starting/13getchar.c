#include <stdio.h>

int main() {

	printf("Choose a menu option 1-4:\n");
	printf("1. add a ptient\n");
	printf("2. view a ptient\n");
	printf("3. search a ptient\n");
	printf("4. exit\n");

	int input;
	scanf("%d", &input);
	
	if(input == 1) {
		printf("adding a patient\n");

	}else if (input == 2) {
		printf("adding a patient\n");

	}else if (input == 3) {
		printf("search a patient\n");

	}else if (input == 4) {
		printf("exiting...");
		printf("do you want to save? y/n ");
		char q;
		
		getchar(); // for do not let scanf give \n
		scanf("%c", &q);

		if(q == 'Y' || q == 'y') {
				printf("saving changes!\n");

		}else if(q == 'N' || q == 'n') {
				printf("fine wathever\n");
		
		}else {
			printf("do not try to hack me lol\n");

		}

	}
	return 0;
}
