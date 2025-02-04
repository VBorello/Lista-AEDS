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

    cout << "\nseus numeros: " << endl;
    for(int i = 0; i < 6; i++){
        cout << jogo[i] << " ";
    }
    
}

void sorteio(int sorteados[6]){

    srand(time(0));

    cout << "\n\nNumeros Sorteados: " << endl;
    for(int i = 0; i < 6; i++){
        sorteados[i] = rand() %60 + 1;
        cout << sorteados[i] << " ";
    }

    cout << endl;
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

int main(){
    apresentacao();

    int jogo[6];
    int sorteados[6];

    jogar(jogo);
    sorteio(sorteados);

    if(confirmacao(jogo, sorteados)){
        cout << "\nTU GANHOU KRL!!!!!" << endl;
    }
    else{
        cout << "\nque pena você perdeu" << endl;
    }

    return 0; 
}