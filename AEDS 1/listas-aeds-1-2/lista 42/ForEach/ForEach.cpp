#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

class Dias{
    
    private:
    
        string nome;

    public:

        //construtores
        Dias(){};
        
        Dias(string nome){
            setNome(nome);
        }

        //sets e gets
        string getNome(){
            return this -> nome;
        }

        void setNome(string nome){
            this -> nome = nome;
        }
};

int main(){

    Dias *vetor[7];
    vetor[0] = new Dias("Domingo");
    vetor[1] = new Dias("Segunda");
    vetor[2] = new Dias("Terça");
    vetor[3] = new Dias("Quarta");
    vetor[4] = new Dias("Quinta");
    vetor[5] = new Dias("Sexta");
    vetor[6] = new Dias("Sabado");


    for(Dias* dias :vetor){
        if(dias != nullptr){
            cout << dias -> getNome() << endl;
        }
        
    }

    for (int i = 0; i < 7; i++) {
        delete vetor[i];  //libera tudo
    }

    return 0;
}
