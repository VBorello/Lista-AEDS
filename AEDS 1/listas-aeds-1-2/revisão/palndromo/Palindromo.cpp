#include <iostream>
#include <string>

using namespace std;

void apresentacao(){
    cout << "\nPalindromo\n" << endl;
}

bool palindromo(string palavra){

    bool palindromo = true;
    int inicio = 0;
    int tamanho = palavra.length() - 1;

        while(inicio <= tamanho){
            if(palavra[inicio] != palavra[tamanho]){
                palindromo = false;
            }
            inicio++;
            tamanho--;
        }

        return palindromo;
}

int main(){
    apresentacao();

    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    if(palindromo(palavra)){
        cout << "\na palavra " << palavra << " e palindromo" << endl;
    }
    else{
        cout << "\na palavra " << palavra << " nao e um palindromo" << endl;
    }


    return 0;
}
