#include <iostream>

float elementosIguais(int a[], int b[], int tam){
    int qtd = 0;

    for(int i = 0; i < tam; i++){
        if(a[i] == b[i]){
            qtd++;
        }
    }
    
    return qtd;
}

int main(){
    
    int tam = 5;
    int a[tam] = {1, 2, 3, 4, 5};
    int b[tam] = {1, 2, 3, 4, 6};

    int elementos = elementosIguais(a, b, tam);
    
    std::cout << "valores iguais " << elementos << std::endl;

    return 0;
}