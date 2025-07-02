#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// dinamic list for buffer
typedef struct dymarr {
	size_t dsize;
	size_t dindx;
	char *darr;
} dymarr;

dymarr dnarr = {0, 0, NULL};

void apDarr(dymarr *strcDarr, const char *arr, size_t lenarr) {
	if (strcDarr->darr == NULL) {
		char *nwarr = NULL;
		nwarr = realloc(strcDarr->darr, sizeof(char)*2);
		if (nwarr == NULL) {
			perror("error with realloc");
			exit(1);
		}

		strcDarr->darr = nwarr;
		strcDarr->dsize += 2;
	}

	while(strcDarr->dsize <= lenarr+1) {
		strcDarr->dsize *= 2;
		char *nwarr = NULL;
		nwarr = realloc(strcDarr->darr, sizeof(char)*strcDarr->dsize);
		if (nwarr == NULL) {
			perror("error with realloc");
			exit(1);
		}
	}
	memcpy(&strcDarr->darr[strcDarr->dindx], arr, lenarr);
	strcDarr->dindx += lenarr;
	
}

void fullRec(size_t hight, size_t base, dymarr *strcDarr) {
	for(size_t rows = 0; rows < hight; rows++) {
		for(size_t cols = 0; cols < base; cols++) {
			// printf("(%d;%d)", rows, cols);
			if ((rows != 0 && rows != hight-1) && (cols != 0 && cols != base-1)) {
				apDarr(strcDarr, " ", 1);
			} else {
				if ((cols == 0 && rows == 0) || (cols == base-1 && rows == hight-1) ||
					(cols == 0 && rows == hight-1) || (cols == base-1 && rows == 0)) {
					apDarr(strcDarr, "+", 1);

				}else if (rows == 0 || rows == hight-1) {
					apDarr(strcDarr, "-", 1);
					
				}else {
					apDarr(strcDarr, "|", 1);
				}
			}
		}
		apDarr(strcDarr, "\n", 1);
	}
}

int main() {
	fullRec(30, 50, &dnarr);
	write(STDIN_FILENO, dnarr.darr, dnarr.dindx);
	return 0;
}
