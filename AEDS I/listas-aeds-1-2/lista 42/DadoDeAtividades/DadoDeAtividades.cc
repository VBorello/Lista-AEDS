#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

void apresentacao(){
    cout << "\nDado sorteador de atividades\n\n";
}

class Dado{
    
    private:
        string nome;

    public:

        Dado() {}
        Dado(string nome){
            setNome(nome);
        }

        string getNome(){
            return this -> nome;
        }

        void setNome(string nome){
            this -> nome = nome;
        }
    
};

int sortear(){
    
    srand(time(0));
    return rand() %6 + 1;

}

int main(){
    apresentacao();

    Dado atividades[6] = {

        Dado("brincar"),
        Dado("jogar"),
        Dado("dançar"),
        Dado("trabalhar"),
        Dado("estudar"),
        Dado("cantar"),
    
    };

    int numero = sortear();

    cout << "Você fará: " << atividades[numero].getNome() << endl;
    
    return 0;
}
