#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nMedia das Notas dos alunos\n\n");
}

float qtdAlunos(){
    int alunos;
    printf("Digite quantos sao os alunos:");
    scanf("%d", &alunos);
    return alunos;
}

void lerNotas(float v[], int alunos){
    for(int i = 0; i < alunos; i++){
        printf("\nqual a nota do %d aluno:", i + 1);
        scanf("%f", &v[i]);
    }
}

float mediaNotas(float v[], int alunos){
    float soma = 0;
    for(int i = 0; i < alunos; i++){
        soma += v[i];
    }
    return soma / alunos;
}

void qtdAcima(float v[], int alunos, float media){
    printf("\nMedia:\n");
    int acimaMedia = 0;
    for(int i = 0; i < alunos; i++){
        if(v[i] > media){
            printf("\n%.2f esta acima da media", v[i]);
            acimaMedia++;
        }
        else if(v[i] == media){
            printf("\n%.2f esta na media", v[i]);
        }
        else{
            printf("\n%.2f esta abaixo da media", v[i]);
        }
    }
    printf("\n%d aluno esta acima da media", acimaMedia);

}

void maiorMenorNota(float v[], int alunos, float *maior, float *menor){
    printf("\n\nMaior Menor nota:\n");
    *maior = v[0];
    *menor = v[0];
    for(int i = 1; i < alunos; i++){
        if(v[i] < *menor){
            *menor = v[i];
        }
        else if(v[i] > *maior){
            *maior = v[i];
        }
    }
    printf("\n%.2f foi a maior nota", *maior);
    printf("\n%.2f foi a menor nota", *menor);
}

void aprovacao(float v[], int alunos, int *aprovados, float *menorAprovado){
    printf("\n\naprovacao:\n");
    *aprovados = 0;
    *menorAprovado = -1;
    for(int i = 0; i < alunos; i++){
            if(v[i] < 60){
                printf("\n%.2freprovado", v[i]);
            }
            else {
                printf("\n%.2faprovado", v[i]);
                (*aprovados)++;
                if(*menorAprovado == -1 || v[i] < *menorAprovado){
                *menorAprovado = v[i];
            }
        }
    }
    if(*menorAprovado == -1){
        printf("nenhum dos alunos foram aprovados");
    }
    else{
        printf("\n a menor nota dentre os aprovados e: %.2f", *menorAprovado);
    }
}

void percentual(int aprovados, int alunos){
    float percentualAprovado = ((float)aprovados / alunos) * 100;
    float percentualReprovado = 100 - percentualAprovado;
    printf("\no percentual de alunos aprovados e: %.2f%%", percentualAprovado);
    printf("\no percentual de alunos reprovados e: %.2f%%", percentualReprovado);
}

int main() {
    apresentacao();

    int alunos = qtdAlunos();
    float notas[alunos];

    lerNotas(notas, alunos);

    float media = mediaNotas(notas, alunos);

    qtdAcima(notas, alunos, media);
    printf("\nMedia das notas: %.2f", media);

    float menor, maior;
    maiorMenorNota(notas, alunos, &maior, &menor);

    float menorAprovado;
    int aprovados;
    aprovacao(notas, alunos, &aprovados, &menorAprovado);

    percentual(aprovados, alunos);

    return 0;
}