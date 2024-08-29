#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nTudo da Turma\n\n");
}

void lerAlunos(int* alunos){

    printf("Quantos são os alunos? ");
    scanf("%d", alunos);
}

void lerIdade(int* idades, int alunos){

    for(int i = 0; i < alunos; i++){
        printf("\nDigite a idade do aluno %d: ", i + 1);
        scanf("%d", &idades[i]);
    }
}

void lerGenero(char* generos, int alunos){

    for(int i = 0; i < alunos; i++){
        bool erro;
        do{
            printf("\nDigite o sexo do aluno %d: ", i + 1);
            scanf(" %c", &generos[i]);
            erro = (generos[i] != 'f' && generos[i] != 'F' && generos[i] != 'm' && generos[i] != 'M');
            if(erro){
                printf("\nGenero inválido");
            }
        }while(erro);
    }
}

void lerNota(float* notas, int alunos){

    for(int i = 0; i < alunos; i++){
        printf("\nDigite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

int maiorDeIdade(int* idades, int alunos){

    int maiorDeIdade = 0;
    for(int i = 0; i < alunos; i++){
        if(idades[i] >= 18){
            maiorDeIdade++;
        }
    }

    return maiorDeIdade;
}

float percentualMaior(int* idades, int alunos){
    
    int maior = maiorDeIdade(idades, alunos);
    float percentualMaior = (float)maior / alunos * 100;

    return percentualMaior;
}

int idadeMaior(int* idades, int alunos){
    
    int maior = 0;
    for(int i = 0; i < alunos; i++){
        if(idades[i] > maior){
            maior = idades[i];
        }
    }

    return maior;
}

int idadeMenor(int* idades, int alunos){
    
    int menor = 100;
    for(int i = 0; i < alunos; i++){
        if(idades[i] < menor){
            menor = idades[i];
        }
    }

    return menor;
}

int amplitudeEtaria(int* idades, int alunos){
    
    int menor = idadeMenor(idades, alunos);
    int maior = idadeMaior(idades, alunos);

    int amplitude = maior - menor;

    return amplitude;
}

float mediaEtaria(int* idades, int alunos){

    int total = 0;
    for(int i = 0; i < alunos; i++){
        total += idades[i];
    }

    float mediaIdade = (float)total / alunos;

    return mediaIdade;
}

float maiorNota(float* notas, int alunos){
    
    int notaMaior = 0;
    for(int i = 0; i < alunos; i++){
        if(notas[i] > notaMaior){
            notaMaior = notas[i];
        }
    }

    return notaMaior;
}

float menorNota(float* notas, int alunos){
    
    int notaMenor = 100;
    for(int i = 0; i < alunos; i++){
        if(notas[i] < notaMenor){
            notaMenor = notas[i];
        }
    }

    return notaMenor;
}

void aprovacao(float* notas, int alunos, int* aprovados, int* reprovados){
    
    *aprovados = 0;
    *reprovados = 0;
    for(int i = 0; i < alunos; i++){
        if(notas[i] >= 60){
            printf("\naluno %d Aprovado", i + 1);
            (*aprovados)++;
        }
        else if(notas[i] < 60){
            printf("\naluno %d reprovado", i + 1);
            (*reprovados)++;
        }
    }
}

float amplitudeNotas(float* notas, int alunos){
    float notaMaior = maiorNota(notas, alunos);
    float notaMenor = menorNota(notas, alunos);

    float amplitude = notaMaior - notaMenor;

    return amplitude;
}

float percentualAprovado(float* notas, int alunos){
    
    int aprovados, reprovados;
    aprovacao(notas, alunos, &aprovados, &reprovados);
    
    float aprovadosPercentual = (float)aprovados / alunos * 100;

    return aprovadosPercentual;
}

float percentualReprovado(float* notas, int alunos){

    int reprovados, aprovados;
    aprovacao(notas, alunos, &aprovados, &reprovados);

    float reprovacaoPercentual = (float)reprovados / alunos * 100;

    return reprovacaoPercentual;
}

float mediaNotas(float* notas, int alunos){

    float total = 0;
    for(int i = 0; i < alunos; i++){
        total += notas[i];
    }

    float mediaDasNotas = total / alunos;
    return mediaDasNotas;

}

int main(){
    apresentacao();

    int alunos;
    lerAlunos(&alunos);

    int* idades = (int*) malloc(alunos * sizeof(int));
    char* generos = (char*) malloc(alunos * sizeof(char));
    float* notas = (float*) malloc(alunos * sizeof(float));

    if (idades == NULL || generos == NULL || notas == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    lerIdade(idades, alunos);
    lerGenero(generos, alunos);
    lerNota(notas, alunos);

    printf("\nPercentual de alunos maiores de idade: %.2f%%", percentualMaior(idades, alunos));
    printf("\nMaior idade: %d", idadeMaior(idades, alunos));
    printf("\nMenor idade: %d", idadeMenor(idades, alunos));
    printf("\nMaior Amplitude etária: %d", amplitudeEtaria(idades, alunos));
    printf("\nMédia etária: %.2f", mediaEtaria(idades, alunos));
    printf("\nMaior nota: %.2f", maiorNota(notas, alunos));
    printf("\nMenor nota: %.2f", menorNota(notas, alunos));
    printf("\nMaior Amplitude das notas: %.2f", amplitudeNotas(notas, alunos));
    printf("\nPercentual de aprovação: %.2f%%", percentualAprovado(notas, alunos));
    printf("\nPercentual de reprovação: %.2f%%", percentualReprovado(notas, alunos));
    printf("\nMédia das notas: %.2f", mediaNotas(notas, alunos));

    free(idades);
    free(generos);
    free(notas);

    return 0;
}
