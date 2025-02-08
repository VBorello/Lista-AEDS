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


int termosIguais(string &palavra1, string &palavra2){

    int iguais = 0;

    int tam1 = palavra1.size();
    int tam2 = palavra2.size();


    int maior = 0;
    if (tam1 > tam2){
        maior = tam1;
    } 
    else{
        maior = tam2;
    }

    for(int i = 0; i < maior; i++){
        if(palavra1[i] == palavra2[i]){
            iguais++;
        }
    }

    return iguais;
}



int main(){

    apresentacao();

    string palavra1;
    string palavra2;

    lerString(palavra1);
    lerString(palavra2);

    int iguais = termosIguais(palavra1, palavra2);

    cout << "\na string: " << palavra1 << " e a string: " << palavra2 << " possuem: " << iguais << " termos em comum." << endl;

    return 0;

}