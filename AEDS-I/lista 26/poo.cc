#include <iostream>

using namespace std;

class Quadrado {
private:
    int lado;

public:

    Quadrado() : lado(0) {}

    void setLado(int lado){
        this -> lado = lado;
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
        cout << "digite o valor do lado:";
        cin >> lado;
    }

    void printALL(){
        cout << "\nlado:" << lado;
        cout << "\nperimetro:" << perimetro();
        cout << "\narea:" << area(); 
    }
};

int main(){
    Quadrado square;

    square.lerLado();
    square.printALL();

    return 0;
}