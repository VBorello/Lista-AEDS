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

    if(tam <= 0){
        return 0;
    }

    int maiores = 0;
    if(vetor[tam - 1] > x){
        maiores = 1;
    }

    return maiores + contarX(tam -1, x, vetor);
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