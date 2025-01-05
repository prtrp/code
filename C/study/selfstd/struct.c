#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* maticola;
    int* grades;
    char *subject;
} student;

struct car {
    float heaight;
    int num;
    char *model;
};

int main() {
    struct car toyota;
    toyota.model = "supra";
    char* model = "viper";

    printf("%s ", model);
    printf("%s ", toyota.model);
}
