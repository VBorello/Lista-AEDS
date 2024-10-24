#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nCadastrador de Senha\n");
}

int verTam(char* SenhaTeste){
    
    int tam = 0;
    
    while (SenhaTeste[tam] != '\0'){
        tam++;
    }

    return tam;
}

void cadastrarSenha(){
    
    FILE* arq = fopen("password.dat", "w");
        if(arq == NULL){
            printf("arquivo não encontrado");
            return;
        }
    
    char Senha[100];

    printf("\nDigite a nova senha: ");
    scanf("%s", Senha);

    fprintf(arq, "%s", Senha);
    printf("\nSenha Cadstrada com Sucesso!\n");

    fclose(arq);
}


bool validar(){

    bool conhecidem = true;
    char SenhaTeste[100];

    printf("Digite a senha: ");
    scanf("%s", SenhaTeste);
    
    FILE* arq = fopen("password.dat", "r");
    if(arq == NULL){
        printf("arquivo não encontrado");
        return false;
    }

    char Senha[100];
    fscanf(arq ,"%s", Senha);

    fclose(arq);

    int tam1 = verTam(Senha);
    int tam2 = verTam(SenhaTeste);

    if(tam1 != tam2){
        conhecidem = false;
    }

    for(int i = 0; i < tam1; i++){
        if(Senha[i] != SenhaTeste[i]){
            conhecidem = false;
        }
    }

    return conhecidem;
}

void menu(){

    int opcao;
    
    do{
        printf("\n0- Sair\n1- Cadastrar Senha\n2- Validar Senha\nDigite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:{
            printf("\nSaindo...");

            return;
        }

        case 1:{
            cadastrarSenha();

            break;
        }

        case 2:{
            if(validar()){
                printf("\nSenha válida!\n");
            }
            else{
                printf("\nSenha inválida\n");
            }

            break;
        }

        default:

            printf("\nOpção inválida.\nSelecione Uma opção valida\n");
            menu();

            break;
        }

    }while (opcao != 0);

}   

int main(){
    apresentacao();

    menu();

    return 0;
}