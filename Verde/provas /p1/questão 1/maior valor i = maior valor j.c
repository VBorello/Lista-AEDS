#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao() {
    printf("\nIdentificar se o maior numero da coluna e o mesmo da linha\n\n");
}

void lerTam(int* tam) {
    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", tam);
    printf("\n");
}

void lerM(int** m, int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("Digite [%d][%d]: ", i + 1, j + 1); 
            scanf("%d", &m[i][j]);
        }
    }
}

void lerI(int* lin) {
    printf("\nDigite qual linha tu queres: ");
    scanf("%d", lin);
}

void lerC(int* col) {
    printf("\nDigite qual coluna tu queres: ");
    scanf("%d", col);
}

void identificarMaior(int i, int j, int** m, int tam, int* maiorL, int* maiorC) {
    *maiorL = m[i][0]; 
    *maiorC = m[0][j];  

    for (int x = 0; x < tam; x++) {
        if (m[i][x] > *maiorL) {
            *maiorL = m[i][x];
        }
    }

    for (int x = 0; x < tam; x++) {
        if (m[x][j] > *maiorC) {
            *maiorC = m[x][j];
        }
    }
}

bool mesmoNum(int i, int j, int** m, int tam, int maiorL, int maiorC) {
    if (maiorL == maiorC) {
        printf("\nO maior valor da linha %d é também o maior da coluna %d\n\n", i + 1, j + 1);
        return true;
    } else {
        printf("\nO maior valor da linha %d não é o maior da coluna %d\n\n", i + 1, j + 1);
        return false;
    }
}

void printM(int** m, int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {

    apresentacao();
    
    int tamanho;
    lerTam(&tamanho);

    int **m = (int **)malloc(tamanho * sizeof(int*));

    for (int i = 0; i < tamanho; i++) {
        m[i] = (int *)malloc(tamanho * sizeof(int));
    }

    if (m == NULL) {
        printf("ERRO AO MALOCAR");
        return 1;
    }

    lerM(m, tamanho);

    int linha, coluna;
    lerI(&linha);
    lerC(&coluna);

    linha--;
    coluna--;

    int maiorL, maiorC;
    identificarMaior(linha, coluna, m, tamanho, &maiorL, &maiorC);
    mesmoNum(linha, coluna, m, tamanho, maiorL, maiorC);

    printM(m, tamanho);

    for (int i = 0; i < tamanho; i++) {
        free(m[i]);
    }

    free(m);

    return 0;
}
