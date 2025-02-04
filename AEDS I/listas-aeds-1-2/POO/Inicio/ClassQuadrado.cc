#include <iostream>

using namespace std;

#define VETMAX 10

void apresentacao(){
    cout << "\nClass Vetor de Quadrados\n\n";
}

class Quadrado{

    private:
        double lado;
    
    public:

        Quadrado() : lado(0){}

        Quadrado(double l){
            setLado(l);
        }

        void setLado(double l){
            if(l >= 0){
                lado = l;
            }
            else{
                cout << "\nLado inpossivel de ser negativo";
            }
        }

        double getLado(){
            return lado;
        }

        double getArea(){
            return lado * lado;
        }

        double getPerimetro(){
            return lado * 4;
        }

        void ler(){
            double l;
            cout << "\nDigite o valor do lado do quadrado: ";
            cin >> l;

            setLado(l);
        }

        void escrever(){
            cout << "lado: " << lado << endl;
        }

};

void pegarTam(int *tam){
    
    bool erro;
    
    do{
        
        cout << "\nDigite o tamanho do vetor de quadrados: ";
        cin >> *tam;

        erro = (*tam < 0 && *tam <= VETMAX);
        if(erro){
            cout << "valor inválido";
        }

    }while(erro);
}

void criarVetor(int tam){

    Quadrado *vetor = new Quadrado[tam];

    for(int i = 0; i < tam; i++){
        cout << "\nQuadrado " << i + 1 << ":\n";
        vetor[i].ler(); 
    }

    cout << "\nElementos do vetor: \n";
    for(int i = 0; i < tam; i++){
        cout << "\nQuadrado" << i + 1 << "\n";
        vetor[i].escrever();
        cout << "Perimetro: " << vetor[i].getPerimetro() << endl;
        cout << "Área: " << vetor[i].getArea() << endl;
    }

    delete[] vetor;

}

int main(){
    apresentacao();

    int tamanho;
    pegarTam(&tamanho);

    criarVetor(tamanho);

    return 0;
}