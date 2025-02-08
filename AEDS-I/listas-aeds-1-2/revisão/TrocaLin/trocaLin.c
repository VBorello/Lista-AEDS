#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nTrocador de Linhas Matrizais\n\n");
}

void pegarTam(int *tam){
    printf("Digite o tamanho da matriz(quadrada):");
    scanf("%d", tam);
}

void lerMatriz(int tam, float m[][tam]){

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("\nDigite o valor na posicao [%d][%d] da matriz: ", i + 1, j + 1); 
            scanf("%f", &m[i][j]);
        }
    }
}

int lerLinhas(){
    
    int lin1;
    printf("\nDigite a linha: ");
    scanf("%d", &lin1);

    return lin1;
}

void trocaLinhas(int tam, float m[][tam]){
    
    int lin1 = lerLinhas(); 
    int lin2 = lerLinhas();

    for(int j = 0; j < tam; j++){
        float aux = m[lin1][j];
        m[lin1][j] = m[lin2][j];
        m[lin2][j] = aux;
    }
}

void printM(int tam, float m[][tam]){
    
    printf("\n");
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                printf("%.0f ", m[i][j]);
            }
            printf("\n");
        }
}

int main(){
    apresentacao();

    int tamanho;
    pegarTam(&tamanho);

    float matriz[tamanho][tamanho];
    lerMatriz(tamanho, matriz);

    printM(tamanho, matriz);
    trocaLinhas(tamanho, matriz);
    printM(tamanho, matriz);

    return 0;
}
