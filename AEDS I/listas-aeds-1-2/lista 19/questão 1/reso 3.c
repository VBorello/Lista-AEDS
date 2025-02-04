#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    printf("\nPeso Ideal sem uso de vetor, apenas com alocação dinâmica\n\n");
}

void lerQuantidade(int* quantidade) {
    printf("Digite a quantidade de pessoas: ");
    scanf("%d", quantidade);
}

void lerDadosPessoa(float* altura, char* genero) {
    printf("Digite a altura (em metros, ex: 1.75): ");
    scanf("%f", altura);
    
    printf("Digite o genero (M/F): ");
    scanf(" %c", genero); 
}

float calcularPesoIdeal(float altura, char genero) {
    if (genero == 'F' || genero == 'f') {
        return (62.1 * altura) - 44.7;
    } else if (genero == 'M' || genero == 'm') {
        return (72.2 * altura) - 58;
    } else {
        printf("Genero invalido Considerando genero masculino.\n");
        return (72.2 * altura) - 58;  
    }
}

int main() {
    apresentacao();

    int* quantidade = (int*) malloc(sizeof(int));
    lerQuantidade(quantidade);

    for (int i = 0; i < *quantidade; i++) {
        printf("\nPessoa %d\n", i + 1);

        float* altura = (float*) malloc(sizeof(float));
        char* genero = (char*) malloc(sizeof(char));

        lerDadosPessoa(altura, genero);

        float pesoIdeal = calcularPesoIdeal(*altura, *genero);
        printf("O peso ideal da pessoa %d é: %.2f kg\n", i + 1, pesoIdeal);

        free(altura);
        free(genero);
    }

    free(quantidade);

    return 0;
}
