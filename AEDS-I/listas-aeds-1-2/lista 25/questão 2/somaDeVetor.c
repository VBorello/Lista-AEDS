#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nSoma de valores de um vetor\n\n");
}

int tam(){
    int tam;
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &tam);
    return tam;


}

void lerVetor(int tam, int vetor[tam]){
    
    for(int i = 0; i < tam; i++){
        printf("\nDifite o valor %d do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

}

int somarVetor(int tam, int vetor[tam]){

    int soma = 0;
    for(int i = 0; i < tam; i++){
        soma += vetor[i];
    }

    return soma;
    
}

int main(){
    apresentacao();
    
    int tamanho = tam();

    int* vetor = (int *)malloc(tamanho * sizeof(int));

    lerVetor(tamanho, vetor);

    int soma = somarVetor(tamanho, vetor);

    printf("\nA soma dos valores do vetor deu: %d", soma);

    return 0;
    free(vetor);
}