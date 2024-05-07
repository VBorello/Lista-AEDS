#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("\nAprovação / Reprovação\n");

    int n, aprovados = 0, reprovados = 0;
    bool erro;
    float amplitude, soma = 0, nota, maior = 0, menor = 100; // nota 
    
    do {
        printf("\nNumero de alunos: ");
        scanf("%d", &n);
        erro = n <= 0;
        if (erro) {
            printf("Valor invalido\n");
        }
    } while (erro);
  
    for (int i = 0; i < n; i++) {
        do {
            printf("\nDigite uma nota: ");
            scanf("%f", &nota);
            erro = nota < 0 && nota > 100;
            if (erro) {
                printf("Valor invalido\n");
            }
        } while (erro);

        if (nota >= 60) {
            printf("aprovado\n");
          aprovados++;
        } else {
            printf("reprovado\n");
          reprovados++;
      }

        soma += nota; 
        if (nota > maior) {
            maior = nota;
        }
        if (nota < menor) {
            menor = nota;
        }
    }
  
    float percentual_aprovado = (float) aprovados / n * 100;
    float percentual_reprovado = (float) reprovados / n * 100;
    float media = soma / n;
    amplitude = maior - menor;
  
    printf("\nmaior: %.2f\n", maior);
    printf("menor: %.2f\n", menor);
    printf("amplitude: %.2f\n", amplitude);
    printf("media: %.2f\n", media);
    printf("Reprovados: %.2f%%\n", percentual_reprovado);
    printf("Aprovados: %.2f%%\n", percentual_aprovado);
  
    return 0;
}