#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#define max 1000

class Data
{
private:
    int dia;
    int mes; 
    int ano;
        
public:
    Data() : dia(0), mes(0), ano(0) {} //construtor inicializa a data como 0/0/0
    Data(int dia, int mes, int ano) {  //Construtor 
        this -> dia = dia;
        this -> mes = mes;
        this -> ano = ano;
    }
    //para definir
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    bool validarData();
    bool ehBissexto();
    //para retornar
    int getDia();
    int getMes();
    int getAno();
    //ler e imprimir
    void lerData();
    void printData();
};

void Data::setDia(int dia){
    this -> dia = dia;
}

void Data::setMes(int mes){
    this -> mes = mes;
}

void Data::setAno(int ano){
    this -> ano = ano;
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

bool Data::ehBissexto(){
    if ((this->ano % 4 == 0 && this -> ano % 100 != 0) || (this->ano % 400 == 0)) {
        return true;
    }
    return false;
}

bool Data::validarData(){
    bool dataValida = true;

    if(this->dia < 1 || this -> dia > 31 || this -> mes < 1 || this -> mes > 12 || this -> ano < 0 ||
       (this -> mes == 2 && ((this->ehBissexto() && this -> dia > 29) || (!this -> ehBissexto() && this -> dia > 28))) || 
       (this -> mes == 4 && this -> dia > 30) || 
       (this -> mes == 6 && this -> dia > 30) || 
       (this -> mes == 9 && this -> dia > 30) || 
       (this -> mes == 11 && this -> dia > 30)){
        dataValida = false;
        cout << "Data invalida." << endl;
    }
    return dataValida;
}

void Data::lerData(){
    int dia, mes, ano;
    do {
        cout << "Digite a data (dia mes ano): ";
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        ss >> dia >> mes >> ano;

        this->setDia(dia);
        this->setMes(mes);
        this->setAno(ano);

    } while(!this -> validarData());
}

void Data::printData(){ 
    cout << this -> dia << "/" << this -> mes << "/" << this -> ano << endl;
}

class Pessoa
{
private:
    string nome;
    Data nascimento;
    static int qtd; //contador de pessoa static(para todas as funções terem acesso)

public:
    static int getQtd(){
        return qtd;
    }

    Pessoa(){
        this -> nascimento = Data();
        qtd++;
    }

    void setNome(string nome);

    string getNome();

    void lerNome();
    void printNome();
    void lerPessoa();
    void printPessoa();

    Data getDataNascimento() {
        return nascimento;
    }
};

int Pessoa::qtd = 0;

void Pessoa::setNome(string nome){
    this -> nome = nome;
}

string Pessoa::getNome(){
    return this -> nome;
}

void Pessoa::lerNome(){
    string nome;
    cout << "Digite um nome: ";
    cin.ignore();
    getline(cin, nome);

    setNome(nome);
}

void Pessoa::printNome(){
    cout << this -> nome << endl;
}

void Pessoa::lerPessoa(){
    lerNome();
    nascimento.lerData();
}

void Pessoa::printPessoa(){
    printNome();
    nascimento.printData();
}

class Aluno: public Pessoa{    
private:
    string matricula; 
    static int qtd;

public:
    Aluno(){
        qtd++;
    }

    virtual ~Aluno(){
        qtd--;
    }

    void setMatricula(string matricula){
        this -> matricula = matricula;
    }

    string getMatricula(){
        return matricula;        
    }

    void lerAluno() {
        lerPessoa();
        string matricula;
        cout << "Digite a matricula: ";
        cin >> matricula;
        setMatricula(matricula);
    }

    void printAluno() {
        printPessoa();
        cout << "Matricula: " << matricula << endl;
    }

    static int getQtdAlunos() {
        return qtd;
    }
};

int Aluno::qtd = 0;

class Professor: public Pessoa{
private:
    string titulacao;
    static int qtd;

public:
    Professor(){
        qtd++;
    }

    virtual ~Professor(){
        qtd--;
    }

    void setTitulacao(string titulacao){
        this -> titulacao = titulacao;
    }

    string getTitulacao(){
        return titulacao;
    }

    void lerProfessor() {
        lerPessoa();
        cout << "Digite a titulação: ";
        cin.ignore();
        getline(cin, titulacao);
    }

    void printProfessor() {
        printPessoa();
        cout << "Titulação: " << titulacao << endl;
    }

    static int getQtdProfessores() {
        return qtd;
    }
};

int Professor::qtd = 0;

void listarAniversariantes(Pessoa* pessoas[], int qtdPessoas, int mes) {
    for (int i = 0; i < qtdPessoas; ++i) {
        if (pessoas[i]->getDataNascimento().getMes() == mes) {
            if (pessoas[i]->getDataNascimento().validarData()) {
                pessoas[i]->printPessoa();
            } else {
                cout << "Data invalida" << pessoas[i]->getNome() << ".\n";
            }
        }
    }
}

void menu(Pessoa* pessoas[], Aluno* alunos[], Professor* professores[]) {
    int opcao;
    do {
        cout << "\nMenu de Opcoes:\n";
        cout << "0 – Sair\n";
        cout << "1 – Cadastrar aluno\n";
        cout << "2 – Cadastrar professor\n";
        cout << "3 – Listar alunos\n";
        cout << "4 – Listar professores\n";
        cout << "5 – Listar todos os aniversariantes do mes\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "fim\n";
                break;
            case 1: {
                
                if (Aluno::getQtdAlunos() < max) {
                    Aluno* aluno = new Aluno();
                    aluno -> lerAluno();
                    alunos[Aluno::getQtdAlunos() - 1] = aluno;
                    pessoas[Pessoa::getQtd() - 1] = aluno;
                } else {
                    cout << "Numero maximo de cadastros atingido\n";
                }
                break;

            }
            case 2: {

                if (Professor::getQtdProfessores() < max) {
                    Professor* professor = new Professor();
                    professor -> lerProfessor();
                    professores[Professor::getQtdProfessores() - 1] = professor;
                    pessoas[Pessoa::getQtd() - 1] = professor;
                } else {
                    cout << "Numero maximo de cadastros atingido\n";
                }
                break;

            }
            case 3:

                for (int i = 0; i < Aluno::getQtdAlunos(); ++i) {
                    alunos[i]->printAluno();
                }
                break;

            case 4:

                for (int i = 0; i < Professor::getQtdProfessores(); ++i) {
                    professores[i]->printProfessor();
                }
                break;

            case 5: {
                int mes;
                cout << "Digite o mes: ";
                cin >> mes;
                listarAniversariantes(pessoas, Pessoa::getQtd(), mes);
                break;
            }
            default:
                cout << "Opcao invalida.\n";
                break;
        }
    } while (opcao != 0);
}

int main(){
    Pessoa* pessoas[max];
    Aluno* alunos[max];
    Professor* professores[max];

    menu(pessoas, alunos, professores);

    for (int i = 0; i < Pessoa::getQtd(); ++i) {
        delete pessoas[i];
    }

    return 0;
}
