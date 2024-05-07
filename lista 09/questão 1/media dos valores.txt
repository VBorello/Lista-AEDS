#include <stdio.h>

int main() {
    int numero;
    int soma = 0;
    int contador = 0;
    int flag = 1; 

    printf("Digite os números inteiros (digite 0 para encerrar):\n");

    while (flag) {
        scanf("%d", &numero);

        if (numero == 0) {
            flag = 0;
        } else {
            soma += numero;
            contador++;
        }
    }

    if (contador > 0) {
        double media = (double) soma / contador;
        printf("A média dos valores lidos é: %.2f\n", media);
    } else {
        printf("Nenhum número diferente de zero foi digitado.\n");
    }

    return 0;
}