#include <stdio.h>

int main() {
	printf("\xE2\x96\x88 \xE2\x96\x91 \xE2\x96\x92 %c\n", 66);
	#include <stdio.h>

	// Posiziona il cursore (riga 5, colonna 10)
	printf("\033[5;10H");
	// Colore rosso (31), sfondo nero (40)
	printf("\033[31;40m");
	printf("Benvenuto!");
	return 0;
}
