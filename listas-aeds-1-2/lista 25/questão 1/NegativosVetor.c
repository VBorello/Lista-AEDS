#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nNegativos em um Vetor\n\n");
}

void lerTam(int *tam){
    printf("Digite o tamanho do vetor: ");
    scanf("%d", tam);
}

void lerVetor(int tam, float vetor[tam]){
    
    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor %d do vetor: ", i + 1);
        scanf("%f", &vetor[i]);
    }

}

void calcularNegativos(int tam, float vetor[tam], int* negativos){

    *negativos = 0;

    for(int i = 0; i < tam; i++){
        if(vetor[i] < 0){
            (*negativos)++;
        }
    }
}

int main(){
    apresentacao();

    int tam;
    lerTam(&tam);

    float* vetor = (float *)malloc(tam * sizeof(float));

    lerVetor(tam, vetor);

    int negativos;
    calcularNegativos(tam, vetor, &negativos);

    printf("\nsão %d numeros negativos presentes no vetor", negativos);


    return 0;
}
