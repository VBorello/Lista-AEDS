#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct{
    char nome[50];
    int idade;
} ALUNOS;

void apresentacao(){
    printf("\n\nStruct Cadastro de Alunos\n");
}

int menu(){
    int opcao;
    printf("1 para cadastrar aluno\n2 para listar os alunos\n3 informar a idade media da turma\n0 para sair\n");
    scanf("%d", &opcao);
    return opcao;
}

void lerAlunos(ALUNOS* alunos[], int* qtd){
    int num;
    printf("\nQuantos são os novos alunos: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        if (*qtd >= max) {
            printf("Capacidade máxima de alunos atingida.\n");
            return;
        }
        alunos[*qtd] = (ALUNOS *)malloc(sizeof(ALUNOS));
        if(alunos[*qtd] == NULL){
            printf("Erro ao alocar memória\n");
            exit(1);
        }
        printf("\nNome: ");
        getchar();
        fgets(alunos[*qtd]->nome, 50, stdin);
        size_t len = strlen(alunos[*qtd]->nome);
        if (len > 0 && alunos[*qtd]->nome[len - 1] == '\n') {
            alunos[*qtd]->nome[len - 1] = '\0';
        }
        printf("\nIdade: ");
        scanf("%d", &alunos[*qtd]->idade);
        (*qtd)++;
    }
}

void listar(ALUNOS* alunos[], int qtd){
    if (qtd == 0) {
        printf("\nNenhum aluno registrado.\n");
        return;
    }
    for(int i = 0; i < qtd; i++){
        printf("\nNome: %s", alunos[i]->nome);
        printf("\nIdade: %d\n", alunos[i]->idade);
    }
}

float mediaIdade(ALUNOS* alunos[], int qtd){
    int soma = 0;
    for(int i = 0; i < qtd; i++){
        soma += alunos[i]->idade;
    }
    if (qtd == 0) return 0.0;
    return (float)soma / qtd;
}

int main(){
    apresentacao();

    ALUNOS* alunos[max];
    int qtd = 0;
    int opcao;

    do {
        opcao = menu();

        switch (opcao) {
            case 1:
                lerAlunos(alunos, &qtd);
                break;
            case 2:
                listar(alunos, qtd);
                break;
            case 3:
                printf("\nA idade média da turma é: %.2f\n", mediaIdade(alunos, qtd));
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (opcao != 0);

    for(int i = 0; i < qtd; i++){
        free(alunos[i]);
    }

    return 0;
}
