#include <iostream>
#include <string>

using namespace std;

#define MAX 100

void apresentacao(){
    cout << "\nClass Candidato\n" << endl;
}

class Candidato{

    private:
        string nome;
        int nota;

    public:
 
    Candidato() : nome(""), nota(0){}
    Candidato(string nome, int nota) : nome(nome), nota(nota) {}
    
    void setNome(string nome){
        this -> nome = nome; 
    }

    void setNota(int nota){
        this -> nota = nota; 
    }

    int getNota(){
        return nota;
    }

    string getNome(){
        return nome;
    }
};

int lerCandidatos(){
    
    int quantidade;
    do{
        cout << "\nDigite o numero de candidatos: ";
        cin >> quantidade;
    }while(quantidade <= 0 || quantidade >= MAX);

    return quantidade;
}

Candidato criarCandidato(){
    
    string nome;
    int nota;

    cout << "\nDigite o nome do candidato: ";
    cin.ignore();
    getline(cin, nome);

    cout << "\nDigite a nota do candidato: ";
    cin >> nota;


    return Candidato(nome, nota);
}

double calculaMediaDosCandidatos(Candidato canditados[], int n){
    
    double soma = 0;
    for(int i = 0; i < n; i++){
        soma += canditados[i].getNota();
    }

    return soma / n;
}

void listarAcimaDaMedia(Candidato canditados[], int n, double media){

    cout << "\nCandidatos com nota acima da media (" << media << "):" << endl;
    for(int i = 0; i < n; i++){
        if(canditados[i].getNota() > media){
            cout << "\nCandidato: " << canditados[i].getNome() << " Nota: " << canditados[i].getNota() << endl;
        }
    }
}

int main(){
    apresentacao();

    Candidato candidatos[MAX];

    int n = lerCandidatos();

    for(int i = 0; i < n; i++){
        cout << "\nCandidato " << (i + 1) << ":" << endl;
        candidatos[i] = criarCandidato();
    }

    double media = calculaMediaDosCandidatos(candidatos, n);
    listarAcimaDaMedia(candidatos, n, media);

    return 0;
}