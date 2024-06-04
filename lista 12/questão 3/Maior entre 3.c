#include <stdio.h>

void apresentacao(){
    printf("\nmaior numero entre 3\n\n");
}
float leiaNum(){
    float num;
    printf("Digite um valor:");
    scanf("%f", &num);
    return num;
}
void ordenarNum(float *a,float *b,float *c){
    if(*a > *b){
        float temp = *a;
        *a = *b;
        *b = temp;
    }
    else if(*b > *c){
        float temp = *b;
        *b = *c;
        *c = temp;
    }
    if(*a > *b){
        float temp = *a;
        *a = *b;
        *b = temp;
    }
}
void escrevaResultado(float segundoMaior){
    printf("O segundo maior numero e: %.2f", segundoMaior);
} 
int main(){    

    apresentacao();
    
    float num1, num2, num3;
    num1 = leiaNum();
    num2 = leiaNum();
    num3 = leiaNum();

    ordenarNum(&num1, &num2, &num3);

    float segundoMaior = num2;

    escrevaResultado(segundoMaior);

 return 0;
}