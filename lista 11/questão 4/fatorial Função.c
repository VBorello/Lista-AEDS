#include <stdio.h>

void apresentacao(){
    printf("\nFatorial Funacao\n\n");
}

int leiaNum(){
    int num;
    printf("digite o numero que deseja saber o fatorial:");
    scanf("%d", &num);

    return num;
}


int fatorial(int x) {
  int res;
  if(x <= 1){
    res = 1;
  }
  else{
    res = x * (fatorial(x - 1));
  }

  return res;
}

int main(){

    apresentacao();
    int num = leiaNum();

    int resultado = fatorial(num);
    printf("o fatoria de %d e igaual a: %d", num, resultado);

    return 0;
}


