#include <iostream>

void lerPalavra(char *v, int tamanho){
    std::cout << "Digite uma palavra: ";
    std::cin >> v;
}

int lerTamanho(char *v){
    int tamanho = 0;
    while(v[tamanho] != '\0'){
        tamanho++; 
    }
    return tamanho;
}

bool palindromo(char *v){
    int tamanho = lerTamanho(v);

    for(int i = 0; i < tamanho / 2; i++){
        if(v[i] != v[tamanho - 1 - i]){
            std::cout << "nao e palindromo";
            return false;
        }
    }

    std::cout << "e palindromo";
    return true;
}

int main(){
    int tamanho = 100;
    char v[tamanho];

    lerPalavra(v, tamanho);
    palindromo(v);

    return 0;
}