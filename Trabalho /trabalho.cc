#include <string>
#include <iostream>
#include <exception>

#define max 1000

class Data
{
private:
    int dia;
    int mes; 
    int ano;
        
public:
    Data() : dia(0), mes(0), ano(0) {}
    Data(int dia, int mes, int ano) {
        this -> dia = dia;
        this -> mes = mes;
        this -> ano = ano;
    }

    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    bool validarData();
    int getDia();
    int getMes();
    int getAno();
    void lerData();
    void printData();
};

void Data::setDia(int dia){
    this->dia = dia;
}

void Data::setMes(int mes){
    this->mes = mes;
}

void Data::setAno(int ano){
    this->ano = ano;
}

int Data::getDia(){
    return this -> dia;
}

int Data::getMes(){
    return this -> mes;
}

int Data::getAno(){
    return this -> ano;
}

bool Data::validarData(){
    bool dataValida = true;
    if(this -> dia < 1 || this -> dia > 31 || this -> mes < 1 || this -> mes > 12 || this -> ano < 0 || (this->mes == 2 && this -> dia > 29) || (this -> mes == 4 && this->dia > 30) || (this -> mes == 6 && this->dia > 30) || (this -> mes == 9 && this -> dia > 30) || (this -> mes == 11 && this -> dia > 30)){
        
        dataValida = false;
    }
    return dataValida;
}

void Data::lerData(){
    int dia, mes, ano;
    do {
        std::cout << "Digite o dia: ";
        std::cin >> dia;

        std::cout << "Digite o mes: ";
        std::cin >> mes;

        std::cout << "Digite o ano: ";
        std::cin >> ano;

        this->setDia(dia);
        this->setMes(mes);
        this->setAno(ano);

    } while(!this->validarData());
}

void Data::printData(){ 
    std::cout << this -> dia << "/" << this -> mes << "/" << this -> ano << std::endl;
}

class Pessoa
{
private:
    std::string nome;
    Data nascimento;
    static int qtd;

public:
    static int getQtd(){
        return qtd;
    }

    Pessoa(){
        this->nascimento = Data();
        qtd++;
    }

    void setNome(std::string nome);
    std::string getNome();
    void lerNome();
    void printNome();
    void lerPessoa();
    void printPessoa();
};

int Pessoa::qtd = 0;

void Pessoa::setNome(std::string nome){
    this -> nome = nome;
}

std::string Pessoa::getNome(){
    return this -> nome;
}

void Pessoa::lerNome(){
    std::string nome;
    std::cout << "Digite um nome: ";
    std::getline(std::cin, nome);
    setNome(nome);
}

void Pessoa::printNome(){
    std::cout << this -> nome << std::endl;
}

void Pessoa::lerPessoa(){
    lerNome();
    nascimento.lerData();
}

void Pessoa::printPessoa(){
    printNome();
    nascimento.printData();
}

void cadastro(Pessoa* p[]){
    if(Pessoa::getQtd() < max){
        p[Pessoa::getQtd()] = new Pessoa();
        p[Pessoa::getQtd() - 1] -> lerPessoa();
    }
}

int main(){
    Pessoa pessoas[max];
    pessoas[0].lerPessoa();
    pessoas[0].printPessoa();

    return 0;
}
