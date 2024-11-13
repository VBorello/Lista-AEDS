#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nCadastro de Notas\n\n");
}

void lerQtd(int *qtd){
    printf("\nDigite quantas notas quer cadastrar: ");
    scanf("%d", qtd);
}

void cadastrarNotas(int qtd, float notas[qtd]){
    bool erro;

    for(int i = 0; i < qtd; i++){
        do {
            printf("\nDigite a nota %d: ", i + 1);
            scanf("%f", &notas[i]);
                    
            erro = (notas[i] > 100 || notas[i] < 0);
            if(erro){
                printf("\nNota inválida, insira uma nota entre 0 e 100.");
            }

        } while(erro);
    }

    printf("\nNotas cadastradas com sucesso\n");

}

int calcularAprovados(int qtd, float notas[qtd]){
    int aprovados = 0;

    for(int i = 0; i < qtd; i++){
        if(notas[i] >= 60){
            aprovados++;
        }
    }
    return aprovados;
}

float calcularAmplitude(int qtd, float notas[qtd]){
    float menor = 100, maior = 0;

    for(int i = 0; i < qtd; i++){
        if(notas[i] > maior){
            maior = notas[i];
        }
        if(notas[i] < menor){
            menor = notas[i];
        }
    }
    return maior - menor;
}

void menu(){
    int opcao;

    int quantidade = 0;
    float *notas = NULL;

    do{
        printf("\nEscolha uma opção:\n");
        printf("- 0: Sair\n- 1: Cadastrar Notas\n- 2: Informar Alunos Aprovados\n- 3: Informar Amplitude\n: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("\nObrigado por usar o programa! Saindo...\n");
                free(notas);
                return;

            case 1:{
                if (notas != NULL) {
                    free(notas);
                }
                lerQtd(&quantidade);
                notas = (float *)malloc(quantidade * sizeof(float));
                
                cadastrarNotas(quantidade, notas);
                
                break;
            }
            case 2:{
                if (notas == NULL) {
                    printf("\nCadastre as notas primeiro.\n");
                } else {
                    int aprovados = calcularAprovados(quantidade, notas);
                    printf("\n%d de %d alunos foram aprovados.\n", aprovados, quantidade);
                }
                
                break;
            }
            case 3:{
                if (notas == NULL) {
                    printf("\nCadastre as notas primeiro.\n");
                } else {
                    float amplitude = calcularAmplitude(quantidade, notas);
                    printf("\nA amplitude das notas é: %.2f\n", amplitude);
                }
                
                break;
            }
            default:{
                printf("\nOpção inválida. Tente novamente.\n");
            
                break;
            }
        }
    } while (opcao != 0);

}

int main(){
    apresentacao();
    menu();
    return 0;
}
