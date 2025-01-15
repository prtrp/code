#include <stdio.h>


int rec_sum(int num) ;


int main() {
    printf("%d\n", rec_sum(10));
}


int rec_sum(int num) {
    if(num == 0) {
        return 0;
    }
    else {
        return num + rec_sum(num-1); 
    }
}
