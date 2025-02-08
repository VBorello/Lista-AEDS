#include <stdio.h>

#define BRANCA 0
#define PRETA 1
#define VAZIA 9

int main() {
    int N;
    scanf("%d", &N);

    int tabuleiro[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &tabuleiro[i][j]);
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (tabuleiro[i][j] == VAZIA) {
                int brancas = 0, pretas = 0;
                
                if (tabuleiro[i][j - 1] == BRANCA) brancas++; else pretas++;
                if (tabuleiro[i - 1][j - 1] == BRANCA) brancas++; else pretas++;
                if (tabuleiro[i - 1][j] == BRANCA) brancas++; else pretas++;

                if (brancas > pretas) {
                    tabuleiro[i][j] = PRETA;
                } else {
                    tabuleiro[i][j] = BRANCA;
                }
            }
        }
    }

    printf("%d\n", tabuleiro[N-1][N-1]);

    return 0;
}
