#include <iostream>

int elementosIguaisREC(float a[], float b[], int tam, int indice = 0){
    if(indice >= tam){
        return 0;
    }

    if(a[indice] == b[indice]){
        return 1 + elementosIguaisREC(a, b, tam, indice + 1);
    }else{
        return elementosIguaisREC(a, b, tam, indice + 1);
    }
}

int main() {
    int tam = 5;
    float a[tam] = {1, 2, 3, 4, 5};
    float b[tam] = {1, 2, 3, 4, 5};
    
    int elementos = elementosIguaisREC(a, b, tam);
    
    std::cout << "numero de elementos iguais: " << elementos << std::endl;
    
    return 0;
}