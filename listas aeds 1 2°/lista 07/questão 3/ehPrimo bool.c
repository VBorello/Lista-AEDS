#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int n) {
    if (n <= 1) {
        return false; // Números menores ou iguais a 1 não são primos
    }
    
    for (int i = 2; i * i <= n; i++) { //se i * i <= n; i++ e verifica se ŕ ou não divisível 
        if (n % i == 0) {              //verifica a raiz se i * i chegar a ficar igual a n sabemos que não é primo;
            return false; // Se for divisível por qualquer número além de 1 e ele mesmo, não é primo
        }
    }
    
    return true; // Se nenhum divisor foi encontrado, o número é primo
}

int main() {
    int numero;

    // Solicita ao usuário um número para verificar
    printf("Digite um numero: ");
    scanf("%d", &numero);

    // Verifica se o número é primo
    if (ehPrimo(numero)) {
        printf("%d eh um numero primo.\n", numero);
    } else {
        printf("%d nao eh um numero primo.\n", numero);
    }

    return 0;
}
