#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao() {
    system("clear");
    printf("\nComparador de Matrizes\n\n");
}

int lerTam() {

    int tam;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tam);
    return tam;
}

void lerMatriz(int tam, int m[tam][tam]) {

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("Digite o valor do[%d][%d] da matriz: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

bool compararMatrizes(int tam, int m1[tam][tam], int m2[tam][tam]) {
    
    bool iguais;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if (m1[i][j] != m2[i][j]){
                iguais = false;
            }
        }
    }
    return iguais;
}

int lerLinha() {
    
    int linha;
    printf("\nDigite a linha: ");
    scanf("%d", &linha);
    return linha - 1;
}

int identificarMaior(int linha, int tam, int m[tam][tam]) {
    
    int maior = m[linha][0];
    for(int j = 0; j < tam; j++){
        if(m[linha][j] > maior){
            maior = m[linha][j];
        }
    }
    return maior;
}

int diferenciadorEntreMaioresTermosAcimaEabaixoDaDiagonal(int *maiorAcima, int *maiorAbaixo, int tam, int m[tam][tam]) {
    // função desgranhenta.
    *maiorAcima = 0;
    *maiorAbaixo = 0;

    for(int i = 0; i < tam; i++){
        for(int j = i + 1; j < tam; j++){
            if(m[i][j] > *maiorAcima){
                *maiorAcima = m[i][j];
            }
        }
    }

    for(int i = 1; i < tam; i++){
        for(int j = 0; j < i; j++){
            if(m[i][j] > *maiorAbaixo){
                *maiorAbaixo = m[i][j];
            }
        }
    }

    return abs(*maiorAcima - *maiorAbaixo);
}

void printM(int tam, int m[tam][tam]){
    
    printf("\nMatriz:\n");
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void trocaMatriz(int tam, int m1[tam][tam], int m2[tam][tam]) {
    
    int mAux[tam][tam];
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            mAux[i][j] = m1[i][j];
            m1[i][j] = m2[i][j];
            m2[i][j] = mAux[i][j];
        }
    }
}

void transpostar(int tam, int m[tam][tam]){

    printf("\nMatriz Transposta:\n");
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("%d ", m[j][i]);
        }
        printf("\n");
    }
}

int main() {
    apresentacao();

    int tamanho = lerTam();

    int m[tamanho][tamanho];
    int m2[tamanho][tamanho];

    printf("\nPreencha a primeira matriz -\n");
    lerMatriz(tamanho, m);
    printf("\nPreencha a segunda matriz -\n");
    lerMatriz(tamanho, m2);

    printM(tamanho, m);
    printM(tamanho, m2);

    int opcao;
    printf("\nDigite qual matriz será testada (1- matriz 1, 2- matriz 2): ");
    scanf("%d", &opcao);

    printf("\nMatriz %d transposta:\n", opcao);
    if (opcao == 1) {
        transpostar(tamanho, m);
    } else {
        transpostar(tamanho, m2);
    }

    bool iguais = compararMatrizes(tamanho, m, m2);

    int linha = lerLinha();

    int maior;
    if (opcao == 1) {
        maior = identificarMaior(linha, tamanho, m);
    } else {
        maior = identificarMaior(linha, tamanho, m2);
    }
    printf("\nO maior termo da linha %d da matriz %d é: %d\n", linha + 1, opcao, maior);

    int diferenca;
    int maiorAcima;
    int maiorAbaixo;
    if (opcao == 1) {
        diferenca = diferenciadorEntreMaioresTermosAcimaEabaixoDaDiagonal(&maiorAcima, &maiorAbaixo, tamanho, m);
    } else {
        diferenca = diferenciadorEntreMaioresTermosAcimaEabaixoDaDiagonal(&maiorAcima, &maiorAbaixo, tamanho, m2);
    }
    printf("\nA diferença entre o maior termo acima da diagonal principal: %d e o maior termo abaixo da diagonal principal: %d é: %d\n",
           maiorAcima, maiorAbaixo, diferenca);

    if (iguais) {
        printf("\nAs matrizes são iguais!\n");
    } else {
        printf("\nAs matrizes são diferentes!\n");
    }

    printf("\nMatrizes Trocadas:\n");
    trocaMatriz(tamanho, m, m2);
    printM(tamanho, m);
    printM(tamanho, m2);

    return 0;
}
