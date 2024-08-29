#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPerfil da Turma\n\n");
}

void qtdAlunos(int* qtd){
    printf("quantos são os alunos? ");    
    scanf("%d", qtd);
}

void lerIDade(int* idades, int qtd){
    bool erro;
  
    for(int i = 0; i < qtd; i++){
        do{
            printf("\nQual a idade do aluno %d: ", i + 1);
            scanf("%d", &idades[i]);

            erro = (idades[i] > 100 || idades[i] < 0);
            if(erro){
                printf("\nIdade inválida");
            }
        }while (erro);
    }
}

void lerGenero(char* genero, int qtd){
    bool erro;

    for(int i = 0; i < qtd; i++){
        do{
            printf("\nQual o genero do aluno %d (M/F):", i + 1);
            scanf(" %c", &genero[i]);

            erro = (genero[i] != 'm' && genero[i] != 'M' && genero[i] != 'f' && genero[i] != 'F');
            if(erro){
                printf("\nSexo inválido");
            }

        }while(erro);
    }
}

int identificarMaisVelha(int* idades, int qtd){
    
    int maisVei = idades[0];
    for(int i = 1; i < qtd; i++){
        if(idades[i] > maisVei){
            maisVei = idades[i];
        }
    }

    printf("\nA idade do aluno mais velho e de: %d", maisVei);
    return maisVei;
}

int identificarMaisNovo(int* idades, int qtd){
    
    int maisNovo = idades[0];
    for(int i = 1; i < qtd; i++){
        if(idades[i] < maisNovo){
            maisNovo = idades[i];
        }
    }

    printf("\nA idade do aluno mais novo e de: %d", maisNovo);
    return maisNovo;
}

int percentualMaior(int* idades, int qtd){
    int dmaior = 0;

    for(int i = 0; i < qtd; i++){
        if(idades[i] >= 18){
            dmaior++;
        }
    }

    float percentualDmaior = (float)dmaior / qtd * 100;


    printf("\nO percentual da turma que e maior de idade e de: %.2f%%", percentualDmaior);
    return percentualDmaior;
}

int percentualHomen(char* genero, int qtd){

    int meninos = 0;
    
    for(int i = 0; i < qtd; i++){
        if(genero[i] == 'm' || genero[i] == 'M'){
            meninos++;
        }
    }

    float percentualMasculino = (float)meninos / qtd * 100;

    printf("\nO percentual de alunos homens e de: %.2f%%", percentualMasculino);
    return percentualMasculino;
}

int percentualMulher(char* genero, int qtd){
    
    int meninas = 0;

    for(int i = 0; i < qtd; i++){
        if(genero[i] == 'f' || genero[i] == 'F'){
            meninas++;
        }
    }

    float percentualFeminino = (float)meninas / qtd * 100;

    printf("\nO percentual de alunas mulheres e de: %.2f%%", percentualFeminino);
    return percentualFeminino;
}

int main(){

    apresentacao();

    int qtd;
    qtdAlunos(& qtd);
    

    int* idade = (int *)malloc(qtd * sizeof(char));
    char* gen = (char *)malloc(qtd * sizeof(char));

    if (idade == NULL || gen == NULL) {
        printf("ERRO NA ALOCAÇÃO DINAMICA DOIDÃO");
        return 1;
    }

    lerIDade(idade, qtd);
    lerGenero(gen, qtd);

    identificarMaisVelha(idade, qtd);
    identificarMaisNovo(idade, qtd);
    percentualMaior(idade, qtd);

    percentualHomen(gen, qtd);
    percentualMulher(gen, qtd);

    free(idade);
    free(gen);
    
    return 0;
}