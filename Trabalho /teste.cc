#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

class Data {
private:
    int dia, mes, ano;

public:
    void setDia(int d) {
        dia = d;
    }

    void setMes(int m) {
        mes = m;
    }

    void setAno(int a) {
        ano = a;
    }

    int getDia() const {
        return dia;
    }

    int getMes() const {
        return mes;
    }

    int getAno() const {
        return ano;
    }

    void setData(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    void lerData() {
        char sep;
        std::cin >> dia >> sep >> mes >> sep >> ano;
    }

    bool dataValida() const {
        if (ano < 1 || mes < 1 || mes > 12 || dia < 1) return false;
        int diasPorMes[] = { 31, (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return dia <= diasPorMes[mes - 1];
    }
};

class Pessoa {
protected:
    enum Tipo { ALUNO, PROFESSOR };
    char nome[50];
    Data nascimento;
    Tipo tipo;
    static int qtd;

public:
    Pessoa() {
        qtd++;
    }

    virtual ~Pessoa() {
        qtd--;
    }

    void setNome(const std::string& n) {
        strncpy(nome, n.c_str(), 50);
    }

    std::string getNome() const {
        return std::string(nome);
    }

    void lerNome() {
        std::cin.ignore();
        std::cin.getline(nome, 50);
    }

    void escreverNome() const {
        std::cout << nome;
    }

    void lerPessoa() {
        lerNome();
        nascimento.lerData();
    }

    void escreverPessoa() const {
        escreverNome();
        std::cout << " - Data de Nascimento: " << nascimento.getDia() << "/" << nascimento.getMes() << "/" << nascimento.getAno() << "\n";
    }

    static int getQtd() {
        return qtd;
    }

    Data getNascimento() const {
        return nascimento;
    }

    virtual void lerDadosEspecificos() = 0;
    virtual void escreverDadosEspecificos() const = 0;
    virtual void salvarDadosEspecificos(FILE* file) const = 0;
};

int Pessoa::qtd = 0;

#define _MAX 1000

class Aluno : public Pessoa {
private:
    std::string matricula;
    static int qtd;

public:
    Aluno() {
        tipo = ALUNO;
        qtd++;
    }

    ~Aluno() {
        qtd--;
    }

    void setMatricula(const std::string& m) {
        matricula = m;
    }

    std::string getMatricula() const {
        return matricula;
    }

    void lerDadosEspecificos() override {
        std::cout << "Digite a matricula: ";
        std::cin >> matricula;
    }

    void escreverDadosEspecificos() const override {
        std::cout << " - Matricula: " << matricula << "\n";
    }

    void salvarDadosEspecificos(FILE* file) const override {
        fprintf(file, "A %s %s\n", getNome().c_str(), matricula.c_str());
    }

    static int getQtd() {
        return qtd;
    }

    void lerAluno() {
        lerPessoa();
        lerDadosEspecificos();
    }

    void escreverAluno() const {
        escreverPessoa();
        escreverDadosEspecificos();
    }
};

int Aluno::qtd = 0;

class Professor : public Pessoa {
private:
    std::string titulacao;
    static int qtd;

public:
    Professor() {
        tipo = PROFESSOR;
        qtd++;
    }

    ~Professor() {
        qtd--;
    }

    void setTitulacao(const std::string& t) {
        titulacao = t;
    }

    std::string getTitulacao() const {
        return titulacao;
    }

    void lerDadosEspecificos() override {
        std::cout << "Digite a titulacao: ";
        std::cin >> titulacao;
    }

    void escreverDadosEspecificos() const override {
        std::cout << " - Titulacao: " << titulacao << "\n";
    }

    void salvarDadosEspecificos(FILE* file) const override {
        fprintf(file, "P %s %s\n", getNome().c_str(), titulacao.c_str());
    }

    static int getQtd() {
        return qtd;
    }

    void lerProfessor() {
        lerPessoa();
        lerDadosEspecificos();
    }

    void escreverProfessor() const {
        escreverPessoa();
        escreverDadosEspecificos();
    }
};

int Professor::qtd = 0;

void cadastrarPessoa(Pessoa* arr[], int& qtd, bool aluno) {
    if (qtd >= _MAX) {
        std::cerr << "Erro: Limite maximo de cadastros atingido.\n";
        return;
    }

    try {
        if (aluno) {
            arr[qtd] = new Aluno();
            static_cast<Aluno*>(arr[qtd])->lerAluno();
        } else {
            arr[qtd] = new Professor();
            static_cast<Professor*>(arr[qtd])->lerProfessor();
        }
        qtd++;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Erro ao alocar memoria: " << e.what() << "\n";
    }
}

void salvarDados(Pessoa* arr[], int qtd) {
    FILE* file = fopen("dados.txt", "w");
    if (file == nullptr) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return;
    }

    for (int i = 0; i < qtd; ++i) {
        arr[i]->salvarDadosEspecificos(file);
    }

    fclose(file);
}

void listarPessoas(Pessoa* arr[], int qtd, bool aluno) {
    for (int i = 0; i < qtd; ++i) {
        if ((aluno && arr[i]->tipo == Pessoa::ALUNO) || (!aluno && arr[i]->tipo == Pessoa::PROFESSOR)) {
            arr[i]->escreverPessoa();
            arr[i]->escreverDadosEspecificos();
        }
    }
}

void alterarPessoa(Pessoa* arr[], int qtd, bool aluno) {
    std::string nome;
    std::cout << "Digite o nome da pessoa que deseja alterar: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    for (int i = 0; i < qtd; ++i) {
        if ((aluno && arr[i]->tipo == Pessoa::ALUNO && arr[i]->getNome() == nome) || 
            (!aluno && arr[i]->tipo == Pessoa::PROFESSOR && arr[i]->getNome() == nome)) {
            arr[i]->lerPessoa();
            arr[i]->lerDadosEspecificos();
            return;
        }
    }
    std::cerr << "Pessoa não encontrada.\n";
}

void excluirPessoa(Pessoa* arr[], int& qtd, bool aluno) {
    std::string nome;
    std::cout << "Digite o nome da pessoa que deseja excluir: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    for (int i = 0; i < qtd; ++i) {
        if ((aluno && arr[i]->tipo == Pessoa::ALUNO && arr[i]->getNome() == nome) || 
            (!aluno && arr[i]->tipo == Pessoa::PROFESSOR && arr[i]->getNome() == nome)) {
            delete arr[i];
            for (int j = i; j < qtd - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            qtd--;
            return;
        }
    }
    std::cerr << "Pessoa não encontrada.\n";
}

void listarAniversariantes(Pessoa* arr[], int qtd, int mes) {
    for (int i = 0; i < qtd; ++i) {
        if (arr[i]->getNascimento().getMes() == mes) {
            arr[i]->escreverPessoa();
            arr[i]->escreverDadosEspecificos();
        }
    }
}

void menuCadastro(Pessoa* arr[], int& qtd) {
    int opcao;
    do {
        std::cout << "0 - Voltar ao menu principal\n1 - Cadastrar aluno\n2 - Cadastrar professor\nEscolha: ";
        std::cin >> opcao;
        if (opcao == 1) {
            cadastrarPessoa(arr, qtd, true);
        } else if (opcao == 2) {
            cadastrarPessoa(arr, qtd, false);
        }
    } while (opcao != 0);
}

void menuListar(Pessoa* arr[], int qtd) {
    int opcao;
    do {
        std::cout << "0 - Voltar ao menu principal\n1 - Listar alunos\n2 - Listar professores\nEscolha: ";
        std::cin >> opcao;
        if (opcao == 1) {
            listarPessoas(arr, qtd, true);
        } else if (opcao == 2) {
            listarPessoas(arr, qtd, false);
        }
    } while (opcao != 0);
}

void menuAlterar(Pessoa* arr[], int qtd) {
    int opcao;
    do {
        std::cout << "0 - Voltar ao menu principal\n1 - Alterar aluno\n2 - Alterar professor\nEscolha: ";
        std::cin >> opcao;
        if (opcao == 1) {
            alterarPessoa(arr, qtd, true);
        } else if (opcao == 2) {
            alterarPessoa(arr, qtd, false);
        }
    } while (opcao != 0);
}

void menuExcluir(Pessoa* arr[], int& qtd) {
    int opcao;
    do {
        std::cout << "0 - Voltar ao menu principal\n1 - Excluir aluno\n2 - Excluir professor\nEscolha: ";
        std::cin >> opcao;
        if (opcao == 1) {
            excluirPessoa(arr, qtd, true);
        } else if (opcao == 2) {
            excluirPessoa(arr, qtd, false);
        }
    } while (opcao != 0);
}

void menuPrincipal(Pessoa* arr[], int& qtd) {
    int opcao;
    do {
        std::cout << "0 - Sair\n1 - Cadastrar (A/P)\n2 - Listar (A/P)\n3 - Alterar (A/P)\n4 - Excluir (A/P)\n5 - Aniversariantes do mes\nEscolha: ";
        std::cin >> opcao;
        switch (opcao) {
        case 0:
            salvarDados(arr, qtd);
            break;
        case 1:
            menuCadastro(arr, qtd);
            break;
        case 2:
            menuListar(arr, qtd);
            break;
        case 3:
            menuAlterar(arr, qtd);
            break;
        case 4:
            menuExcluir(arr, qtd);
            break;
        case 5:
            int mes;
            std::cout << "Digite o mes: ";
            std::cin >> mes;
            listarAniversariantes(arr, qtd, mes);
            break;
        default:
            std::cerr << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

int main() {
    Pessoa* pessoas[_MAX];
    int qtd = 0;
    menuPrincipal(pessoas, qtd);
    for (int i = 0; i < qtd; ++i) {
        delete pessoas[i];
    }
    return 0;
}
