#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define max 1000

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data() : dia(0), mes(0), ano(0) {} //construtor inicializa a data como 0/0/0
    Data(int dia, int mes, int ano) {  //construtor com parâmetros para inicialização
        this -> dia = dia;
        this -> mes = mes;
        this -> ano = ano;
    }

    //métodos para definir dia, mês e ano
    void setDia(int dia) {
        this -> dia = dia;
    }

    void setMes(int mes) {
        this -> mes = mes;
    }

    void setAno(int ano) {
        this -> ano = ano;
    }

    //metodos para retornar dia, mês e ano
    int getDia() {
        return this -> dia;
    }

    int getMes() {
        return this -> mes;
    }

    int getAno() {
        return this -> ano;
    }

    //verifica se o ano é bissexto
    bool bissexto() {
        if ((this -> ano % 4 == 0 && this -> ano % 100 != 0) || (this -> ano % 400 == 0)) {
            return true;
        }
        return false;
    }

    // Valida se a data é válida
    bool validarData() {
        bool dataValida = true;

        if (this -> dia < 1 || this -> dia > 31 || this -> mes < 1 || this -> mes > 12 || this -> ano < 1 ||
            (this -> mes == 2 && ((this -> bissexto() && this -> dia > 29) || (!this -> bissexto() && this -> dia > 28))) ||
            (this -> mes == 4 && this -> dia > 30) ||
            (this -> mes == 6 && this -> dia > 30) ||
            (this -> mes == 9 && this -> dia > 30) ||
            (this -> mes == 11 && this -> dia > 30)) {
            dataValida = false;
            std::cout << "Data inválida." << std::endl;
        }
        return dataValida;
    }

    //método para ler uma data do usuário e validar
    void lerData() {
        int dia, mes, ano;
        do {
            std::cout << "Digite a data (dia mes ano): ";
            std::cin >> dia >> mes >> ano;

            this -> setDia(dia);
            this -> setMes(mes);
            this -> setAno(ano);

        } while (!this -> validarData());
    }

    //método para imprimir a data
    void printData() {
        std::cout << this -> dia << "/" << this -> mes << "/" << this -> ano << std::endl;
    }
};

//classe Pessoa como classe base
class Pessoa {
private:
    std::string nome;
    Data nascimento;
    static int qtd; //contador estático(para ter um escopo global) de pessoas

public:
    Pessoa() {
        qtd++;
    }

    static int getQtd() {
        return qtd;
    }

    void setNome(std::string nome) {
        this -> nome = nome;
    }

    std::string getNome() {
        return this -> nome;
    }

    //método para ler o nome da pessoa
    void lerNome() {
        std::cout << "Digite um nome: ";
        std::cin >> nome;
    }

    //método para imprimir o nome da pessoa
    void printNome() {
        std::cout << this -> nome << std::endl;
    }

    //método para ler dados da pessoa (nome e data de nascimento)
    void lerPessoa() {
        lerNome();
        nascimento.lerData();
    }

    //método para imprimir dados da pessoa
    void printPessoa() {
        printNome();
        nascimento.printData();
    }

    //método virtual para escrever dados da pessoa (polimorfismo)
    virtual void escrevaPessoa() {
        std::cout << "Nome: " << nome << "\nData de Nascimento: ";
        nascimento.printData();
    }

    //retorna a data de nascimento da pessoa
    Data getDataNascimento() {
        return nascimento;
    }
};

int Pessoa::qtd = 0; //inicialização do contador estático

//classe Aluno derivada de Pessoa
class Aluno : public Pessoa {
private:
    std::string matricula;
    static int qtd; //contador estático de alunos

public:
    Aluno() {
        qtd++;
    }

    static int getQtdAlunos() {
        return qtd;
    }

    virtual ~Aluno() {
        qtd--;
    }

    void setMatricula(std::string matricula) {
        this -> matricula = matricula;
    }

    std::string getMatricula() {
        return matricula;
    }

    //método para ler dados de um aluno (nome, data de nascimento e matrícula)
    void lerAluno() {
        lerPessoa();
        std::cout << "Digite a matrícula: ";
        std::cin >> matricula;
    }

    //método para imprimir dados de um aluno
    void printAluno() {
        printPessoa();
        std::cout << "Matrícula: " << matricula << std::endl;
    }

    // Método para escrever dados de um aluno
    void escrevaPessoa() override { //override modificar a implementação virtual de um método herdado.
        Pessoa::escrevaPessoa();
        std::cout << "Matrícula: " << matricula << std::endl;
    }
};

int Aluno::qtd = 0; // Inicialização do contador estático

// Classe Professor derivada de Pessoa
class Professor : public Pessoa {
private:
    std::string titulacao;
    static int qtd; // Contador estático de professores

public:
    Professor() {
        qtd++;
    }

    static int getQtdProfessores() {
        return qtd;
    }

    virtual ~Professor() {
        qtd--;
    }

    void setTitulacao(std::string titulacao) {
        this -> titulacao = titulacao;
    }

    std::string getTitulacao() {
        return titulacao;
    }

    //método para ler dados de um professor (nome, data de nascimento e titulação)
    void lerProfessor() {
        lerPessoa();
        std::cout << "Digite a titulacao: ";
        std::cin >> titulacao;
    }

    //método para imprimir dados de um professor
    void printProfessor() {
        printPessoa();
        std::cout << "Titulação: " << titulacao << std::endl;
    }

    // Método para escrever dados de um professor (nome, data de nascimento, titulação)
    void escrevaPessoa() override { //override modificar a implementação virtual de um método herdado.
        Pessoa::escrevaPessoa();
        std::cout << "Titulação: " << titulacao << std::endl;
    }
};

int Professor::qtd = 0; //inicialização do contador estático

void listarAniversariantes(Pessoa *pessoas[], int qtdPessoas, int mes) {
    for (int i = 0; i < qtdPessoas; ++i) {
        if (pessoas[i] -> getDataNascimento().getMes() == mes) {
            pessoas[i] -> escrevaPessoa();
        }
    }
}

void salvarDados(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    std::ofstream arquivo("dados.txt");

    if (!arquivo) {
        std::cerr << "Erro ao abrir arquivo." << std::endl;
        return;
    }

    //escreve os dados dos alunos no arquivo
    for (int i = 0; i < Aluno::getQtdAlunos(); ++i) {
        arquivo << "Aluno\n";
        arquivo << alunos[i] -> getNome() << "\n";
        arquivo << alunos[i] -> getDataNascimento().getDia() << " "
                << alunos[i] -> getDataNascimento().getMes() << " "
                << alunos[i] -> getDataNascimento().getAno() << "\n";
        arquivo << alunos[i] -> getMatricula() << "\n";
    }

    //escreve os dados dos professores no arquivo
    for (int i = 0; i < Professor::getQtdProfessores(); ++i) {
        arquivo << "Professor\n";
        arquivo << professores[i] -> getNome() << "\n";
        arquivo << professores[i] -> getDataNascimento().getDia() << " "
                << professores[i] -> getDataNascimento().getMes() << " "
                << professores[i] -> getDataNascimento().getAno() << "\n";
        arquivo << professores[i] -> getTitulacao() << "\n";
    }

    arquivo.close();
}

//função para ler o conteúdo de um arquivo e retornar como string
std::string lerArquivoParaString() {
    std::ifstream arquivo("dados.txt");
    std::stringstream buffer;
    std::string conteudo;

    if (!arquivo) {
        std::cerr << "Erro ao abrir arquivo." << std::endl;
        return "";
    }

    buffer << arquivo.rdbuf();
    conteudo = buffer.str();

    arquivo.close();

    return conteudo;
}

void cadastro(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    int opcao;
    do {
        std::cout << "\n Menu de Cadastro:\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "1 - Cadastrar Aluno\n";
        std::cout << "2 - Cadastrar Professor\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0: {
                return;
            }

            case 1: {
                if (Aluno::getQtdAlunos() < max) {
                    Aluno *aluno = new Aluno();
                    aluno -> lerAluno();
                    alunos[Aluno::getQtdAlunos() - 1] = aluno;
                    pessoas[Pessoa::getQtd() - 1] = aluno;
                } else {
                    std::cout << "Numero máximo de cadastros atingido\n";
                }
                break;
            }

            case 2: {
                if (Professor::getQtdProfessores() < max) {
                    Professor *professor = new Professor();
                    professor -> lerProfessor();
                    professores[Professor::getQtdProfessores() - 1] = professor;
                    pessoas[Pessoa::getQtd() - 1] = professor;
                } else {
                    std::cout << "Numero máximo de cadastros atingido\n";
                }
                break;
            }
        }
    } while (opcao != 0);
}

void alterarCadastro(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    int opcao;
    do {
        std::cout << "\nMenu de Alteração:\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "1 - Alterar Aluno\n";
        std::cout << "2 - Alterar Professor\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0: {
                return;
            }

            case 1: {
                int indiceAluno;
                std::cout << "Digite o numero do aluno para alterar (1-" << Aluno::getQtdAlunos() << "): ";
                std::cin >> indiceAluno;

                if (indiceAluno > 0 && indiceAluno <= Aluno::getQtdAlunos()) {
                    alunos[indiceAluno - 1] -> lerAluno();
                    pessoas[indiceAluno - 1] = alunos[indiceAluno - 1];
                    std::cout << "Aluno alterado.\n";
                } else {
                    std::cout << "Numero do aluno invalido.\n";
                }
                break;
            }

            case 2: {
                int indiceProfessor;
                std::cout << "Digite o numero do professor para alterar (1-" << Professor::getQtdProfessores() << "): ";
                std::cin >> indiceProfessor;

                if (indiceProfessor > 0 && indiceProfessor <= Professor::getQtdProfessores()) {
                    professores[indiceProfessor - 1] -> lerProfessor();
                    pessoas[indiceProfessor - 1] = professores[indiceProfessor - 1];
                    std::cout << "Professor alterado.\n";
                } else {
                    std::cout << "Numero de professor inválido.\n";
                }
                break;
            }

            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    } while (opcao != 0);
}

void excluirCadastro(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    int opcao;
    do {
        std::cout << "\nMenu de Exclusão:\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "1 - Excluir Aluno\n";
        std::cout << "2 - Excluir Professor\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0: {
                return;
            }

            case 1: {
                int indiceAluno;
                std::cout << "Digite o índice do aluno a ser excluído (1-" << Aluno::getQtdAlunos() << "): ";
                std::cin >> indiceAluno;

                if (indiceAluno > 0 && indiceAluno <= Aluno::getQtdAlunos()) {
                    delete alunos[indiceAluno - 1];
                    alunos[indiceAluno - 1] = nullptr;
                    std::cout << "Aluno excluído com sucesso.\n";
                } else {
                    std::cout << "Índice de aluno inválido.\n";
                }
                break;
            }

            case 2: {
                int indiceProfessor;
                std::cout << "Digite o índice do professor a ser excluído (1-" << Professor::getQtdProfessores() << "): ";
                std::cin >> indiceProfessor;

                if (indiceProfessor > 0 && indiceProfessor <= Professor::getQtdProfessores()) {
                    delete professores[indiceProfessor - 1];
                    professores[indiceProfessor - 1] = nullptr;
                    std::cout << "Professor excluído com sucesso.\n";
                } else {
                    std::cout << "Índice de professor inválido.\n";
                }
                break;
            }

            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    } while (opcao != 0);
}

void listar(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    int opcao;
    do {
        std::cout << "Menu Listagem:\n";
        std::cout << "0 - Voltar ao Menu Principal\n";
        std::cout << "1 - Listar Alunos\n";
        std::cout << "2 - Listar Professores\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0: {
                return;
            }

            case 1: {
                //lista todos os alunos cadastrados
                for (int i = 0; i < Aluno::getQtdAlunos(); ++i) {
                    alunos[i] -> printAluno();
                }

                //lê e exibe o conteúdo do arquivo de dados
                std::string conteudoArquivo = lerArquivoParaString();
                std::cout << "Conteúdo do arquivo:\n" << conteudoArquivo << std::endl;

                break;
            }

            case 2: {
                //lista todos os professores cadastrados
                for (int i = 0; i < Professor::getQtdProfessores(); ++i) {
                    professores[i] -> printProfessor();
                }
                
                //lê e exibe o conteúdo do arquivo de dados
                std::string conteudoArquivo = lerArquivoParaString();
                std::cout << "Conteúdo do arquivo:\n" << conteudoArquivo << std::endl;
                break;
            }
        }
    } while (opcao != 0);
}

void menu(Pessoa *pessoas[], Aluno *alunos[], Professor *professores[]) {
    int opcao;
    do {
        std::cout << "\nMenu Principal:\n";
        std::cout << "0 – Sair\n";
        std::cout << "1 – Cadastrar aluno ou professor(a/p):\n";
        std::cout << "2 – Listar alunos ou professores(a/p):\n";
        std::cout << "3 - Alterar alunos ou professores(a/p):\n";
        std::cout << "4 - Excluir alunos ou professores(a/p):\n";
        std::cout << "5 – Listar todos os aniversariantes do mês\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 0: {
                std::cout << "Salvando dados e saindo...\n";
                salvarDados(pessoas, alunos, professores);
                std::string conteudoArquivo = lerArquivoParaString();
                std::cout << "Conteúdo do arquivo:\n" << conteudoArquivo << std::endl;
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
                alterarCadastro(pessoas, alunos, professores);
                break;
            }

            case 4: {
                excluirCadastro(pessoas, alunos, professores);
                break;
            }

            case 5: {
                int mes;
                std::cout << "Digite o mês: ";
                std::cin >> mes;
                listarAniversariantes(pessoas, Pessoa::getQtd(), mes);
                break;
            }

            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    } while (opcao != 0);
}

int main() {
    Pessoa *pessoas[max];
    Aluno *alunos[max];
    Professor *professores[max];

    try {
        menu(pessoas, alunos, professores);
    } catch (std::bad_alloc& e) {
        std::cerr << "Erro de alocação de memória: " << e.what() << std::endl;
        return 1; // Retorna um código de erro
    }

    //libera a memória alocada para cada objeto criado
    for (int i = 0; i < Pessoa::getQtd(); ++i) {
        delete pessoas[i];
    }

    return 0;
}