#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    printf("come ti chiami? ");
    scanf("%s", name);

    if (strcmp(name, "giorgia") == 0 || strcmp(name, "Giorgia") == 0 || strcmp(name, "GIORGIA") == 0)
    {
        for(int i = 0; i < 3000; i ++)
        {
            printf("ti voglio bene, <3 <3 <3 <3 ");
        }
    } else{
        printf("vai via >:( \n");
    }
    return 0;
}
