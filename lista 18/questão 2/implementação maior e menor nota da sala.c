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
    int soma = 0;
    for(int i = 0; i < alunos; i++){
        soma += v[i];
    }
    return soma / alunos;
}

void qtdAcima(float v[], int alunos, float media){
    int acimaMedia = 0;
    for(int i = 0; i < alunos; i++){
        if(v[i] > media){
            printf("\n%.2f esta acima da media\n", v[i]);
            acimaMedia++;
        }
        else if(v[i] == media){
            printf("\n%.2f esta na media\n", v[i]);
        }
        else{
            printf("\n%.2f esta abaixo da media\n", v[i]);
        }
    }
    printf("\n%d aluno esta acima da media\n", acimaMedia);

}

void maiorMenorNota(float v[], int alunos, float *maior, float *menor){
    *maior = v[0];
    *menor = v[0];
    for(int i = 0; i < alunos; i++){
        if(v[i] < *menor){
            *menor = v[i];
        }
        else if(v[i] > *maior){
            *maior = v[i];
        }
    }
    printf("\n%.2f foi a maior nota\n", *maior);
    printf("\n%.2f foi a menor nota\n", *menor);
}

int main(){
    apresentacao();
    
    int alunos = qtdAlunos();
    float notas[alunos];
    
    lerNotas(notas, alunos);

    float media = mediaNotas(notas, alunos);

    qtdAcima(notas, alunos, media);

    float menor, maior;
    maiorMenorNota(notas, alunos, &maior, &menor);

    
    return 0;
}