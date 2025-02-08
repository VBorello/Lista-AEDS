#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void apresentacao(){
    cout << "\nMegacena\n\n";
}

void jogar(int jogo[6]){
    
    for(int i = 0; i < 6; i++){
        cout << "\nDigite o " <<  i + 1  << "° numero: ";
        cin >> jogo[i]; 
    }

}

void sorteioRecursivo(int sorteados[6], int contador){

    if(contador == 6){
        return;
    }

    sorteados[contador] = rand() % 60 + 1;

    sorteioRecursivo(sorteados, contador + 1);
}

void ordenar(int jogo[6]){
    
    for(int i = 0; i < 6 - 1; i++){
        for(int j = 0; j < 6 - 1 - i; j++){
            if(jogo[i] > jogo[j + 1]){
                int aux = jogo[j];
                jogo[j] = jogo[j + 1];
                jogo[j + 1] = aux;
            }
        }
    }
}

int confirmacao(int jogo[6], int sorteados[6]){

    ordenar(jogo);
    ordenar(sorteados);

    bool sucesso = true;

    for(int i = 0; i < 6; i++){
        if(jogo[i] != sorteados[i]){
            sucesso = false;
        }
    }

    return sucesso;
}

void printV(int v[6]){
    for(int i = 0; i < 6; i++){
        cout << v[i] << " ";
    }
}

int main(){
    apresentacao();

    int jogo[6];
    int sorteados[6];

    jogar(jogo);

    int contador = 0;
    sorteioRecursivo(sorteados, contador);

    cout << "\nseu jogo:\n" << endl;
    printV(jogo);
    cout << "\n\nnumeros sorteados:\n" << endl;
    printV(sorteados);

    if(confirmacao(jogo, sorteados)){
        cout << "\n\nTU GANHOU KRL!!!!!" << endl;
    }
    else{
        cout << "\n\nque pena você perdeu" << endl;
    }

    return 0; 
}