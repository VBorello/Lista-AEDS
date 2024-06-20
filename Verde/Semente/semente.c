#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// propagação da tinta
int distancia(int f, int r, int* posicoes) {
    bool* fita = (bool*)malloc(f * sizeof(bool));
    for (int i = 0; i < f; i++) {
        fita[i] = false; // sem marcas iniciais
    }
    
    int* fila = (int*)malloc(f * sizeof(int));
    int frente = 0, tras = 0;

    //posições iniciais
    for (int i = 0; i < r; i++) {
        int gota = posicoes[i] - 1;
        fita[gota] = true;
        fila[tras++] = gota; // Adiciona as posições iniciais na fila
    }

    int dias = 0;
    while (frente < tras) {
        int tamanhoAtual = tras - frente;
        for (int i = 0; i < tamanhoAtual; i++) {
            int gota = fila[frente++];
            
            // Propaga para esquerda
            if (gota - 1 >= 0 && !fita[gota - 1]) {
                fita[gota - 1] = true;
                fila[tras++] = gota - 1;
            }
            // Propaga para direita
            if (gota + 1 < f && !fita[gota + 1]) {
                fita[gota + 1] = true;
                fila[tras++] = gota + 1;
            }
        }
        if (tras - frente > 0) {
            dias++;
        }
    }
    
    free(fita);
    free(fila);
    
    return dias;
}

int main() {
    int f, r;
    scanf("%d %d", &f, &r);
    
    int* posicoes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        scanf("%d", &posicoes[i]);
    }
    
    int dias = distancia(f, r, posicoes);
    printf("%d\n", dias);
    
    free(posicoes);
    return 0;
}
