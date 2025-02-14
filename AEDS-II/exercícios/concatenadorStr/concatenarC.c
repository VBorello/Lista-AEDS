#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nConcatenador\n");
}

int main(){

    char string1[100];
    char string2[100];

    do{
        scanf("%s %s", string1, string2);
        printf("%s%s\n", string1, string2 );
    }while(string1[0] != 'F' && string1[1] != 'I' && string1[2] != 'M');

    return 0;
}