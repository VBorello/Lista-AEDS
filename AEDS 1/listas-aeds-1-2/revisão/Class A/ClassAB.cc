#include <iostream>
using namespace std;

// Classe base B com o atributo Y
class B {
protected:
    float y; // Atributo herdado pela classe A
public:
    B(float y = 0.0) : y(y) {}
    float getY() const {
        return y;
    }
};

// Classe A herdando de B
class A : public B {
private:
    float x;               // Atributo X
    static int quantidade; // Atributo estático para contar instâncias

public:
    // Construtor padrão
    A() : x(0.0), B() {
        quantidade++;
    }

    // Construtor com parâmetros
    A(float x, float y) : x(x), B(y) {
        quantidade++;
    }

    // Destrutor
    ~A() {
        quantidade--;
    }

    // Método para configurar os valores de X e Y
    void setA(float x, float y) {
        this->x = x;
        this->y = y;
    }

    // Método para configurar apenas X
    void setX(float x) {
        this->x = x;
    }

    // Método para obter o valor de X
    float getX() const {
        return x;
    }

    // Método para imprimir todos os atributos
    void escreve() const {
        cout << "X: " << x << ", Y: " << y;
    }

    // Método estático para obter a quantidade de instâncias
    static int quantidade() {
        return quantidade;
    }

    // Método para obter o maior valor de X entre o objeto atual e outro
    float maior(const A* outro) const {
        return (this->x > outro->x) ? this->x : outro->x;
    }
};

// Inicialização do membro estático
int A::quantidade = 0;

int main() {
    // Instanciando objetos
    A* objeto = new A();
    objeto->setA(3.5, 2.7);

    // Escrevendo os atributos do objeto
    objeto->escreve();

    // Mostrando o número de instâncias da classe A
    cout << endl << A::quantidade();

    // Criando outro objeto com valores iniciais
    A* outro = new A(1.8, 2.5);

    // Comparando o maior valor de X
    float m = objeto->maior(outro);
    cout << endl << "Maior X: " << m;

    // Escrevendo o valor de Y do objeto
    cout << endl << "Y: " << objeto->getY();

    // Liberando memória
    delete objeto;
    delete outro;

    return 0;
}
