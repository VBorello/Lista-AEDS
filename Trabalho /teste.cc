#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

// Classe Data
class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    bool dataValida() {
        if (mes < 1 || mes > 12 || dia < 1 || dia > 31) return false;
        if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return false;
        if (mes == 2) {
            bool anoBissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
            if (dia > 29 || (dia == 29 && !anoBissexto)) return false;
        }
        return true;
    }

    void setData(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    void lerData() {
        cout << "Digite o dia: "; cin >> dia;
        cout << "Digite o mês: "; cin >> mes;
        cout << "Digite o ano: "; cin >> ano;
    }

    void escreverData() {
        cout << dia << "/" << mes << "/" << ano;
    }
};

// Classe Pessoa
class Pessoa {
protected:
    char nome[50];
    Data dataNascimento;

public:
    void setNome(const char* n) { strncpy(nome, n, 50); }
    const char* getNome() { return nome; }

    void lerNome() {
        cout << "Digite o nome: ";
        cin.ignore();
        cin.getline(nome, 50);
    }

    void escreverNome() {
        cout << nome;
    }

    void lerPessoa() {
        lerNome();
        cout << "Digite a data de nascimento:\n";
        dataNascimento.lerData();
    }

    virtual void escreverPessoa() {
        escreverNome();
        cout << " - Data de nascimento: ";
        dataNascimento.escreverData();
        cout << endl;
    }

    Data getDataNascimento() { return dataNascimento; }

    Pessoa() {}
    virtual ~Pessoa() {}
};

// Classe Aluno
class Aluno : public Pessoa {
private:
    int matricula;
    static int quantidade;

public:
    void setMatricula(int m) { matricula = m; }
    int getMatricula() { return matricula; }

    void lerAluno() {
        lerPessoa();
        cout << "Digite a matrícula: ";
        cin >> matricula;
    }

    void escreverPessoa() override {
        Pessoa::escreverPessoa();
        cout << " - Matrícula: " << matricula << endl;
    }

    Aluno() { quantidade++; }
    ~Aluno() { quantidade--; }
    static int getQuantidade() { return quantidade; }
};

int Aluno::quantidade = 0;

// Classe Professor
class Professor : public Pessoa {
private:
    char titulacao[20];
    static int quantidade;

public:
    void setTitulacao(const char* t) { strncpy(titulacao, t, 20); }
    const char* getTitulacao() { return titulacao; }

    void lerProfessor() {
        lerPessoa();
        cout << "Digite a titulação: ";
        cin.ignore();
        cin.getline(titulacao, 20);
    }

    void escreverPessoa() override {
        Pessoa::escreverPessoa();
        cout << " - Titulação: " << titulacao << endl;
    }

    Professor() { quantidade++; }
    ~Professor() { quantidade--; }
    static int getQuantidade() { return quantidade; }
};

int Professor::quantidade = 0;

#define _MAX 1000

void cadastrarPessoa(Pessoa* pessoas[], int& quantidade) {
    if (quantidade >= _MAX) {
        cout << "Limite de cadastros atingido!" << endl;
        return;
    }

    try {
        cout << "Cadastrar:\n1 - Aluno\n2 - Professor\nEscolha: ";
        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            pessoas[quantidade] = new Aluno();
            ((Aluno*)pessoas[quantidade])->lerAluno();
        } else if (opcao == 2) {
            pessoas[quantidade] = new Professor();
            ((Professor*)pessoas[quantidade])->lerProfessor();
        } else {
            cout << "Opção inválida!" << endl;
            return;
        }

        quantidade++;
    } catch (bad_alloc& ba) {
        cerr << "Falha ao alocar memória: " << ba.what() << endl;
    }
}

void listarPessoas(Pessoa* pessoas[], int quantidade) {
    for (int i = 0; i < quantidade; ++i) {
        pessoas[i]->escreverPessoa();
    }
}

void salvarDados(Pessoa* pessoas[], int quantidade) {
    FILE* outFile = fopen("dados.txt", "w");
    if (!outFile) {
        cerr << "Erro ao abrir arquivo para escrita." << endl;
        return;
    }
    
    fprintf(outFile, "%d\n", quantidade);
    for (int i = 0; i < quantidade; ++i) {
        Aluno* aluno = dynamic_cast<Aluno*>(pessoas[i]);
        if (aluno) {
            fprintf(outFile, "A %s %d %d %d %d\n", aluno->getNome(), aluno->getMatricula(), aluno->getDataNascimento().getDia(), aluno->getDataNascimento().getMes(), aluno->getDataNascimento().getAno());
        } else {
            Professor* professor = dynamic_cast<Professor*>(pessoas[i]);
            if (professor) {
                fprintf(outFile, "P %s %s %d %d %d\n", professor->getNome(), professor->getTitulacao(), professor->getDataNascimento().getDia(), professor->getDataNascimento().getMes(), professor->getDataNascimento().getAno());
            }
        }
    }
    fclose(outFile);
}

void carregarDados(Pessoa* pessoas[], int& quantidade) {
    FILE* inFile = fopen("dados.txt", "r");
    if (!inFile) return;

    fscanf(inFile, "%d\n", &quantidade);
    for (int i = 0; i < quantidade; ++i) {
        char tipo;
        fscanf(inFile, " %c", &tipo);
        if (tipo == 'A') {
            pessoas[i] = new Aluno();
            char nome[50];
            int matricula, dia, mes, ano;
            fscanf(inFile, "%s %d %d %d %d\n", nome, &matricula, &dia, &mes, &ano);
            pessoas[i]->setNome(nome);
            ((Aluno*)pessoas[i])->setMatricula(matricula);
            ((Aluno*)pessoas[i])->getDataNascimento().setData(dia, mes, ano);
        } else if (tipo == 'P') {
            pessoas[i] = new Professor();
            char nome[50], titulacao[20];
            int dia, mes, ano;
            fscanf(inFile, "%s %s %d %d %d\n", nome, titulacao, &dia, &mes, &ano);
            pessoas[i]->setNome(nome);
            ((Professor*)pessoas[i])->setTitulacao(titulacao);
            ((Professor*)pessoas[i])->getDataNascimento().setData(dia, mes, ano);
        }
    }
    fclose(inFile);
}

int main() {
    Pessoa* pessoas[_MAX];
    int quantidade = 0;

    carregarDados(pessoas, quantidade);

    int opcao;

    do {
        cout << "Menu:\n0 - Sair\n1 - Cadastrar uma pessoa\n2 - Listar pessoas\nEscolha: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                break;
            case 1:
                cadastrarPessoa(pessoas, quantidade);
                break;
            case 2:
                listarPessoas(pessoas, quantidade);
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    salvarDados(pessoas, quantidade);

    for (int i = 0; i < quantidade; ++i) {
        delete pessoas[i];
    }

    return 0;
}
