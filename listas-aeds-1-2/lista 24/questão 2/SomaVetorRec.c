#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nSoma de valores de um vetor\n\n");
}

void lerTam(int* tamanho){

    printf("Digite quantos valores seu vetor irá possuir: ");
    scanf("%d", tamanho);
}

void lerArranjo(int tamanho, int vetor[tamanho]){
    
    for(int i = 0; i < tamanho; i++){
        printf("\nDigite o valor %d do seu vetor: ", i + 1);
        scanf("%d", &vetor[i]);

    }
}

int somArranjo(int tamanho, int vetor[tamanho]){

    return (tamanho <= 0) ? 0 : vetor[tamanho - 1] + somArranjo(tamanho - 1, vetor);

}


int main(){
    apresentacao();

    int tamanho;
    lerTam(&tamanho);

    int* vetor = (int *)malloc(tamanho * sizeof(int));

    lerArranjo(tamanho, vetor);

    int soma = somArranjo(tamanho, vetor);

    printf("\nA soma do seu vetor é: %d", soma);

    free(vetor);

    return 0;
}