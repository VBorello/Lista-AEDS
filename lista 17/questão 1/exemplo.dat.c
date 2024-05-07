#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nAprendendo Sobre arquivos\n\n");
}
int main()
{
    apresentacao();
    FILE* arc = fopen("teste.dat", "w");
    fclose(arc);

    return 0;
}