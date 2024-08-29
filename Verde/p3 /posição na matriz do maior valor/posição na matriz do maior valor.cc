#include <iostream>

#define tam 3

int posicionamento(int m[tam][tam]){
    int maior = m[0][0];
    int posicao = 0;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(m[i][j] > maior){
                maior = m[i][j];

                if(i == j){
                    posicao = 0; //na principal
                }
                else if(i < j){
                    posicao = 1; //acima da principal
                }
                else if(i > j){
                    posicao = -1; //abaixo da principal 
                }
            
            }
        }
    }

    return posicao;
}

void lerM(int m[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            std::cout << "Digite [" << i + 1 << "][" << j + 1 << "]:";
            std::cin >> m[i][j];
        }
    }
}

int Maior(int m[tam][tam]){
    int maior = m[0][0];

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(m[i][j] > maior){
                maior = m[i][j];
            }
        }
    }
    return maior;
}    

int main(){
    int m[tam][tam];
    
    lerM(m);

    int maior = Maior(m);

    std::cout << "O maior valor e:" << maior << std::endl;

    int posicao = posicionamento(m);

    if(posicao == 0){
        std::cout << "O maior valor esta na diagonal principal" << std::endl;
    }
    else if(posicao == 1){
        std::cout << "O maior valor esta acima da diagonal principal" << std::endl;
    }
    else if(posicao == -1){
        std::cout << "O maior valor esta abaixo da diagonal principal" << std::endl;
    }

    return 0;
}
