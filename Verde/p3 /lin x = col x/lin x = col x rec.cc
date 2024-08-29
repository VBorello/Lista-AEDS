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

bool linhaIgualColuna(int m[tam][tam], int x, int indice){
    if(indice >= tam){
        std::cout << " a coluna x é igual a linha x";
        return true;
    }
    else if(m[x][indice] != m[indice][x]){
        std::cout << " a coluna não x é igual a linha x";
        return false;
    }
    
    return linhaIgualColuna(m, x, indice + 1);
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
    int indice;
    lerM(m);

    linhaIgualColuna(m, x, indice);

    return 0;
}

    
