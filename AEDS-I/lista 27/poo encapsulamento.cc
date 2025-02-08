#include <string>
#include <iostream>
#include <sstream>

#define max 100

using namespace std;

class Quadrado{

private:
    string cor;
    int lado;

public:

    Quadrado(): lado(0) {}

    void setCor(string cor){
        this -> cor = cor;
    }

    void setLado(int lado){
        this -> lado = lado;
    }

    string getCor(){
        return cor;
    }

    int getLado(){
        return lado;
    } 

    int perimetro(){
        return lado * 4;
    }

    int area(){
        return lado * lado;
    }

    void lerLado(){
        cout << "Digite o lado: ";
        cin >> lado;
    }

    void lerCor(){
        cout << "\nDigite a cor do quadrado: ";
        cin >> cor;
    }

    void printLadoCor(){
        cout << "\ncor: " << cor;
        cout << "\nlado: " << lado;
    }
};

int main(){
    Quadrado* quadrado[max];
    int opcao;
    int contador = 0;

    

do{

    cout << "\nMenu\n0 para sair\n1 para inserir Quadrado\n2 para listar Quadrados:\n";
    cin >> opcao;

    switch (opcao){
    
        case 0:{
            cout << "Saindo";
            break;
        }

        case 1: {
            if(contador < max){
                quadrado[contador] = new Quadrado();
                quadrado[contador] -> lerLado();
                quadrado[contador] -> lerCor();
                contador++;
            } else{
                cout << "Maximo de quadrados atingidos";
            }
            break;
        }

        case 2: {
            cout <<"Quadrados";
            for(int i = 0; i < contador; i++){
                cout << "quadrado" << i + 1 << ": ";
                quadrado[i] -> printLadoCor(); 
            }
            break;
        }

        default: {
            cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }            

} while (opcao != 0);

    for (int i = 0; i < contador; i++) {
            delete quadrado[i];
    }

return 0;

}
