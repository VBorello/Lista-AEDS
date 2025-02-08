#include <iostream>
#include <time.h>

using namespace std;

void apresentacao(){
    cout << "\nSorteio da sorte\n" << endl;
}


void pegarQtd(int *qtd){
    cout << "\nDigite quantos serão os premios: ";
    cin >> *qtd;
}

void definirPremios(string *premios, int qtd){
    
    cin.ignore();

    for(int i = 0; i < qtd; i++){
        cout << "\nDigite o premio " << i + 1 << ": "; 
        getline(cin, premios[i]);

    }    
}

int sortear(int qtd){
    
    srand(time(0));

    return rand()% qtd - 1;
}

int main(){
    apresentacao();

    int qtd;
    pegarQtd(&qtd);

    string* premios = new string[qtd];

    definirPremios(premios, qtd);

    int sorteado = sortear(qtd);


    cout << "\nO premio sorteado foi: " << premios[sorteado] << "!" << endl;

    delete[] premios; 
}

