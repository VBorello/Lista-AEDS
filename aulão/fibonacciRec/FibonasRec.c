#include <stdio.h>

int fibonacci(int n) {
    if (n == 0){
        return 0;  // Caso base: F(0) = 0
    }
    else if (n == 1){
        return 1;  // Caso base: F(1) = 1
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);  
    }
}

void printFiboTermos(int n) {
    for (int i = 0; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;

    printf("Digite a quantidade de termos da sequência: ");
    scanf("%d", &n);

    printf("%d\n", n);
    printFiboTermos(n);

    return 0;
}
