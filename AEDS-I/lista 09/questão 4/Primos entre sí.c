#include <stdio.h>

int main() {
    char continuar = 'S';

    while (continuar == 'S') {
        int num1, num2;

        // Leitura do primeiro número natural
        printf("Digite o primeiro número natural: ");
        if (scanf("%d", &num1) != 1 || num1 <= 0) {
            printf("Entrada inválida. Por favor, insira apenas números inteiros positivos.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        // Leitura do segundo número natural
        printf("Digite o segundo número natural: ");
        if (scanf("%d", &num2) != 1 || num2 <= 0) {
            printf("Entrada inválida. Por favor, insira apenas números inteiros positivos.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        // Verifica se os números são primos entre si
        int primo_entre_si = 1; // Assume inicialmente que são primos entre si
        int divisor = 2;
        while (divisor <= num1 && divisor <= num2) {
            if (num1 % divisor == 0 && num2 % divisor == 0) {
                primo_entre_si = 0; // Encontrou um divisor comum, não são primos entre si
                break; // Saímos do loop, pois já não são primos entre si
            }
            divisor++;
        }

        // Impressão do resultado
        if (primo_entre_si)
            printf("Os números são primos entre si.\n");
        else
            printf("Os números não são primos entre si.\n");

        // Pergunta ao usuário se deseja continuar
        printf("Deseja verificar outros números? (S/N): ");
        while (scanf(" %c", &continuar) != 1 || (continuar != 'S' && continuar != 'N')) {
            printf("Por favor, digite apenas 'S' para sim ou 'N' para não: ");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }

        // Limpa o buffer de entrada
        while (getchar() != '\n');
    }

    return 0;
}