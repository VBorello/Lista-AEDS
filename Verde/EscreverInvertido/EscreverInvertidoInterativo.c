#include <stdio.h>

int escreveInvertido(int x){
    
    int invertido = 0;
    
    while(x != 0){
        invertido = invertido * 10 + (x % 10);
        x = x / 10; 
    }

    return invertido;
}


int main(){

    int x=12345;
    int xInvertido = escreveInvertido(x);

    printf("%d", xInvertido);

    return 0;
}