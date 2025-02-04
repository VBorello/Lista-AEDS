#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nAprovados\n\n");
}

void lerNotas(int* notas, int* qtdAlunos){
    int nota;
    int i = 0;

    do {
        printf("Digite a nota ('0' para parar de ler): ");
        scanf("%d", &nota);
        
            if (nota <= 0 || nota > 100) {
                printf("\nNota invalida. Deve estar entre 0 e 100.\n");
            } else {
                notas[i++] = nota;
            }

    } while (nota != 0);

    *qtdAlunos = i; 
}

void calcularPercentagem(int* notas, int qtdAlunos) {
    int aprovados = 0, reprovados = 0;
    
    for (int i = 0; i < qtdAlunos; i++) {
        if (notas[i] < 60) {
            reprovados++;
        } else {
            aprovados++;
        }
    }

    float percentagemAprovada = (float)aprovados / qtdAlunos * 100;
    float percentagemReprovada = (float)reprovados / qtdAlunos * 100;

    printf("\nA percentagem de alunos aprovados da turma e %.2f%%", percentagemAprovada);
    printf("\nA percentagem de alunos reprovados da turma e %.2f%%", percentagemReprovada);
}

int main() {
    apresentacao();

    int alunos;
    int* notas = (int*)malloc(100 * sizeof(int)); 

    if (notas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; 
    }

    lerNotas(notas, &alunos);

    if (alunos > 0) {
        calcularPercentagem(notas, alunos);
    } else {
        printf("Nenhum aluno foi registrado.\n");
    }

    free(notas); 
    return 0;
}
