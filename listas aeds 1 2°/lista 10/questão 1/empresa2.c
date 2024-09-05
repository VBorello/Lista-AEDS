#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nReajuste nos preços de produtos do mercado\n\n");

    int mercadorias;
    printf("Digite a quantidade de mercadorias: ");
    scanf("%d", &mercadorias);

    int preço, maior = 0, menor = 100000;
    int preçoMaior = 0, preçoMenor = 0;

    for (int i = 0; i < mercadorias; i++) {
        printf("Digite o valor da mercadoria %d: ", i + 1);
        scanf("%d", &preço);

        if (preço < 2000 && preço > maior) {
            maior = preço;
            preçoMaior = preço;
        }

        if (preço > 2000 && preço < menor) {
            menor = preço;
            preçoMenor = preço;
        }
    }

    if (preçoMaior != 0) {
        printf("\nA mercadoria com o maior valor abaixo de 2000$ é: %d", preçoMaior);
    } else {
        printf("\nNenhuma mercadoria tem valor abaixo de 2000$.");
    }

    if (preçoMenor != 0) {
        printf("\nA mercadoria com o menor valor acima de 2000$ é: %d", preçoMenor);
    } else {
        printf("\nNenhuma mercadoria tem valor acima de 2000$.");
    }

    printf("\n");

    return 0;
}
