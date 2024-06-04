#include <stdlib.h>
#include <stdio.h>

#define max 100

void apresentacao() {
    printf("\nMedia das Notas dos alunos\n\n");
}

int lerNotas(float v[]) {
    int i = 0;
    float nota;
    printf("Digite as notas dos alunos (nota negativa para encerrar):\n");
    while (i < max) {
        printf("\nQual a nota do %d aluno: ", i + 1);
        scanf("%f", &nota);
        if (nota < 0) {
            break;
        }
        v[i] = nota;
        i++;
    }
    return i; 
}

float mediaNotas(float v[], int alunos) {
    float soma = 0;
    for (int i = 0; i < alunos; i++) {
        soma += v[i];
    }
    return soma / alunos;
}

void qtdAcima(float v[], int alunos, float media) {
    printf("\nMedia:\n");
    int acimaMedia = 0;
    for (int i = 0; i < alunos; i++) {
        if (v[i] > media) {
            printf("\n%.2f esta acima da media", v[i]);
            acimaMedia++;
        } else if (v[i] == media) {
            printf("\n%.2f esta na media", v[i]);
        } else {
            printf("\n%.2f esta abaixo da media", v[i]);
        }
    }
    printf("\n%d aluno(s) esta(ao) acima da media", acimaMedia);
}

void maiorMenorNota(float v[], int alunos, float *maior, float *menor) {
    printf("\n\nMaior Menor nota:\n");
    *maior = v[0];
    *menor = v[0];
    for (int i = 1; i < alunos; i++) {  
        if (v[i] < *menor) {
            *menor = v[i];
        }
        if (v[i] > *maior) {
            *maior = v[i];
        }
    }
    printf("\n%.2f foi a maior nota", *maior);
    printf("\n%.2f foi a menor nota", *menor);
}

void aprovacao(float v[], int alunos, int *aprovados, float *menorAprovado) {
    printf("\n\nAprovacao:\n");
    *aprovados = 0;
    *menorAprovado = -1;
    for (int i = 0; i < alunos; i++) {
        if (v[i] < 60) {
            printf("\n%.2f reprovado", v[i]);
        } else {
            printf("\n%.2f aprovado", v[i]);
            (*aprovados)++;
            if (*menorAprovado == -1 || v[i] < *menorAprovado) {
                *menorAprovado = v[i];
            }
        }
    }
    if (*menorAprovado == -1) {
        printf("\nNenhum aluno foi aprovado");
    } else {
        printf("\nA menor nota dentre os aprovados e: %.2f", *menorAprovado);
    }
}

void percentual(int aprovados, int alunos) {
    float percentualAprovado = ((float)aprovados / alunos) * 100;
    float percentualReprovado = 100 - percentualAprovado;
    printf("\nO percentual de alunos aprovados e: %.2f%%", percentualAprovado);
    printf("\nO percentual de alunos reprovados e: %.2f%%", percentualReprovado);
}

int main() {
    apresentacao();

    float notas[max];
    int alunos = lerNotas(notas);  

    if (alunos == 0) {
        printf("Nenhuma nota foi inserida.\n");
        return 0;
    }

    float media = mediaNotas(notas, alunos);
    printf("\nMedia das notas: %.2f", media);

    qtdAcima(notas, alunos, media);

    float menor, maior;
    maiorMenorNota(notas, alunos, &maior, &menor);

    float menorAprovado;
    int aprovados;
    aprovacao(notas, alunos, &aprovados, &menorAprovado);

    percentual(aprovados, alunos);

    return 0;
}
