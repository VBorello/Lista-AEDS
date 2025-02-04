#include <iostream>
#include <string>

#define MAX 100

using namespace std;

class Veiculo{

    protected:
        string modelo;
        int ano;

    public:

        static int quantidade;
        Veiculo(string modelo, int ano) : modelo(modelo), ano(ano){
            quantidade++;
        }

        virtual ~Veiculo(){
            quantidade--;
        }

        void setModelo(string modelo){
            this -> modelo = modelo;
        }

        void setAno(int ano){
            this -> ano = ano;
        }

        string getModelo(){
            return modelo;
        }

        int getAno(){
            return ano;
        }

        virtual void escreve() const = 0;
        
        static int getQuantidade(){
            return quantidade;
        }
};

int Veiculo::quantidade = 0;

class Carro : public Veiculo{

    private:
        string tracao;
    
    public:
        
        Carro(string modelo, int ano, string tracao) : Veiculo(modelo, ano), tracao(tracao) {}

        void setTracao(string tracao){
            this -> tracao = tracao;
        }

        string getTracao(){
            return tracao;
        }

        void escreve()const override{
            cout << "\nCarro: Modelo: " << modelo << ", Ano: " << ano << ", tracao: " << tracao << endl;      
        }
};

class Moto : public Veiculo{

    private:
        int cilindradas;
    
    public :

        Moto(string modelo, int ano, int cilindradas) : Veiculo(modelo, ano), cilindradas(cilindradas){}

        void setCilindradas(int cilindradas){
            this -> cilindradas = cilindradas;
        }

        int getCilindradas(){
            return cilindradas;
        }

        void escreve() const override{
            cout << "\nMoto: Modelo: " << modelo << ", Ano: " << ano << ", cilindradas: " << cilindradas << endl;
        }
        
};

Veiculo** criarVeiculo(int& quantidade){

    cout << "\nDigite a quantidade de veiculos: ";
    cin >> quantidade;

    if(quantidade <= 0 || quantidade > MAX){
        cout << "\nQuantidade inválida";
        quantidade = 1;
    }

    Veiculo** veiculos = new Veiculo*[quantidade];

    for(int i = 0; i < quantidade; i++){
        
        int opcao;
        do{
            cout << "\n1- Carro\n2- Moto\n: ";
            cin >> opcao; 
        }while(opcao != 1 && opcao !=2);

        if(opcao == 1){
            string modelo;
            cout << "\nCarro: Digite o Modelo: ";
            cin.ignore();
            getline(cin, modelo);

            int ano;
            cout << "Digite o ano: ";
            cin >> ano;

            string tracao;
            cout << "\nDigite a Tração: ";
            cin.ignore();
            getline(cin, tracao);

            veiculos[i] = new Carro(modelo, ano, tracao);
        }
        else if(opcao == 2){
            string modelo;
            cout << "\nMoto: Digite o Modelo: ";
            cin.ignore();
            getline(cin, modelo);

            int ano;
            cout << "Digite o ano: ";
            cin >> ano;

            int cilindradas;
            cout << "\nDigite quantas são as cilindradas: ";
            cin >> cilindradas;


        veiculos[i] = new Moto(modelo, ano, cilindradas);
        }
    }

    return veiculos;
}

void listarVeiculos(Veiculo** veiculos, int quantidade){
    
    for(int i = 0; i < quantidade; i++){
        veiculos[i]->escreve();
    }
}

void liberarMemoria(Veiculo** veiculos, int quantidade) {
   
    for (int i = 0; i < quantidade; i++) {
        delete veiculos[i];
    }
    delete[] veiculos;
}

int main() {

    int quantidade;
    Veiculo** veiculos = criarVeiculo(quantidade);

    cout << "\n--- Lista de Jogadores ---\n";
    listarVeiculos(veiculos, quantidade);

    cout << "\nQuantidade de instancias de Veiculos criadas: " << Veiculo::getQuantidade() << endl;

    liberarMemoria(veiculos, quantidade);

    return 0;
}




