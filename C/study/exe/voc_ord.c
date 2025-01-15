#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* sort_by_vocals(char *a);
int compare (char ltr);


int main() {
    char a[] = ".pr0grAmMaz1onE-C*"; 
    char *b = sort_by_vocals(a);
    for(int i = 0; i < strlen(b); i++) {
        printf("%c ", b[i]);
    }
    printf("\n");
    return 0;
}

char* sort_by_vocals(char *a) {
    int i, j = 0;
    char *darr = NULL;


    for( i = 0; i < (strlen(a)-i-1); i++ ) {
        int size = 0;
        if(compare(a[i])) {
            darr = (darr == NULL) ? malloc(sizeof(char)*(size += 2)) : realloc(darr, sizeof(char)*(size *= 2));
            darr[j] = a[i];
            j++;
        }
    }
    return darr;
}


int compare (char ltr) {
    char a[] = "aeiouAEIOU";
    int i;
    for(i = 0; i < strlen(a); i++) {
        if(ltr == a[i]) {
            return 1;
        }
    } 
    return 0;
}
