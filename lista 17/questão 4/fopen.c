#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nAprendendo Sobre arquivos\n\n");
}
int main()
{
    apresentacao();
    FILE* arc = fopen("teste.dat", "r");
    int idadePai, idadeMae;
        scanf("%d", &idadePai);
        fprintf(arc,"%d", idadePai);
        scanf("%d", &idadeMae);
        fprintf(arc,"%d", idadeMae);
    fclose(arc);

    return 0;
}   