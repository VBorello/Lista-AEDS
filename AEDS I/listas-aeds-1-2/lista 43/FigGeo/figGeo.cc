#include <iostream>

#define MAX 100

using namespace std;

void apresentacao(){
    cout << "\nClass FigGeo\n" << endl;
}

class FigGeo{

    protected:
        int quantidade;
        string cor;

    public:

        FigGeo() : quantidade(0), cor("sem com") {}

        virtual ~FigGeo(){}

        int getQuantidade(){
            return quantidade;
        }

        void setCor(string cor){
            this -> cor = cor;
        }

        string getCor(){
            return cor;
        }

        virtual void leia() = 0;
        virtual void escreva() = 0;

        virtual double perimetro() = 0;
        virtual double area() = 0;

};

class Circulo : public FigGeo{

    private:
        
        double raio;

    public:

        Circulo() : raio(0) {}

        Circulo(double raio) : raio(raio) {}
        Circulo(double raio, string cor) : raio(raio) {
            setCor(cor);
        }

        void setRaio(double raio){
            this -> raio = raio;
        }

        double getRaio(){
            return raio;
        }

        void leia() override{
            cout << "\nDigite o raio do circulo: ";
            cin >> raio; 
            cout << "\nDigite a cor do circulo: ";
            cin >> cor;
        }

        void escreva() override{
            cout << "\nCirculo: Raio: " << raio << ", Cor: " << cor << endl; 
        }

        double area() override{
            return 3.14 * raio * raio;
        }

        double perimetro() override{
            return 3.14 * raio * 2;
        }
};

class Quadrado : public FigGeo{

    private:

        double lado;
    
    public:

        Quadrado(): lado(0) {}
        
        Quadrado(double lado) : lado(lado){}
        Quadrado(double lado, string cor) : lado(lado) {
            setCor(cor);
        }

        void setLado(double lado){
            this -> lado = lado;
        }

        double getLado(){
            return lado;
        }

        void leia() override{
            cout << "\nDigite o valor do lado do quadrado: ";
            cin >> lado;
            cout << "\nDigite a cor do quadrado: ";
            cin >> cor;
        }

        void escreva() override{
            cout << "\nQuadrado: Lado: " << lado << ", Cor: " << cor << endl;
        }

        double area() override{
            return lado * lado;
        }

        double perimetro() override{
            return lado * 4;
        }
};

class Triangulo : public FigGeo{

    private:

        double a;
        double b;
        double c;
    
    public:

        Triangulo() : a(0), b(0), c(0) {}
        Triangulo(double a, double b, double c) : a(a), b(b), c(c) {} 
        Triangulo(double a, double b, double c, string cor) : a(a), b(b), c(c) {
            setCor(cor);
        }

        void setTriangulo(double a, double b, double c, string cor){
            this -> a = a;
            this -> b = b;
            this -> c = c;
            setCor(cor);
        }

        double getA(){
            return a;
        }

        double getB(){
            return b;
        }

        double getC(){
            return c;
        }

        void leia() override{
            cout << "\nDigite os 3 lados do triangulo a, b e c: ";
            cin >> a >> b >> c;
            cout << "\nDigite a cor do triangulo: ";
            cin >> cor;
        }

        void escreva() override{
            cout << "\nTriangulo: Lado a: " << a << ", lado b: " << b << ", lado c: " << c << ", cor: " << cor << endl;
        }

        double perimetro() override{
            return a + b + c;
        }
        
        double area() override{
            return a * c / 2;
        }

        bool valido() {
            return (a + b > c) && (a + c > b) && (b + c > a);
        }
};

void menuFigGeo(FigGeo *figuras[], int &quantidade, int opcaoFig){
    
    int opcao;
    do{
        cout << "\n0 - Voltar\n1 - Cadastrar\n2 - Listar\n: ";
        cin >> opcao;
    
        switch (opcao) {
            case 0:
                break;
            case 1: {
                if (quantidade >= MAX) {
                    cout << "O limite de figuras foi atingido.\n";
                    break;
                }

                FigGeo* novaFigura = nullptr;
                switch (opcaoFig) {
                    case 1:
                        novaFigura = new Circulo();
                        break;
                    case 2:
                        novaFigura = new Quadrado();
                        break;
                    case 3:
                        novaFigura = new Triangulo();
                        break;
                }

                if (novaFigura) {
                    novaFigura->leia();
                    figuras[quantidade++] = novaFigura;
                }
                break;
            }
            case 2: {
                cout << "\nListando figuras:\n";
                for (int i = 0; i < quantidade; ++i) {
                    figuras[i]->escreva();
                }
                break;
            }
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

void menuPrincipal() {
    FigGeo* figuras[MAX];
    int quantidade = 0;
    int opcao;

    do {
        cout << "\nMenu Principal\n";
        cout << "0 - Sair\n1 - Círculo\n2 - Quadrado\n3 - Triângulo\nEscolha: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                break;
            case 1:
            case 2:
            case 3:
                menuFigGeo(figuras, quantidade, opcao);
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    for (int i = 0; i < quantidade; ++i) {
        delete figuras[i];
    }
}

int main() {
    apresentacao();
    menuPrincipal();
    return 0;
}