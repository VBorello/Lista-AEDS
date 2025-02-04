#include <iostream>

#define LIN 3

// Função que encontra o maior valor na matriz e sua posição
int maiorValor(int m[LIN][LIN]) {
    int maior = m[0][0];
    int maiorLin = 0;
    int maiorCol = 0;
    int posicao;

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < LIN; j++) {
            if (m[i][j] > maior) {
                maior = m[i][j];
                maiorLin = i;
                maiorCol = j;
            }
        }
    }

    if (maiorLin == maiorCol) { // Diagonal principal
        posicao = 0;
    } else if (maiorLin < maiorCol) { // Acima da diagonal principal
        posicao = 1;
    } else if (maiorLin > maiorCol) { // Abaixo da diagonal principal
        posicao = -1;
    }

    return posicao;
}

int main() {
    int m[LIN][LIN] = {
        {10, 10, 10},
        {10, 10, 10},
        {10, 10, 10}
    };

    int posicao = maiorValor(m);

    if (posicao == 0) {
        std::cout << "O maior valor está na diagonal principal" << std::endl;
    } else if (posicao == 1) {
        std::cout << "O maior valor está acima da diagonal principal" << std::endl;
    } else if(posicao == -1){
        std::cout << "O maior valor está abaixo da diagonal principal" << std::endl;
    }

    return 0;
}
