#include <iostream>

#define tam 3

int lerX(){
    int x;
    std::cout << "Digite qual linha e Coluna quer:";
    std::cin >> x;

    return x;
}

void lerM(int m[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            std::cout << "valor [" << i + 1 << "][" << j + 1 << "]:";
            std::cin >> m[i][j];
        }
    }
}

bool linhaIgualColuna(int m[tam][tam], int x){
    for(int i = 0; i < tam; i++){
        if(m[x][i] == m[i][x]){
            std::cout << " a coluna x é igual a linha x";
            return true;
        }
    }
    std::cout << " a coluna não x é igual a linha x";
    return false;
}

void printM(int m[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    int m[tam][tam];
    int x = lerX();

    lerM(m);

    linhaIgualColuna(m, x);

    return 0;
}

    
