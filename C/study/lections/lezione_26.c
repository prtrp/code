#include <stdio.h>

char srcType(char *b);

int main() {
    float f;
    printf("insert a float: ");
    int tmp = scanf("%f", &f);

    if(tmp == 1) {
        printf("%f\n", f);
    }
    else {
        printf("formato errato\n");
    }
}

char srcType(char *b) {
    int i = 0, npoint = 0;

    while(b[i] != '\0') {
        if(b[i] == '0') {
            if(npoint > 0) {
                return 's';
            }
            else {
                npoint++;
            }
        }
        else if (b[i] < '0' || b[i] > '9') {
            return 's';
        }
        else {
            i++;
        }
    }
    if (npoint == 0) {
        return 'i';
    }
    else {
        return 'f';
    }
}
