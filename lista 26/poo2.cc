#include <iostream>

class quadrado{
private:
    float lado;

public:
    quadrado() : lado(0) {}

    void setLado(float l){
        if(l <= 0){
            std::cout << "valor negativo é invalido bb" << std::endl;
            lado = 0;
        }
        else{
            lado = l;
        }
    }

    float getLado(){
        return lado;
    }

    float area(){
        return lado * lado;
    }

    float perimetro(){
        return lado * 4;
    }

    void lerLado(){
        float l;
        std::cout << "Digite o Lado do Quadrado:";
        std::cin >> l;
        setLado(l);
    }

    void printLado(){
        std::cout << "\nlado:" << lado << std::endl;
    }

};

int main(){

    quadrado q;

    q.lerLado();

    q.printLado();

    std::cout << "\nperimetro:" << q.perimetro() << std::endl;
    std::cout << "\narea:" << q.area() << std::endl;

    return 0;
}

