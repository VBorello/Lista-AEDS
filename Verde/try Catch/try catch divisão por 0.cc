#include <iostream>
#include <exception>
#include <stdbool.h>

using namespace std;

int divisao(int x, int y){
    if(y == 0)throw runtime_error("erro: divisao por 0");
    else return x / y;
}

int main(){
    int a, b;
    bool execao = true;

    system("clear");

do{
    cout << "\nDigite dois valores:";
    cin >> a >> b;
    
    try{
        cout <<"\nResultado:"<< divisao(a,b);
        execao = false;
    }

    catch(runtime_error e){
        cout << e.what();
    }

}while(execao);

    cout << "\nSempre executado ainda que o divisor for igual a 0";

    return 0;
}