#include <iostream>
#include <string>

using namespace std;

void apresentacao(){
    cout << "\nPalindromo\n" << endl;
}

bool palindromoRec(string palavra, int inicio, int tamanho){

    if(inicio >= tamanho){
        return true;
    }

    if(palavra[inicio] != palavra[tamanho]){
        return false;
    }

    return palindromoRec(palavra, inicio + 1, tamanho - 1);
}

int main(){
    apresentacao();

    string palavra;


    cout << "Digite uma palavra: ";
    cin >> palavra;

    if(palindromoRec(palavra, 0, palavra.length() - 1)){
        cout << "\na palavra " << palavra << " e palindromo" << endl;
    }
    else{
        cout << "\na palavra " << palavra << " nao e um palindromo" << endl;
    }


    return 0;
}
