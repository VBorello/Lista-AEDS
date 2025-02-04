#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX = 100; //tamanho maximo dos nomes
int TAM = 0; //contador global dos registros

typedef struct {

    char nome[100];
    int idade;

}Pessoa;

void apresentacao(){
    printf("\nCadastramento de Pessoas\n\n");
}

void cadastrarPessoa(Pessoa pessoas[MAX]){

    if (TAM < MAX) {
        printf("\nDigite o nome da pessoa: ");
        getchar();
        fgets(pessoas[TAM].nome, sizeof(pessoas[TAM].nome), stdin);
        pessoas[TAM].nome[strcspn(pessoas[TAM].nome, "\n")] = '\0';

        printf("Digite a idade da pessoa: ");
        scanf("%d", &pessoas[TAM].idade);


        FILE *arquivo = fopen("cadastros.txt", "a");
        if(arquivo == NULL){
            printf("erro ao registrar\n");
            return;
        } 

        fprintf(arquivo,"%s, %d\n", pessoas[TAM].nome, pessoas[TAM].idade);
        
        fclose(arquivo);

        TAM++;

    }else {
        printf("\nMáximo de pessoas cadastradas atingido.\n");
    }
}

void listarPessoas(Pessoa pessoas[MAX]){
   
    FILE *arquivo = fopen("cadastros.txt", "r");
    if(arquivo == NULL){
        printf("\nO arquivo não possui nenhum cadastro.\n");
        return;
    }

    TAM = 0; //reiniciar o contador antes de carregar o arquivo ;)
    char linha[150]; //armazenar cada linha do arquivo

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        if(sscanf(linha, "%99[^,], %d", pessoas[TAM].nome, &pessoas[TAM].idade) == 2){
            TAM++;
        }
    }
    fclose(arquivo);

   if(TAM == 0){
        printf("\nNenhuma pessoa foi cadastradas ainda.");
    }
    else{
        for(int i = 0; i < TAM; i++){
            printf("\nPessoa %d: nome: %s, idade: %d", i + 1, pessoas[i].nome, pessoas[i].idade);

        }
        printf("\n");
    }
}

void calcularMediaEtaria(Pessoa pessoas[MAX]){
    
    FILE *arquivo = fopen("cadastros.txt", "r");
    if(arquivo == NULL){
        printf("\nO arquivo não possui nenhum cadastro.\n");
        return;
    }

    int total = 0; 
    int i = 0;
    char linha[150];

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        
        int idade;
        char nome[100];

        if(sscanf(linha, "%99[^,], %d", nome, &idade) == 2){
            total += idade;
            i++;
        }
    }

    fclose(arquivo);

    if(i == 0){
        printf("\nNenhuma pessoa foi cadastradas ainda.");
        return;
    }

    float media = (float)total / TAM;
    printf("\nA media de idade das pessoas cadastradas e: %.0f", media);
}

void deletarCadastro(){

    char opcao;
    bool erro;

    do{

        printf("\nDeseja mesmo deletar os cadastros?\n(s/n): ");
        scanf(" %c", &opcao);

        erro = (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');
        if(erro){
            printf("\nOpcão inválida");
        }
    }while(erro);
    
    if(opcao == 's' || opcao == 'S'){

        FILE *arquivo = fopen("cadastros.txt", "w");
        if(arquivo != NULL){
            fclose(arquivo);
            printf("\nCadastros deletados com sucesso.\n");
        }
        else{
            printf("\nO arquivo já não possui cadastros.\n");
        }

    }
    else{
        printf("\nAção cancelada.");
    }   
}

int main(){

    apresentacao();
    
    Pessoa pessoas[MAX];
    
    int opcao;

    do{
        printf("\nMenu:\n0 - Sair\n1 - Cadastrar Pessoas\n2 - Listar Pessoas\n3 - Calcular media etária\n4 - Deletar cadastros\n: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:{
                printf("Saindo do programa.\n");
                break;
            }   
            case 1:{
                cadastrarPessoa(pessoas);
                break;
            }
            case 2:{
                listarPessoas(pessoas);
                break;
            }
            case 3:{
                calcularMediaEtaria(pessoas);
                break;
            }
            case 4:{
                deletarCadastro();
                break;
            }
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    
    }while (opcao != 0);

    return 0;
}


