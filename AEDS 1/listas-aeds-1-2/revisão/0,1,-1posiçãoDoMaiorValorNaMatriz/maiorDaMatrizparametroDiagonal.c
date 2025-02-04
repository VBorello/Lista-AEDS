#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void apresentacao(){
    printf("\n0 Caso o MAIOR esteja na diagonal principal\n1 Caso o MAIOR esteja acima\n-1 Caso o MAIOR esteja abaixo\n\n");
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

int identificarPosicaoDoMaior(int tam, float m[][tam], float *maior){
    
    int posicao;
    *maior = m[0][0];
    int linDoMaior = 0, colDoMaior = 0;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(m[i][j] > *maior){
                *maior = m[i][j];
                linDoMaior = i;
                colDoMaior = j;
            }
        }
    }

    if(linDoMaior < colDoMaior){
        posicao = 1;
    }
    else if(linDoMaior == colDoMaior){
        posicao = 0;
    }
    else if (linDoMaior > colDoMaior){
        posicao = -1;
    }

    return posicao;
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

    float maior;
    int posicao = identificarPosicaoDoMaior(tamanho, matriz, &maior);

    printM(tamanho, matriz);

    if(posicao == 0){
        printf("\n%d A posicao do maior termo da matriz: %.0f está na diagonal.", posicao, maior);
    }
    else if(posicao == -1){
        printf("\n%d A posicao do maior termo da matriz: %.0f está abaixo da diagonal.", posicao, maior);
    }
    else{
        printf("\n%d A posicao do maior termo da matriz: %.0f está acima da diagonal.", posicao, maior);
    }    

    return 0;

}