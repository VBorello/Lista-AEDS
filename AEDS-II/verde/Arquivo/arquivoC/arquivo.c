#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    FILE *arquivo = fopen("arq.txt", "wb");
    
    int n;
    int inteiro;
    double num;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lf", &num);
        fwrite(&num, sizeof(double), 1, arquivo);
    }

    fclose(arquivo);

    arquivo = fopen("arq.txt", "rb");

    fseek(arquivo, 0, SEEK_END);
    long pos = ftell(arquivo);
    fseek(arquivo, pos, SEEK_SET);

    while(pos >= sizeof(double)){
        
        pos -= sizeof(double);
        fseek(arquivo, pos, SEEK_SET);
        fread(&num, sizeof(double), 1, arquivo);

        inteiro = (int)num;

        if(inteiro - num == 0){
            printf("%d\n", inteiro);
        }
        else{
            printf("%g\n", num);
        }
    }

    fclose(arquivo);

    return 0;
}