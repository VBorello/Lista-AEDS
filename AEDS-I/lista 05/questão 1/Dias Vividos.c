#include <stdio.h>
#include <math.h>

//A função sqrt retorna a raiz quadrada de x . Por padrão, se x for um valor negativo, sqrt retornará um NaN indefinido. Achando a raiz quadrada de int, double, long double e float.


int main() {
    printf("\nCalculadora de equações 2grau\n");

    float delta, a, b, c, x1, x2;
    char continuar;
    continuar = 's';
  
    while (continuar == 's' || continuar == 'S')
    {  
    printf("\nDigite os coeficientes da equação:(ax^2 + bx + c)\n");
    printf("a:");  
    scanf(" %f", &a);
    printf("b:");
    scanf(" %f", &b);
    printf("c:");
    scanf(" %f", &c);

    delta = b*b - 4*a*c;
    if(delta > 0)
    {                    
    x1 = (-b + sqrt(delta)) / (2*a);
    x2 = (-b - sqrt(delta)) / (2*a);
    printf("As raizes sao: x1 = %.2f e x2 = %.2f\n", x1, x2);
    } 
    else if(delta == 0) 
    {
    x1 = -b / (2*a);
    printf("As raizes sao reais e iguais: x1 = x2 = %.2f\n", x1);
    }
    else  
    {      
    printf("\n Nao existem raizes reais\n");
    }  
    printf ("deseja fazer outra equação? (S/N):");
    scanf(" %c", &continuar);
    }
  
  return 0;
}