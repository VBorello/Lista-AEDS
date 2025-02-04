#include <iostream>

#define MAX 100

using namespace std;

class Time{

    protected:
        
        string nome;
        int titulos;

    public:

        static int quantidade;

        Time() : nome(""), titulos(0){
            quantidade++;
        }

        Time(string nome, int titulos) : nome(nome), titulos(titulos){
            quantidade++;
        }

        virtual ~Time(){
            quantidade--;
        }

        void setNome(string nome){
            this -> nome = nome; 
        }

        void setTitulos(int titulos){
            this -> titulos = titulos; 
        }

        string getNome(){
            return nome;
        }

        int getTitulos(){
            return titulos;
        }

        virtual void escreve() const = 0;

        static int getQuantidade(){
            return quantidade;
        }
};

int Time::quantidade = 0;

class Jogadores : public Time{

    private:

        int numero;
        string posicao;
        
    
    public:

        Jogadores(int numero, string posicao, string nome, int titulos = 0) : Time(nome, titulos), numero(numero), posicao(posicao){} 

        void setPosicao(string posicao){
            this -> posicao = posicao;
        }

        string getPosicao(){
            return posicao;
        }

        void setNumero(int numero){
            this -> numero = numero;
        }

        int getNumero(){
            return numero;
        }

        void escreve() const override{
            cout << "\nJogador: Nome: " << nome
            << ", Posicao: " << posicao
            << ", Numero: " << numero
            << ", Titulos: " << titulos
            << endl;
        }

};

Time** criarTimes(int& quantidade){

    cout << "\nDigite a quantidade de Jogadores: ";
    cin >> quantidade;

    if(quantidade <= 0 || quantidade > MAX){    
        cout << "\nQuantidade inválida";
        quantidade = 1;
    }

    Time** times = new Time*[quantidade];

    for(int i = 0; i < quantidade; i++){
        cout << "\nJogador " << i + 1 << ":" << endl;

        string nome;
        cout << "\nDigite o nome do jogador: ";
        cin.ignore();
        getline(cin, nome);
        
        string posicao;
        cout << "\nDigite a posição do jogador: ";
        cin.ignore();
        getline(cin, posicao);

        int numero;
        cout << "\nDigite o numero do jogador: ";
        cin >> numero;

        int titulos;
        cout << "\nDigite quantos titulos o jogador tem: ";
        cin >> titulos;

        times[i] = new Jogadores(numero, posicao, nome, titulos);
    }

    return times;
}

void listarTimes(Time** times, int quantidade){
    
    for(int i = 0; i < quantidade; i++){
        times[i]->escreve();
    }
}

void liberarMemoria(Time** times, int quantidade) {
   
    for (int i = 0; i < quantidade; i++) {
        delete times[i];
    }
    delete[] times;
}

int main() {

    int quantidade;
    Time** times = criarTimes(quantidade);

    cout << "\n--- Lista de Jogadores ---\n";
    listarTimes(times, quantidade);

    cout << "\nQuantidade de instancias de Time criadas: " << Time::getQuantidade() << endl;

    liberarMemoria(times, quantidade);

    return 0;
}
