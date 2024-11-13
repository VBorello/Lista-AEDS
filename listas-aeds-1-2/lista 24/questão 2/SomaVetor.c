#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nSoma de valores de um vetor\n\n");
}

int lerTam(){
    int tamanho = 0;

    printf("Digite quantos valores seu vetor irá possuir: ");
    scanf("%d", &tamanho);

    return tamanho;
}

int somArranjo(){
    int tam;

    tam = lerTam();
    int* vetor = (int *)malloc(tam * sizeof(int));
    int soma = 0;

    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor %d do seu vetor: ", i + 1);
        scanf("%d", &vetor[i]);

    }

    for(int i = 0; i < tam; i++){
        soma += vetor[i];
    }

    return soma;
}


int main(){
    apresentacao();

    int soma = somArranjo();

    printf("\nA soma do seu vetor é: %d", soma);

    return 0;
}