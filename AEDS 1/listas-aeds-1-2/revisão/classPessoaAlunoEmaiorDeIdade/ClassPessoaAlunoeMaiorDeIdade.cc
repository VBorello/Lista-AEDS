#include <iostream>
#include <string>

using namespace std;


class Pessoa{
    
    protected:
        string nome;
        int idade;

    public:


        Pessoa(string nome = "", int idade = 0) : nome(nome), idade(idade) {}

        void setNome(string nome){
            this -> nome = nome;
        }

        void setIdade(int idade){
            this -> idade = idade;
        }

        string getNome(){
            return nome;
        }

        int getIdade(){
            return idade;
        }

        bool maiorDeIdade(){
            bool maior = true;
            if(idade < 18){
                maior = false;
            }
            return maior;
        }

        Pessoa maisVelha(Pessoa &idades){
            if(idade > idades.idade){
                return *this;
            }else{
                return idades;
            }
        }
};

class Aluno : public Pessoa{

    private:
        int matricula;

    public:

        Aluno(string nome, int idade, int matricula) : Pessoa(nome, idade), matricula(matricula) {}

        void setMatricula(int matricula){
            this -> matricula = matricula;
        }

        int getMatricula(){
            return matricula;
        }
};

int main(){
    
    Pessoa p1("Marcos", 18);

    cout << "\nNome: " << p1.getNome() << ", Idade: " << p1.getIdade() << ", Maior: " << (p1.maiorDeIdade() ? "sim" : "não") << endl;
    
    Aluno a1("Iara", 19, 833428);

    cout << "\nNome: " << a1.getNome() << ", Idade: " << a1.getIdade() << ", Maior: " << (a1.maiorDeIdade() ? "sim" : "não") << ", Matricula: " << a1.getMatricula() << endl;

    Pessoa maisVelha = p1.maisVelha(a1);
    
    cout << "\nA pessoa mais velha é: " << maisVelha.getNome() << ", Idade: " << maisVelha.getIdade() << endl;

    return 0;
}                           
