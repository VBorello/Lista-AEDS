#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <vector>

#define max 1000

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data() : dia(0), mes(0), ano(0) {}
    Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

    void setDia(int dia) { this->dia = dia; }
    void setMes(int mes) { this->mes = mes; }
    void setAno(int ano) { this->ano = ano; }
    bool validarData();
    bool bissexto();

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    void lerData();
    void printData();
};

bool Data::bissexto() {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool Data::validarData() {
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1 ||
        (mes == 2 && ((bissexto() && dia > 29) || (!bissexto() && dia > 28))) ||
        (mes == 4 && dia > 30) || (mes == 6 && dia > 30) ||
        (mes == 9 && dia > 30) || (mes == 11 && dia > 30)) {
        std::cout << "Data invalida." << std::endl;
        return false;
    }
    return true;
}

void Data::lerData() {
    int dia, mes, ano;
    do {
        std::cout << "Digite a data (dia mes ano): ";
        std::string input;
        std::cin.ignore();
        getline(std::cin, input);
        std::stringstream ss(input);
        ss >> dia >> mes >> ano;

        setDia(dia);
        setMes(mes);
        setAno(ano);

    } while (!validarData());
}

void Data::printData() {
    std::cout << dia << "/" << mes << "/" << ano << std::endl;
}

class Pessoa {
private:
    std::string nome;
    Data nascimento;
    static int qtd;

public:
    static int getQtd() { return qtd; }

    Pessoa() { qtd++; }

    void setNome(std::string nome) { this->nome = nome; }
    std::string getNome() { return nome; }
    void lerNome();
    void printNome();
    void lerPessoa();
    void printPessoa();
    virtual void escrevaPessoa();
    Data getDataNascimento() { return nascimento; }
};

int Pessoa::qtd = 0;

void Pessoa::lerNome() {
    std::string nome;
    std::cout << "Digite um nome: ";
    std::cin.ignore();
    getline(std::cin, nome);
    setNome(nome);
}

void Pessoa::printNome() {
    std::cout << nome << std::endl;
}

void Pessoa::lerPessoa() {
    lerNome();
    nascimento.lerData();
}

void Pessoa::printPessoa() {
    printNome();
    nascimento.printData();
}

void Pessoa::escrevaPessoa() {
    std::cout << "Nome: " << nome << "\nData de Nascimento: ";
    nascimento.printData();
}

class Aluno : public Pessoa {
private:
    std::string matricula;
    static int qtd;

public:
    Aluno() { qtd++; }
    virtual ~Aluno() { qtd--; }

    void setMatricula(std::string matricula) { this->matricula = matricula; }
    std::string getMatricula() { return matricula; }

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

    static int getQtdAlunos() { return qtd; }
};

int Aluno::qtd = 0;

class Professor : public Pessoa {
private:
    std::string titulacao;
    static int qtd;

public:
    Professor() { qtd++; }
    virtual ~Professor() { qtd--; }

    void setTitulacao(std::string titulacao) { this->titulacao = titulacao; }
    std::string getTitulacao() { return titulacao; }

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

    static int getQtdProfessores() { return qtd; }
};

int Professor::qtd = 0;

void listarAniversariantes(Pessoa* pessoas[], int qtdPessoas, int mes) {
    for (int i = 0; i < qtdPessoas; ++i) {
        if (pessoas[i]->getDataNascimento().getMes() == mes) {
            if (pessoas[i]->getDataNascimento().validarData()) {
                pessoas[i]->escrevaPessoa();
            } else {
                std::cout << "Data invalida " << pessoas[i]->getNome() << ".\n";
            }
        }
    }
}

void salvarDados(std::vector<Pessoa*>& pessoas, std::vector<Aluno*>& alunos, std::vector<Professor*>& professores) {
    std::ofstream arq("Cadastros.txt");
    if (!arq) {
        std::cerr << "Erro ao abrir arquivo";
        return;
    }

    arq << Pessoa::getQtd() << std::endl;
    arq << Aluno::getQtdAlunos() << std::endl;
    arq << Professor::getQtdProfessores() << std::endl;

    for (auto aluno : alunos) {
        arq << "A " << aluno->getNome() << " " << aluno->getDataNascimento().getDia() << " "
            << aluno->getDataNascimento().getMes() << " " << aluno->getDataNascimento().getAno() << " "
            << aluno->getMatricula() << std::endl;
    }

    for (auto professor : professores) {
        arq << "P " << professor->getNome() << " " << professor->getDataNascimento().getDia() << " "
            << professor->getDataNascimento().getMes() << " " << professor->getDataNascimento().getAno() << " "
            << professor->getTitulacao() << std::endl;
    }
}

void lerDados(std::vector<Pessoa*>& pessoas, std::vector<Aluno*>& alunos, std::vector<Professor*>& professores) {
    std::ifstream arq("Cadastros.txt");
    if (!arq) {
        std::cerr << "Erro ao abrir arquivo";
        return;
    }

    int qtdPessoas, qtdAlunos, qtdProfessores;
    arq >> qtdPessoas >> qtdAlunos >> qtdProfessores;

    Pessoa::qtd = qtdPessoas;
    Aluno::qtd = qtdAlunos;
    Professor::qtd = qtdProfessores;

    for (int i = 0; i < qtdAlunos; ++i) {
        std::string nome, matricula;
        int dia, mes, ano;
        arq >> nome >> dia >> mes >> ano >> matricula;

        Aluno* aluno = new Aluno();
        aluno->setNome(nome);
        aluno->getDataNascimento().setDia(dia);
        aluno->getDataNascimento().setMes(mes);
        aluno->getDataNascimento().setAno(ano);
        aluno->setMatricula(matricula);

        alunos.push_back(aluno);
        pessoas.push_back(aluno);
    }

    for (int i = 0; i < qtdProfessores; ++i) {
        std::string nome, titulacao;
        int dia, mes, ano;
        arq >> nome >> dia >> mes >> ano >> titulacao;

        Professor* professor = new Professor();
        professor->setNome(nome);
        professor->getDataNascimento().setDia(dia);
        professor->getDataNascimento().setMes(mes);
        professor->getDataNascimento().setAno(ano);
        professor->setTitulacao(titulacao);

        professores.push_back(professor);
        pessoas.push_back(professor);
    }
}

void editarAluno(std::vector<Aluno*>& alunos) {
    std::string matricula;
    std::cout << "Digite a matricula do aluno a ser editado: ";
    std::cin >> matricula;

    for (auto aluno : alunos) {
        if (aluno->getMatricula() == matricula) {
            aluno->lerAluno();
            return;
        }
    }
    std::cout << "Aluno nao encontrado." << std::endl;
}

void editarProfessor(std::vector<Professor*>& professores) {
    std::string nome;
    std::cout << "Digite o nome do professor a ser editado: ";
    std::cin.ignore();
    getline(std::cin, nome);

    for (auto professor : professores) {
        if (professor->getNome() == nome) {
            professor->lerProfessor();
            return;
        }
    }
    std::cout << "Professor nao encontrado." << std::endl;
}

void excluirAluno(std::vector<Pessoa*>& pessoas, std::vector<Aluno*>& alunos) {
    std::string matricula;
    std::cout << "Digite a matricula do aluno a ser excluido: ";
    std::cin >> matricula;

    for (auto it = alunos.begin(); it != alunos.end(); ++it) {
        if ((*it)->getMatricula() == matricula) {
            pessoas.erase(std::remove(pessoas.begin(), pessoas.end(), *it), pessoas.end());
            delete *it;
            alunos.erase(it);
            return;
        }
    }
    std::cout << "Aluno nao encontrado." << std::endl;
}

void excluirProfessor(std::vector<Pessoa*>& pessoas, std::vector<Professor*>& professores) {
    std::string nome;
    std::cout << "Digite o nome do professor a ser excluido: ";
    std::cin.ignore();
    getline(std::cin, nome);

    for (auto it = professores.begin(); it != professores.end(); ++it) {
        if ((*it)->getNome() == nome) {
            pessoas.erase(std::remove(pessoas.begin(), pessoas.end(), *it), pessoas.end());
            delete *it;
            professores.erase(it);
            return;
        }
    }
    std::cout << "Professor nao encontrado." << std::endl;
}

int main() {
    std::vector<Pessoa*> pessoas;
    std::vector<Aluno*> alunos;
    std::vector<Professor*> professores;

    int op;

    do {
        std::cout << "1 - Cadastrar Aluno\n2 - Cadastrar Professor\n3 - Editar Aluno\n4 - Editar Professor\n5 - Excluir Aluno\n6 - Excluir Professor\n7 - Listar Aniversariantes do Mes\n8 - Salvar Dados\n9 - Ler Dados\n0 - Sair\n";
        std::cin >> op;

        switch (op) {
        case 1: {
            Aluno* aluno = new Aluno();
            aluno->lerAluno();
            alunos.push_back(aluno);
            pessoas.push_back(aluno);
            break;
        }
        case 2: {
            Professor* professor = new Professor();
            professor->lerProfessor();
            professores.push_back(professor);
            pessoas.push_back(professor);
            break;
        }
        case 3:
            editarAluno(alunos);
            break;
        case 4:
            editarProfessor(professores);
            break;
        case 5:
            excluirAluno(pessoas, alunos);
            break;
        case 6:
            excluirProfessor(pessoas, professores);
            break;
        case 7: {
            int mes;
            std::cout << "Digite o mes (1-12): ";
            std::cin >> mes;
            listarAniversariantes(pessoas, Pessoa::getQtd(), mes);
            break;
        }
        case 8:
            salvarDados(pessoas, alunos, professores);
            break;
        case 9:
            lerDados(pessoas, alunos, professores);
            break;
        case 0:
            break;
        default:
            std::cout << "Opcao invalida." << std::endl;
        }
    } while (op != 0);

    for (auto pessoa : pessoas) {
        delete pessoa;
    }

    return 0;
}
