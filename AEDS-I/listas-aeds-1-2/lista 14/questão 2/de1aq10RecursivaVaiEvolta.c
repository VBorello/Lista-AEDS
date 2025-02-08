#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nDe 1 a 10 função recursiva\n\n");
}

void umADez(int i){

    printf("%d ", i);

    if(i < 10){
        umADez(i + 1);
        printf("%d ", i);
    }
}

int main(){
    apresentacao();

    int i = 0;
    umADez(i);

    return 0;
}