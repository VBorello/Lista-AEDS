#include <iostream>
#include <string>

void lerPalavra(char *v){
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
        if(v[i] !=  v[tamanho] - 1 - i){
            std::cout << v << "nao e palindromo" << std::endl;
            return false;
        }
    }

    std::cout << v << "nao e um palindromo" << std::endl;
    return true;
}

int main(){
   char *v;

    lerPalavra(v);
    palindromo(v);

    return 0;
}