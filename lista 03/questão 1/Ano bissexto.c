#include <stdio.h>

int main() {
  printf("O ano e bissexto?\n\n");

  int ano;
  char continuar = 's';

  while (continuar == 's' || continuar == 'S') {
    printf("\n informe o ano:\n");
    scanf("%d", &ano);
    if (ano % 4 == 0 && ano % 400 == 0 && ano % 100 == 0) {
      printf("o ano:%.2i não e bissexto", ano);
    } else {
      printf("o anos:%.2i e bisexto", ano);
    }
    printf("\n deseja continuar? (S/N):\n");
    scanf(" %c", &continuar);
  }
}