#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nAlunos Maiores de idade File increment\n\n");
}

void lerIdades(){
    FILE* arq = fopen("idades.dat", "w");
   
    int idades;
    int i = 0;

    do {
        printf("\nDigite a idade do aluno %d (0 para terminar): ", i + 1);
        scanf("%d", &idades);

        if (idades != 0) {
            fprintf(arq, "%d ", idades);  
            i++;
        }
    } while (idades != 0);

    fclose(arq);

    arq = fopen("idades.dat", "r");
    
    int maiores = 0;
    while (fscanf(arq, "%d", &idades) == 1) {
        if (idades >= 18) {
            maiores++;
        }
    }

    printf("Número de alunos maiores de idade: %d\n", maiores);

    fclose(arq);
}

int main() {
    apresentacao();
    lerIdades();
    return 0;
}
