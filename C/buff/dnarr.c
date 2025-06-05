#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//----define
#define INIT_DARR {NULL, 0}

//-----data
typedef struct darr {
	char *dastr;
	int dalen;
} darr;


//----fn declaration
void apDarr(darr *darr, const char *apstr, int aplen);
void die(const char *dstr);


//----start main
int main() {
	darr darr = INIT_DARR;
	char str[] = "hello guys ";
	int szstr = strlen(str);
	printf("%x\n", darr.dastr);
	
	apDarr(&darr, str, szstr); 
	printf("%s\n", darr.dastr);

	char str2[] = "hello form another one";
	int szstr2 = strlen(str2);
	apDarr(&darr, str2, szstr2); 
	printf("%s\n", darr.dastr);
	

	return 0;
}

//----fn initializzation
void apDarr(darr *darr, const char *apstr, int aplen) {
	// reallocation and testo of input array
	char *nwstr = NULL;
	nwstr = realloc(darr->dastr, sizeof(char)*(darr->dalen + aplen));
	if(nwstr == NULL) {
		die("error with realloc");
	}

	memcpy(&nwstr[darr->dalen], apstr, aplen);
	darr->dastr = nwstr;
	darr->dalen += aplen;

}

void die(const char *dstr) {
	perror(dstr);
	exit(1);
}
