#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "una stringa";
    // psazio per tutti i carateri ed anche \0
	printf("%s\n", a);

	printf("%lu\n", sizeof(a));
	a[3] = '\0';
	printf("%s\n", a);
    printf("%s = %lu\n", a, strlen(a));
}
