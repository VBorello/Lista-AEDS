#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nintrodução Tp\n\n");
}

void criarArq(){

    FILE* arq = fopen("novo.dat", "w");

    int pai, mae, eu;
    printf("Digite a idade do seu paei e sua mae: ");
    scanf("%d %d %d", &pai, &mae, &eu);

    fwrite(&pai, sizeof(int), 1, arq);
    fwrite(&mae, sizeof(int), 1, arq);  
    fwrite(&eu, sizeof(int), 1, arq); 

    fclose(arq); 

    arq = fopen("novo.dat", "r");

    int valores;

    while(fread(&valores, sizeof(int), 1, arq) != 0){
        printf("%d\n", valores);
    }

    fclose(arq);
}

int main(){
    apresentacao();

    criarArq();

    return 0;
}