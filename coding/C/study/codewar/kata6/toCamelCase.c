#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* to_camel_case(const char *text, char *camel) {
    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        if (text[i] == '-' || text[i] == '_') {
            i++;
            if (text[i] != '\0') {
                camel[j] = toupper(text[i]);
                i++;
                j++;
            }
        } else {
            camel[j] = text[i];
            i++;
            j++;
        }
    }
    camel[j] = '\0';  // Termina correttamente la stringa
    return camel;
}

int main() {
    const char str[] = "hello_i_am_petru_and_it_is_good";
    char camel[50]; // Assicurati che l'array sia abbastanza grande
    printf("%s\n", to_camel_case(str, camel));
    return 0;
}
