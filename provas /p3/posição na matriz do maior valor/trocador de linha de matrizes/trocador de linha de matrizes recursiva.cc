#include <iostream>

#define tam 3

void lerM(int m[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            std::cout << "Digite [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> m[i][j];
        }
    }   
}

void trocarLinhas(int m[tam][tam], int p1, int p2, int col){
    if(col >= tam){
        return;
    }

    int aux = m[p1][col];
    m[p1][col] = m[p2][col];
    m[p2][col] = aux;

    trocarLinhas(m, p1, p2, col + 1);
}

void trocarLinhasRec(int m[tam][tam], int p1, int p2){

    trocarLinhas(m, p1, p2, 0);
}

void printM(int m[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int m[tam][tam];
    
    lerM(m);

    int p1, p2;
    std::cout << "Digite a 1ª linha para troca (0 a " << tam - 1 << "): ";
    std::cin >> p1;
    std::cout << "Digite a 2ª linha para troca (0 a " << tam - 1 << "): ";
    std::cin >> p2;

    if (p1 < 0 || p1 >= tam || p2 < 0 || p2 >= tam) {
        std::cout << "Índices de linha inválidos!" << std::endl;
        return 1;
    }

    trocarLinhasRec(m, p1, p2);

    std::cout << "Matriz após a troca das linhas " << p1 << " e " << p2 << ":" << std::endl;
    printM(m);

    return 0;
}