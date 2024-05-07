#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nCalculador de Peso Ideal\n");
    float altura,peso;
    char sexo, continuar;
      
    printf("\n informe o sexo:(F/M)");
    scanf("%c",&sexo);
    printf("\n informe a altura:");
    scanf("%f",&altura);

    if(sexo=='F' || sexo=='f') {
    peso=(62.1*altura)-44.7; }
    else if(sexo=='M' || sexo=='m') {
        peso=(72.2*altura)-58; }
        
    printf("\n seu peso edeal e:%2.f",peso);
  
    return 0;

}
