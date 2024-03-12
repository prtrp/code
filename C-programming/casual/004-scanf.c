#include <stdio.h>

int sum(int a, int b);

int main() {
    int a, b;
    
    printf("Inserire due numeri da sommare: ");
    int x = scanf("%d %d %d", &a, &b);
    
    printf("Valori letti correttamente: %d\n", x);
    printf("La somma dei due numeri e: %d\n", sum(a, b));
    
    return 0;
}

int sum(int a, int b) {
    int result = a + b;
    return result;
}
