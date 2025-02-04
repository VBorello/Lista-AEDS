#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nQuantidade de x num vetor\n\n");
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

void lerX(int *x){
    printf("\nDigite o valor de x: ");
    scanf("%d", x);
}



int contarX(int tam, int x, int vetor[tam]){

    int maiores = 0;
    for(int i = 0; i < tam; i++){
        if(vetor[i] > x){
            maiores++;
        }
    }

    return maiores;
}

int main(){
    apresentacao();

    int tamanho = tam();

    int* vetor = (int *)malloc(tamanho * sizeof(int));

    lerVetor(tamanho, vetor);

    int x;
    lerX(&x);
    
    int maiores = contarX(tamanho, x, vetor);

    printf("\nA quantidade de valores maiores que %d são: %d", x, maiores);

    return 0;
    free(vetor);
}