#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nPeso Ideal De uma vila Sem variavel Convencional e Vetor de Verdade\n\n");
}

void lerTamanho(int* tamanho){
    printf("Digite quantos habitantes são: ");
    scanf("%d", tamanho);
}

void lerVetores(int tamanho, float alturas[tamanho], char generos[tamanho]){
    
    for(int i = 0; i < tamanho; i++){
        printf("\nDigite a altura da %d pessoa: ", i + 1);
        scanf("%f", &alturas[i]);
        printf("\nDigite o genero da %d pessoa: ", i + 1);
        scanf(" %c", &generos[i]);
    }
}

void calcularPesosIdeais(int tamanho, float alturas[tamanho], char generos[tamanho], float pesosIdeais[tamanho]){

    for(int i = 0; i < tamanho; i++){
        if(generos[i] == 'f' || generos[i] == 'F'){
            pesosIdeais[i] = (62.1 * alturas[i]) - 44.7;
        }
        else if(generos[i] == 'm' || generos[i] == 'M'){
            pesosIdeais[i] = (72.2 * alturas[i]) - 58;
        }
    }
}

void printPesosIdeais(int tamanho, float pesosIdeais[tamanho]){

    for(int i = 0; i < tamanho; i++){
        printf("\nO peso ideal da pessoa %d e: %.2f", i + 1, pesosIdeais[i]);
    }
}

int main(){
    apresentacao();

    int tamanho;
    lerTamanho(&tamanho);

    float alturas[tamanho];
    char generos[tamanho];
    float pesosIdeais[tamanho];

    lerVetores(tamanho, alturas, generos);
    calcularPesosIdeais(tamanho, alturas, generos, pesosIdeais);
    printPesosIdeais(tamanho, pesosIdeais);

    return 0;
}
