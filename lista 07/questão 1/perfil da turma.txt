#include <stdio.h>
#include <stdbool.h>

int main() 
{
  printf("\nPerfil da Turma\n\n");

    bool erro;
    int alunos, idade, mais_velho = 0, mais_novo = 0, f = 0, m = 0;
    float maior_idade = 0;
    char sexo;
  
    do{
    printf("Quantos são os alunos:");
    scanf("%d", &alunos);
    erro = alunos < 0;
      if(erro) {
        printf("valor invalido");
      }
    } while (erro);
  
    for (int i = 0; i < alunos; i++) {
      
        do {
            printf("Informe o sexo do aluno %d (f/m):", i + 1);
            scanf(" %c", &sexo);
            erro = sexo != 'm' && sexo != 'f';
            if (erro) {
                printf("sexo invalido\n");
            }
        } while (erro);

        if (sexo == 'm') {
              m++; 
        } else {
              f++; 
        }   

          do { 
              printf("informe a idade do aluno %d:", i + 1);
              scanf("%d", &idade);
              erro = idade <= 0;
              if (erro) {
                  printf("idade invalida\n");
              }
          } while (erro);
      

          if (idade >= 18) {
              maior_idade++;
          }
          if (idade > mais_velho) {
              mais_velho = idade;
          }
          if (idade < mais_novo) {
              mais_novo = idade;
          }
      }
  
    float percentual_h = (float) m / alunos * 100;
    float percentual_f = (float) f / alunos * 100;
    float percentual_maior_idade = maior_idade / alunos * 100;

    printf("percentual masculino: %.2f%%\n", percentual_h);
    printf("percentual feminino: %.2f%%\n", percentual_f);
    printf("percentual maioridade: %.2f%%\n", percentual_maior_idade);
    printf("mais velho: %d\n", mais_velho);
    printf("mais novo: %d\n", mais_novo);

  return 0;

}