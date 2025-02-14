#include <iostream>

using namespace std;

class Bota{

    private:

        int tamanho;
        char lado;
        

    public:

        Bota(){}
        Bota(int tamanho, char lado) : tamanho(tamanho), lado(lado){}

        int getTamanho(){
            return tamanho;
        }

        char getLado(){
            return lado;
        }

        void setTamanho(int tamanho) {
            this -> tamanho = tamanho;
        }
    
        void setLado(char lado) {
            this -> lado = lado;
        }

        bool formarPar(Bota pe){
            return (this -> tamanho == pe.getTamanho()) &&
            ((this -> lado == 'D' && pe.getLado() == 'E') ||
            (this -> lado == 'E' && pe.getLado() == 'D'));
        }

};


int main(){

    int quantidadeBotas;
    cin >> quantidadeBotas;
    
    Bota botas[10000];
    int pares = 0;
    int total = 0;

    for(int i = 0; i < quantidadeBotas; i++){
        int tamanho;
        char lado;
        cin >> tamanho >> lado;

        if(lado != 'D' && lado != 'E'){
            return 1;
        }
    
        Bota pe2(tamanho, lado);
        int ePar = -1;
        
        for(int j = 0; j < total; j++){
            if(pe2.formarPar(botas[j])){
                ePar = j;
                j = total;//parar
            }
        }

        if(ePar != -1){
            for(int j = ePar; j < total - 1; j++){
                botas[j] = botas[j + 1];
            }

            total--;
            pares++;
        }
        else{
            botas[total].setTamanho(tamanho);
            botas[total].setLado(lado);
            total++;
        }
    }

    cout << pares << endl;

    return 0;
}