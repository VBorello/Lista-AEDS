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

int verMaiorNota(int alunos, int notas[alunos]){
    
    int maior = 0;

    for(int i = 0; i < alunos; i++){
        if(notas[i] > maior){
            maior = notas[i];
        }
    }

    return maior;
}

int verMenorNota(int alunos, int notas[alunos]){

    int menor = 100;

    for(int i = 0; i < alunos; i++){
        if(notas[i] < menor){
            menor = notas[i];
        }
    }
    return menor;
}

int verMenorAprovado(int alunos, int notas[alunos]){
    
    int menorAprovado = 100;

    for(int i = 0; i < alunos; i++){
        if(notas[i] < menorAprovado && notas[i] >= 60){
            menorAprovado = notas[i];
        }
    }
    return menorAprovado;
}

float verPercentualAprovado(int alunos, int notas[alunos]){

    float percentual;
    int aprovados = 0;

    for(int i = 0; i < alunos; i++){
        if(notas[i] >= 60){
            aprovados++;
        }
    }

    percentual = (float)aprovados / alunos;

    return percentual; 
}

int main(){
    apresentacao();

    int alunos;
    lerQtdAlunos(&alunos);

    int *notas = (int *)malloc(alunos * sizeof(int));

    lerNotas(alunos, notas);
    float media = calcularMedia(alunos, notas);

    printf("\nA media da turma foi: %.2f", media);

    int acima;
    int maior;
    int menor;
    int menorAprovado;
    float percentualAprovado;
    
    acima  = acimaDaMedia(alunos, notas);

    printf("\nA quantidade de alunos acima da media foram: %d", acima);
    
    maior = verMaiorNota(alunos, notas);
    
    printf("\nA maior nota da turma e: %d", maior);

    menor = verMenorNota(alunos, notas);

    printf("\nA menor nota da turma e: %d", menor);

    menorAprovado = verMenorAprovado(alunos, notas);

    printf("\nA menor notas dentre os aprovados e: %d", menorAprovado);

    percentualAprovado = verPercentualAprovado(alunos, notas);

    printf("\nO percentual aprovado da turma foi: %.2f%%", percentualAprovado);

    return 0;
}

