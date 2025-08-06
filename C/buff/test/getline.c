#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp = fopen("file.txt", "r");
	if (!fp) {
		perror("Errore apertura file");
		exit(1);
	}


	char *buff = NULL;
	size_t capacity = 0;
	ssize_t num_chars;

	while((num_chars = getline(&buff, &capacity, fp)) != EOF) {

		if (num_chars == -1) {
			printf("hessuna riga letta\n");
		}
		else {
			printf("%zd, %zu\n", num_chars, capacity);
			printf("conenuto: %s", buff);

		}
	}

	free(buff);
	fclose(fp);
	return 0;

}
