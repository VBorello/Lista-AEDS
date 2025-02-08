#include <iostream>
#include <stdbool.h>

using namespace std;

void apresentacao(){
    cout << "\nIdentificador de Natural\n\n";
}

void lerNum(int *num){
    
    cout << "Digite um numero: ";
    cin >> *num;

}

bool eNatural(int num){

    bool natural = true;
    
    if(num < 0){
        natural =  false;
    }

    return natural;
}

int main(){
    apresentacao();

    int numero;
    lerNum(&numero);

    if(eNatural(numero)){
        cout << "\nÉ natural";
    }
    else{
        cout << "\nNão é natural";
    }

    return 0;
}