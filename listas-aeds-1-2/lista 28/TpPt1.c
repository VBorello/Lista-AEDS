#include <stdio.h>
#include <string.h>

const int MAX = 100; 
int TAM = 0;         

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void cadastrarPessoa(Pessoa pessoas[MAX]) {
    if (TAM < MAX) {
        printf("Digite o nome da pessoa: ");
        getchar(); // Limpar o buffer do teclado
        fgets(pessoas[TAM].nome, 50, stdin);
        pessoas[TAM].nome[strcspn(pessoas[TAM].nome, "\n")] = '\0'; // Remover a quebra de linha

        printf("Digite a idade da pessoa: ");
        scanf("%d", &pessoas[TAM].idade);

        TAM++;
    } else {
        printf("Limite de pessoas atingido!\n");
    }
}

// Função para listar todas as pessoas cadastradas
void listarPessoas(Pessoa pessoas[MAX]) {
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
    } else {
        for (int i = 0; i < TAM; i++) {
            printf("Pessoa %d: Nome: %s, Idade: %d\n", i + 1, pessoas[i].nome, pessoas[i].idade);
        }
    }
}

// Função para calcular e informar a idade média
void calcularIdadeMedia(Pessoa pessoas[MAX]) {
    if (TAM == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }

    int somaIdades = 0;
    for (int i = 0; i < TAM; i++) {
        somaIdades += pessoas[i].idade;
    }

    float media = (float)somaIdades / TAM;
    printf("A idade média da turma é: %.2f\n", media);
}

// Função principal com menu
int main() {
    Pessoa pessoas[MAX];
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar uma pessoa\n");
        printf("2. Listar todas as pessoas\n");
        printf("3. Informar a idade média\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPessoa(pessoas);
                break;
            case 2:
                listarPessoas(pessoas);
                break;
            case 3:
                calcularIdadeMedia(pessoas);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
