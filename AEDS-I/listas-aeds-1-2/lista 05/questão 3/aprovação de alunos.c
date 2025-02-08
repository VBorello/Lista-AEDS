#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nAprovacao de alunos\n\n");
}

void lerAlunos(int* qtd){

    bool erro;

    do{
        printf("Quantos são os alunos? ");
        scanf("%d", qtd);
        erro = (*qtd < 1);
        if(erro){
            printf("\nQuantidade de alunos inválido");
        }
    }while(erro);

}

void lerNotas(int* notas, int qtd){
    
    bool erro;

    for(int i = 0; i < qtd; i++){
        do{
            printf("\nDigite a nota do %d aluno:", i + 1);
            scanf("%d", &notas[i]);

            erro = (notas[i] > 100 || notas[i] < 0);
            if(erro){
                printf("\nNota inválida");
            }
        }while(erro);
    }
}

int identificarMaior(int* notas, int qtd){
    int maior = 0;
    for(int i = 0; i < qtd; i++){
        if(notas[i] > maior){
            maior = notas[i];
        }
    }

    printf("\nA maior nota da sala foi: %d\n", maior);

    return maior;
}

int identificarMenor(int* notas, int qtd){
    int menor = 100;
    for(int i = 0; i < qtd; i++){
        if(notas[i] < menor){
            menor = notas[i];
        }
    }

    printf("\nA menor nota da sala foi: %d\n", menor);

    return menor;
}

void calcularNotas(int* notas, int qtd){

        for(int i = 0; i < qtd; i++){
            if(notas[i] < 60){
                printf("\naluno %d reprovado", i);
            }
            else{
                printf("\naluno %d aprovado", i);
            }
        }
}

float calcularMedia(int* notas, int qtd){
    
    float media;
    int total = 0;
    for(int i = 0; i < qtd; i++){
        total += notas[i];
    }

    media = (float)total / qtd;

    printf("\nA media das notas da turma e de: %.2f", media);

    return media;
}

int main(){

    apresentacao();
    int alunos;
    lerAlunos(& alunos);
    
    int* notas = (int*)malloc(alunos * sizeof(int));
    
    if(notas == NULL){
        printf("\nERRO AO ALOCAR");
        return 1;
    }
    
    lerNotas(notas, alunos);

    calcularNotas(notas, alunos);
    calcularMedia(notas, alunos);
    identificarMaior(notas, alunos);
    identificarMenor(notas, alunos);

    free(notas);

    return 0;
}