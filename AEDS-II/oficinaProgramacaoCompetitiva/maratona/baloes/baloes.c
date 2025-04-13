#include <stdio.h>
#include <math.h>
 
int main() {
 
    int raio;
    int helio;
    
    scanf("%d %d", &raio, &helio);
    
    double volume = (4.0/3.0) * 3.1415 * pow(raio, 3);
    int baloes = helio/ volume;

    printf("%d\n", baloes);
 
    return 0;
}