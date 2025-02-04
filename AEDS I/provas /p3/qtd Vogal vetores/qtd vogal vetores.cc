#include <iostream>
#include <cstring>

#define MAX 5

void contarVogais(char caracteres[], int qtdVogais[MAX]) {
   
    for(int i = 0; i < MAX; i++) {
        qtdVogais[i] = 0;
    }
    
    for(int i = 0; i < std::strlen(caracteres); i++) {
        char c = caracteres[i];
        switch(c) {
            case 'a':
                qtdVogais[0]++;
                break;
            case 'e':
                qtdVogais[1]++;
                break;
            case 'i':
                qtdVogais[2]++;
                break;
            case 'o':
                qtdVogais[3]++;
                break;
            case 'u':
                qtdVogais[4]++;
                break;
            default:
                break;
        }
    }
}

int main() {
    const int tam = 100;
    char caracteres[tam];
    int qtdVogais[MAX];

    std::cout << "Digite uma string: ";
    std::cin.getline(caracteres, tam);

    contarVogais(caracteres, qtdVogais);

    std::cout << "Contagem de vogais:" << std::endl;
    std::cout << "a: " << qtdVogais[0] << std::endl;
    std::cout << "e: " << qtdVogais[1] << std::endl;
    std::cout << "i: " << qtdVogais[2] << std::endl;
    std::cout << "o: " << qtdVogais[3] << std::endl;
    std::cout << "u: " << qtdVogais[4] << std::endl;

    return 0;
}
