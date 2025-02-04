#include <stdio.h>

#define MAX_N 500
#define MAX_M 500

char parede[MAX_N][MAX_M];

void printParede(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", parede[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Leitura da matriz
    for (int i = 0; i < N; i++) {
        scanf("%s", parede[i]);
    }

    // Processamento para propagar a água
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (parede[i][j] == '.') {
                // Verifica condições para propagar a água
                if (parede[i - 1][j] == 'o' ||
                    (j > 0 && parede[i][j - 1] == 'o' && parede[i + 1][j - 1] == '#') ||
                    (j < M - 1 && parede[i][j + 1] == 'o' && parede[i + 1][j + 1] == '#')) {
                    parede[i][j] = 'o';
                }
            }
        }
    }

    // Imprime a parede após a propagação da água
    printParede(N, M);

    return 0;
}
