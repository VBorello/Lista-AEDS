#include <iostream>

class Quadrado {
private:
    float lado;

public:

    Quadrado() : lado(0) {}

    void setLado(float l) {
        if (l >= 0) {
            lado = l;
        } else {
            std::cout << "Valor negativo não é permitido. Atribuindo 0." << std::endl;
            lado = 0;
        }
    }

    float getLado() const {
        return lado;
    }

    float perimetro() const {
        return 4 * lado;
    }

    float area() const {
        return lado * lado;
    }

    void lerLado() {
        float l;
        std::cout << "Digite o valor do lado: ";
        std::cin >> l;
        setLado(l);
    }

    void exibirLado() const {
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
