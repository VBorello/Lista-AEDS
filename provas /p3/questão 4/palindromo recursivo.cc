#include <iostream>

void lerPalavra(char *v, int tamanho){
    std::cout << "Digite uma palavra:";
    std::cin >> v;

}

int lerTamanho(char *v){
    int tamanho = 0;
    while (v[tamanho] != '\0'){
        tamanho++;
    }
    
    return tamanho;
}

bool palindromoREC(char *v, int inicio, int fim){
    if(inicio >= fim){
        std::cout << "e palindromo";
        return true;
    }
    else if(v[inicio] != v[fim]){
        std::cout << "nao e palindromo";
        return false;
    }
    
    return palindromoREC(v, inicio + 1, fim -1);

}

int main(){
    int max = 100;
    char palavra[max];

    lerPalavra(palavra, max);
    int tamanho  = lerTamanho(palavra);
    palindromoREC(palavra, 0, tamanho - 1);//0 inicio, tamanho - 1 fim ( '\0' )


    return 0;
}