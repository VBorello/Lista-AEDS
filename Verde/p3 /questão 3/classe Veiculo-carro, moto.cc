#include <iostream>
#include <string>

class Veiculo {
protected:
    std::string modelo;
    int ano;
    static int quantidade; 

public:
    Veiculo(std::string modelo, int ano) : modelo(modelo), ano(ano) {
        quantidade++;
    }

    virtual ~Veiculo() {
        quantidade--;
    }

    static int getQuantidade() {
        return quantidade;
    }

    virtual void escreve() = 0;

    std::string getModelo() {
        return modelo;
    }

    int getAno() {
        return ano;
    }
};

int Veiculo::quantidade = 0;
class Carro : public Veiculo {
private:
    std::string tracao;

public:
    Carro(std::string modelo, int ano, std::string tracao) : Veiculo(modelo, ano), tracao(tracao) {}

    Carro() : Veiculo("Desconhecido", 0), tracao("Desconhecida") {}

    void escreve() {
        std::cout << "Modelo: " << getModelo() << ", Ano: " << getAno() << ", Tracao: " << tracao << std::endl;
    }

    std::string getTracao() {
        return tracao;
    }
};

class Moto : public Veiculo {
private:
    int cilindradas;

public:
    Moto(std::string modelo, int ano, int cilindradas) : Veiculo(modelo, ano), cilindradas(cilindradas) {}

    Moto() : Veiculo("Desconhecido", 0), cilindradas(0) {}

    void escreve() {
        std::cout << "Modelo: " << getModelo() << ", Ano: " << getAno() << ", Cilindradas: " << cilindradas << std::endl;
    }

    int getCilindradas() {
        return cilindradas;
    }
};

void escreve(Veiculo* veiculo) {
    veiculo->escreve();
}

int main() {
    Veiculo* veiculos[4];
    veiculos[0] = new Carro("Gol", 2020, "dianteira");
    veiculos[1] = new Carro();
    veiculos[2] = new Moto();
    veiculos[3] = new Moto("XL125", 2019, 125);

    for (int i = 0; i < 4; i++) {
        escreve(veiculos[i]);
    }

    std::cout << std::endl << "Quantidade de veículos criados: " << Veiculo::getQuantidade() << std::endl;

    for (int i = 0; i < 4; i++) {
        delete veiculos[i];
    }

    return 0;
}
