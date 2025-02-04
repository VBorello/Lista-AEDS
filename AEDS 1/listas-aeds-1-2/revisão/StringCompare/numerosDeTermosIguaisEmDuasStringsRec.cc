#include <iostream>
#include <string>

using namespace std;

#define MAX 100

void apresentacao(){
    cout << "\nNumeros de termos iguais em strings Class\n" << endl;
}

void lerString(string &palavra){
    cout << "Digite uma palavra: ";
    cin.ignore();
    getline(cin, palavra);
}


int termosIguaisRec(string &palavra1, string &palavra2, int tamanho){

    if(tamanho <= 0){
        return 0;
    }

    int iguais = 0;

    if(palavra1[tamanho] == palavra2[tamanho]){
        iguais = 1;
    }

    return iguais + termosIguaisRec(palavra1, palavra2, tamanho - 1);
}

int main(){

    apresentacao();

    string palavra1;
    string palavra2;

    lerString(palavra1);
    lerString(palavra2);

    int tam1 = palavra1.size();
    int tam2 = palavra2.size();

    int maior = 0;
    if(tam1 > tam2){
        maior = tam1;
    }
    else{
        maior = tam2;
    }

    int tamanho = maior;

    int iguais = termosIguaisRec(palavra1, palavra2, tamanho);

    cout << "\na string: " << palavra1 << " e a string: " << palavra2 << " possuem: " << iguais << " termos em comum." << endl;

    return 0;

}