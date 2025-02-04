#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nNota de Alunos\n\n");
}

void lerQtdAlunos(int *alunos){
    printf("Digite a quantidade de alunos: ");
    scanf("%d", alunos);
}

void lerNotas(int alunos, int notas[alunos]){
    
    bool erro;
    for(int i = 0; i < alunos; i++){
        do{
            printf("\nDigite a nota do %d alunos: ", i + 1);
            scanf("%d", &notas[i]);
            erro =(notas[i] > 100 || notas[i] < 0);
            if(erro){
                printf("\nNota invalida");
            }
        }while(erro);
    }
}

float calcularMedia(int alunos, int notas[alunos]){

    int total = 0;
    for(int i = 0; i < alunos; i++){
        total += notas[i];
    }

    float media = (float)total / alunos;

    return media;
}

int acimaDaMedia(int alunos, int notas[alunos]){
    
    float media;
    media = calcularMedia(alunos, notas);

    int qtdAcima = 0;
    for(int i = 0; i < alunos; i++){
        if(notas[i] > media){
            qtdAcima++;
        }
    }

    return qtdAcima;
}

int main(){
    apresentacao();

    int alunos;
    lerQtdAlunos(&alunos);

    int *notas = (int *)malloc(alunos * sizeof(int));

    lerNotas(alunos, notas);
    float media = calcularMedia(alunos, notas);

    printf("\nA media da turma foi: %.2f", media);

    int acima = acimaDaMedia(alunos, notas);

    printf("\nA quantidade de alunos acima da media foram: %d", acima);

    return 0;
}

