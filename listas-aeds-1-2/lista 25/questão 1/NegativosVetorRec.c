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

float calcularNegativos(int tam, float vetor[tam]){

    if(tam <= 0){
        return 0;
    }
    
    return (vetor[tam - 1] > 0 ? 1 : 0) + calcularNegativos(tam - 1, vetor);
}

int main(){
    apresentacao();

    int tam;
    lerTam(&tam);

    float* vetor = (float *)malloc(tam * sizeof(float));

    lerVetor(tam, vetor);

    int negativos;
    negativos = calcularNegativos(tam, vetor);

    printf("\nsão %d numeros negativos presentes no vetor", negativos);


    return 0;
}
