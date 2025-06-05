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

struct gameConfig {
	int sx, sy;
	int screenrows;
	int screencols;
	struct termios orig_termios;
};

struct gameConfig gc;
dnarr buffGame = {0, 0, NULL};

void disableGameMod() {
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &gc.orig_termios) == -1) {
		perror("ERROR WITH tcsetattr");
		exit(1);
	}
}

void enableGameMod() {
	if (tcgetattr(STDIN_FILENO, &gc.orig_termios) == -1) {
		perror("Error with tcgetattr");
		exit(1);
	}
	atexit(disableGameMod);

	struct termios raw = gc.orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | IXON | ISTRIP);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag &= ~(CS8);

	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
		perror("ERROR WITH tcsetattr");
		exit(1);
	}
}

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
	enableGameMod();
	char c = getchar();

	return 0;
}
