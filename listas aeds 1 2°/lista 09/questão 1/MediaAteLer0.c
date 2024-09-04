#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nMédia até ler 0\n\n");
}

void lerValores(int** valor){
    while(valor != 0){
        printf("Digite o %d termo:");
        scanf("%d", &valor);
    }
}

int calcularMedia(int** valor){
    int total = 0;    
    
    while (valor != 0){
        total += valor[i];
    }
    
}

int main(){

}