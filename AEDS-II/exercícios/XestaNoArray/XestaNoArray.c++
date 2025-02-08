#include <iostream>

using namespace std;

void apresentacao(){
    cout <<"\nX esta no array\n" << endl;
}

void lerX(int *x){
    cout << "Digite o valor de x: ";
    cin >> *x;
}

void lerTam(int *tam){
    cout << "\nDigite o tamanho do array: ";
    cin >> *tam;
}

void lerArray(int tam, int array[]){
    for(int i = 0; i < tam; i++){
        cout << "\nDigite o valor " << i << " do array: ";
        cin >> array[i];
    }
}

bool verificarArray(int x, int tam, int array[]){

    for(int i = 0; i < tam; i++){
        if(array[i] == x){
            return true;
        }
    }
    return false;
}

int main(){

    apresentacao();

    int x;
    lerX(&x);

    int tam;
    lerTam(&tam);

    int array[tam];
    lerArray(tam, array);

    if(verificarArray(x, tam, array)){
        cout <<" \nX está presente no array.";
    }
    else{
        cout << "\nX não está presente no array";
    }


    return 0;
}