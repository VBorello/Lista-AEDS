#include <iostream>

using namespace std;

void menorElemento(int** m, int lin, int col, int& menor, int& linhaMenor) {
    menor = m[0][0];
    linhaMenor = 0;

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] < menor) {
                menor = m[i][j];
                linhaMenor = i;
            }
        }
    }
}

int maiorElemento(int** m, int lin, int col) {
    int maior = m[lin][0];

    for (int j = 1; j < col; j++) {
        if (m[lin][j] > maior) {
            maior = m[lin][j];
        }
    }

    return maior;
}

int minmax(int** m, int lin, int col) {
    int menor, linhaMenor;
    menorElemento(m, lin, col, menor, linhaMenor);
    return maiorElemento(m, linhaMenor, col);
}

int lerLin() {
    int lin;
    cout << "Digite a quantidade de linhas da matriz: ";
    cin >> lin;
    return lin;
}

int lerCol() {
    int col;
    cout << "Digite a quantidade de colunas da matriz: ";
    cin >> col;
    return col;
}

void lerM(int** m, int lin, int col) {
    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            cin >> m[i][j];
        }
    }
}

void printM(int** m, int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int lin, col;

    lin = lerLin();
    col = lerCol();

    int** m = new int*[lin];
    for (int i = 0; i < lin; i++) {
        m[i] = new int[col];
    }

    lerM(m, lin, col);

    int numMinmax = minmax(m, lin, col);

    printM(m, lin, col);

    cout << "O maior numero da linha com o menor numero e: " << numMinmax << endl;

    for (int i = 0; i < lin; i++) {
        delete[] m[i];
    }
    delete[] m;

    return 0;
}
