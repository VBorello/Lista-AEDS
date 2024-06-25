#include <iostream>
#include <sstream>3

using namespace std;

#define max 100

class Candidatos
{
    private:

        string nome;
        double nota;

    public:

        void setNome (string nome)
        {
            this->nome = nome;
        }
        void setNota(double nota)
        {
            this->nota = nota;
        }
        string getNome()
        {
            return this->nome;
        }
        double getNota()
        {
            return this->nota;
        }
        void leCandidato()
        {
            string linha;
            getline(cin, linha);
            stringstream ss(linha);
            ss >> nome >> nota;
            setNome(nome);
            setNota(nota);
        }
        void escrevaCandidatos()
        {
            cout << nome << " " << nota << endl;
        }
};

int main ()
{
    Candidatos* candidatos[max];
    int n;
    double soma = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        candidatos[i] = new Candidatos();
        candidatos[i]->leCandidato();
        soma += candidatos[i]->getNota();
    }
    double media = soma/(double)n;
    for (int i = 0; i <= n; i++)
    {
        if(candidatos[i]->getNota() > media) {
            candidatos[i]->escrevaCandidatos();
        }
    }
    return 0;
}