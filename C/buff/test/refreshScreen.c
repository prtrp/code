#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

typedef struct dnarr {
	size_t dlen;
	size_t dindx;
	char *darr;
} dnarr;

dnarr darr = {0, 0, NULL};

void apDnarr(dnarr *arr, const char* inStr, size_t szArr) {
	if(arr->dlen <= 0) {
		arr->dlen = 2;
		arr->darr = malloc(sizeof(char)*(arr->dlen));
	}

	if(arr->darr == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(1);
	}

	while((arr->dlen - arr->dindx) < szArr) {
		arr->dlen *= 2;
		char *tmp = NULL;
		tmp = realloc(arr->darr, sizeof(char)*(arr->dlen));
		if(tmp == NULL) {
			fprintf(stderr, "Memory reallocation error\n");
			free(arr->darr);
			exit(1);
		}
		arr->darr = tmp;
	}
	memcpy(&arr->darr[arr->dindx], inStr, szArr);
	arr->dindx += szArr;
}

int main() {
	char *str = "hello from the first message";
	apDnarr(&darr, str, 28); 
	printf("%s\ndlen = %d\ndindx = %d\n", darr.darr, darr.dlen, darr.dindx);

	char *str2 = "hello from the first message";
	apDnarr(&darr, str2, 28); 
	printf("%s\ndlen = %d\ndindx = %d\n", darr.darr, darr.dlen, darr.dindx);

	return 0;
}
