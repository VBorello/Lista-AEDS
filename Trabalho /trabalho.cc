#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>

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
    bool bissexto();
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

bool Data::bissexto(){
    if ((this -> ano % 4 == 0 && this -> ano % 100 != 0) || (this -> ano % 400 == 0)) {
        return true;
    }
    return false;
}

bool Data::validarData(){
    bool dataValida = true;

    if(this -> dia < 1 || this -> dia > 31 || this -> mes < 1 || this -> mes > 12 || this -> ano < 1 ||
        (this -> mes == 2 && ((this -> bissexto() && this -> dia > 29) || (!this -> bissexto() && this -> dia > 28))) || 
        (this -> mes == 4 && this -> dia > 30) || 
        (this -> mes == 6 && this -> dia > 30) || 
        (this -> mes == 9 && this -> dia > 30) || 
        (this -> mes == 11 && this -> dia > 30)){
        dataValida = false;
        std::cout << "Data invalida." << std::endl;
    }
    return dataValida;
}

void Data::lerData(){
    int dia, mes, ano;
    do {
        std::cout << "Digite a data (dia mes ano): ";
        std::string input;
        std::cin.ignore(); //limpar o buffer
        getline(std::cin, input); //lê a linha inteira até o enter
        std::stringstream ss(input); //para poder utilizar a string de maneira mais fácil com operadores de fluxo(<< e >>)
        ss >> dia >> mes >> ano;

        this -> setDia(dia);
        this -> setMes(mes);
        this -> setAno(ano);

    } while(!this -> validarData());
}

void Data::printData(){ 
    std::cout << this -> dia << "/" << this -> mes << "/" << this -> ano << std::endl;
}

class Pessoa
{
private:
    std::string nome;
    Data nascimento;
    static int qtd; //contador de pessoa static(para possuir um escopo global)

public:
    static int getQtd(){
        return qtd;
    }

    Pessoa(){
        this -> nascimento = Data();
        qtd++;
    }

    void setNome(std::string nome);

    std::string getNome();

    void lerNome();
    void printNome();
    void lerPessoa();
    void printPessoa();
    
    virtual void escrevaPessoa();

    Data getDataNascimento() {
        return nascimento;
    }
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
    std::cin.ignore();
    getline(std::cin, nome);

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

void Pessoa::escrevaPessoa(){
    std::cout << "Nome: " << nome << "\nData de Nascimento: ";
    nascimento.printData();
}

class Aluno: public Pessoa{    
private:
    std::string matricula; 
    static int qtd;

public:
    Aluno(){
        qtd++;
    }

    virtual ~Aluno(){
        qtd--;
    }

    void setMatricula(std::string matricula){
        this -> matricula = matricula;
    }

    std::string getMatricula(){
        return matricula;        
    }

    void lerAluno() {
        lerPessoa();
        std::string matricula;
        std::cout << "Digite a matricula: ";
        std::cin >> matricula;
        setMatricula(matricula);
    }

    void printAluno() {
        printPessoa();
        std::cout << "Matricula: " << matricula << std::endl;
    }

    void escrevaPessoa() override {
        Pessoa::escrevaPessoa();
        std::cout << "Matricula: " << matricula << std::endl;
    }

    static int getQtdAlunos() {
        return qtd;
    }
};

int Aluno::qtd = 0;

class Professor: public Pessoa{
private:
    std::string titulacao;
    static int qtd;

public:
    Professor(){
        qtd++;
    }

    virtual ~Professor(){
        qtd--;
    }

    void setTitulacao(std::string titulacao){
        this -> titulacao = titulacao;
    }

    std::string getTitulacao(){
        return titulacao;
    }

    void lerProfessor() {
        lerPessoa();
        std::cout << "Digite a titulação: ";
        std::cin.ignore();
        getline(std::cin, titulacao);
    }

    void printProfessor() {
        printPessoa();
        std::cout << "Titulação: " << titulacao << std::endl;
    }

    void escrevaPessoa() override {
        Pessoa::escrevaPessoa();
        std::cout << "Titulação: " << titulacao << std::endl;
    }

    static int getQtdProfessores() {
        return qtd;
    }
};

int Professor::qtd = 0;

void listarAniversariantes(Pessoa* pessoas[], int qtdPessoas, int mes) {
    for (int i = 0; i < qtdPessoas; ++i) {
        if (pessoas[i] -> getDataNascimento().getMes() == mes) {
            if (pessoas[i] -> getDataNascimento().validarData()) {
                pessoas[i] -> escrevaPessoa();
            } else {
                std::cout << "Data invalida " << pessoas[i] -> getNome() << ".\n";
            }
        }
    }
}

void salvarDados(Pessoa* pessoas[], Aluno* alunos[], Professor* professores[]){
    FILE *arq = fopen("Cadastros.txt", "w");
    if(arq == NULL){
        std::cerr <<"erro ao abrir arquivo";
        return;
    }

    fprintf(arq, "%d %d\n", Aluno::getQtdAlunos(), Professor::getQtdProfessores());

    for(int i = 0; i < Aluno::getQtdAlunos(); i++){
        Aluno* aluno = alunos[i];
        fprintf(arq, "A %s %d %d %d %s\n", aluno -> getNome().c_str(), aluno -> getDataNascimento().getDia(),
            aluno -> getDataNascimento().getMes(), aluno -> getDataNascimento().getAno(), aluno -> getMatricula().c_str());
    }

    for(int i = 0; i < Professor::getQtdProfessores(); i++){
        Professor* professor = professores[i];
        fprintf(arq, "P %s %d %d %d %s\n", professor -> getNome().c_str(), professor -> getDataNascimento().getDia(),
            professor -> getDataNascimento().getMes(), professor -> getDataNascimento().getAno(), professor -> getTitulacao().c_str());
    }

    fclose(arq); 
}

void lerDados(Pessoa* pessoas[], Aluno* alunos[], Professor* professores[]){
    FILE *arq = fopen("Cadastros.txt", "r");
    if(arq == NULL){
        std::cerr <<"erro ao abrir arquivo";
        return;
    }

    int qtdAlunos, qtdProfessores;
    fscanf(arq, "%d %d", &qtdAlunos, &qtdProfessores);

    for(int i = 0; i < qtdAlunos; i++){
        Aluno* aluno = new Aluno();
        std::string nome, matricula;
        int dia, mes, ano;
        char buffer[100];

        fscanf(arq, " A %s %d %d %d %s", buffer, &dia, &mes, &ano, buffer);
        nome = buffer;
        matricula = buffer;

        aluno -> setNome(nome);
        aluno -> getDataNascimento().setDia(dia);
        aluno -> getDataNascimento().setMes(mes);
        aluno -> getDataNascimento().setAno(ano);
        aluno -> setMatricula(matricula);

        alunos[i] = aluno;
        pessoas[Pessoa::getQtd() - 1] = aluno;

        std::cout << aluno[1].getNome(), aluno[1].getDataNascimento(), aluno[1].getMatricula();
    }

    for(int i = 0; i < qtdProfessores; i++){
        Professor* professor = new Professor();
        std::string nome, titulacao;
        int dia, mes, ano;
        char buffer[100];

        fscanf(arq, " P %s %d %d %d %s", buffer, &dia, &mes, &ano, buffer);
        nome = buffer;
        titulacao = buffer;

        professor->setNome(nome);
        professor->getDataNascimento().setDia(dia);
        professor->getDataNascimento().setMes(mes);
        professor->getDataNascimento().setAno(ano);
        professor->setTitulacao(titulacao);

        professores[i] = professor;
        pessoas[Pessoa::getQtd() - 1] = professor;
    }

    fclose(arq);
}

void cadastro(Pessoa* pessoas[], Aluno* alunos[], Professor* professores[]){
    int opcao;
    do{
        std::cout <<"\n Menu de Cadastro:\n";
        std::cout <<"0 - Voltar ao Menu Principal\n";
        std::cout <<"1 - Cadastrar Aluno\n";
        std::cout <<"2 - Cadastrar Professor\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0:{
                return;

            }

            case 1:{
                if (Aluno::getQtdAlunos() < max) {
                    Aluno* aluno = new Aluno();
                    aluno -> lerAluno();
                    alunos[Aluno::getQtdAlunos() - 1] = aluno;
                    pessoas[Pessoa::getQtd() - 1] = aluno;
                } else {
                    std::cout << "Numero maximo de cadastros de alunos atingido\n";
                }

                break;
            }

            case 2:{
                if (Professor::getQtdProfessores() < max) {
                    Professor* professor = new Professor();
                    professor -> lerProfessor();
                    professores[Professor::getQtdProfessores() - 1] = professor;
                    pessoas[Pessoa::getQtd() - 1] = professor;
                } else {
                    std::cout << "Numero maximo de cadastros de professores atingido\n";
                }

                break;
            }                
        }
    } while (opcao != 0);
}

void listar(Pessoa* pessoas[], Aluno* alunos[], Professor* professores[]){
    int opcao;
    do{
        std::cout <<"Menu Listagem:\n";
        std::cout <<"0 - Voltar ao Menu Principal\n";
        std::cout <<"1 - Listar Alunos\n";
        std::cout <<"2 - Listar Professores\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0:{
                return;

            }

            case 1:{
                for (int i = 0; i < Aluno::getQtdAlunos(); ++i) {
                    alunos[i] -> printAluno();
                }

                break;
            }
        
            case 2:{
                for (int i = 0; i < Professor::getQtdProfessores(); ++i) {
                    professores[i] -> printProfessor();
                }

                break;
            }
        }
    }while (opcao != 0);
}

void menu(Pessoa* pessoas[], Aluno* alunos[], Professor* professores[]) {
    int opcao;
    do {
        std::cout << "\nMenu Principal:\n";
        std::cout << "0 – Sair\n";
        std::cout << "1 – Cadastrar aluno ou professor(a/p):\n";
        std::cout << "2 – Listar alunos ou professores(a/p):\n";
        std::cout << "3 - Alterar alunos ou professores(a/p):\n";
        std::cout << "4 - Excluir alunos ou profesorres(a/p):\n";
        std::cout << "5 – Listar todos os aniversariantes do mes\n";
        std::cout << "6 - salvar\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0: {
                salvarDados(pessoas, alunos, professores);
                std::cout << "fim\n";
                break;
            }   

            case 1: {
                cadastro(pessoas, alunos, professores);
                break;
            }

            case 2: {
                listar(pessoas, alunos, professores);
                break;
            }

            case 3: {
                // Implementar
                break;
            }

            case 4: {
                // Implementar
                break;
            }

            case 5: {
                int mes;
                std::cout << "Digite o mes: ";
                std::cin >> mes;
                listarAniversariantes(pessoas, Pessoa::getQtd(), mes);
                break;
            }

            case 6: {
                lerDados(pessoas, alunos, professores);
            
                break;
            }

            default:{
                std::cout << "Opcao invalida.\n";
                break;

            }
        }
    } while (opcao != 0);
}

int main(){
    Pessoa* pessoas[max];
    Aluno* alunos[max];
    Professor* professores[max];

    lerDados(pessoas, alunos, professores);
    menu(pessoas, alunos, professores);

    for (int i = 0; i < Pessoa::getQtd(); ++i) {
        delete pessoas[i];
    }

    return 0;
}
