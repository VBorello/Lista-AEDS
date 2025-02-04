#include <stdio.h>
#include <stdlib.h>

int main()
    {
    printf("Impar ou Par?\n\n");

    int a;
    char continuar;
    continuar = 's';  

    while (continuar == 's' || continuar == 'S')
    {  
    printf("Insira o numero:");
    scanf("%i",&a);

    if(a% 2 == 0){
    printf("o numero: %i e par",a);
    }
    else {
    printf("o numero:%.2i e impar",a);
    }  
      printf("\n\nDeseja continuar (s/n):");
      scanf(" %c", &continuar);
    }
    return 0;

}