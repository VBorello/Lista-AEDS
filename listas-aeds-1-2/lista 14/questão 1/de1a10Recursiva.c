#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nDe 1 a 10 função recursiva\n\n");
}

void umADez(int i){
    
    if(i <= 10){
        printf("%d ", i);
        umADez(i + 1);
    }
}

int main(){
    apresentacao();
    int i = 1;

    umADez(i);

    return 0;
}