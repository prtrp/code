#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char nstr[] = "hello guys";
	int szstr = strlen(nstr);

	for(int i = 0; i <= szstr; i++) {
		printf("%d('%c') ", nstr[i], nstr[i]); 
	}
	printf("\n");
	//printf("%s\n%d\n", nstr, szstr);

	char *nwstr = malloc(sizeof(char)*(szstr + 1));
	int szNwstr = strlen(nwstr);

	for(int i = 0; i <= szNwstr; i++) {
		nwstr[i] = 66;
	}

	memcpy(nwstr, nstr, szstr);
	for(int i = 0; i <= szNwstr; i++) {
		printf("%d('%c') ", nwstr[i], nwstr[i]); 
	}
	printf("\n"); 

	return 0;
}
