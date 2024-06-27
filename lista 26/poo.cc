#include <iostream>

class Quadrado {
private:
    float lado;

public:

    Quadrado() : lado(0) {}

    void setLado(float l) {
        if (l <= 0) {
            std::cout << "Pode negativo não Nengue" << std::endl;
            lado = 0;
        } else {
            lado = l;
        }
    }

    float getLado(){
        return lado;
    }

    float perimetro(){
        return 4 * lado;
    }

    float area(){
        return lado * lado;
    }

    void lerLado(){
        float l;
        std::cout << "Digite o valor do lado: ";
        std::cin >> l;
        setLado(l);
    }

    void exibirLado(){
        std::cout << "Valor do lado: " << lado << std::endl;
    }
};

int main() {
    
    Quadrado q;

    q.lerLado();

    q.exibirLado();

    std::cout << "Perímetro: " << q.perimetro() << std::endl;

    std::cout << "Área: " << q.area() << std::endl;

    return 0;
}
