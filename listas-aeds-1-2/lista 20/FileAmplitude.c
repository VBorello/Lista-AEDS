#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nAmplitude de reais gravados em um arquivo em binário\n\n");
}

void gerarArquivo(const char* nomeArquivo) { //const para não rodar caso a variavel ser alterada
    
    FILE* arquivo = fopen(nomeArquivo, "wb");  //Cria um fluxo para escrita no arquivo
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo\n");
        return;
    }

    int quantidade;
    printf("\nQuantos valores reais você deseja inserir? ");
    scanf("%d", &quantidade);

    float valores;

    for (int i = 0; i < quantidade; i++) {
        printf("Digite o valor real %d: ", i + 1);
        scanf("%f", &valores);
        fwrite(&valores, sizeof(float), 1, arquivo);  //para escrever os numeros lidos em binário
    }   //parametros(variavel a armazenar os numeros, tipo, 1(quantidade de termos que está 1 por estar em um for(gravar um em cada repetição)), arquivo onde será escrito).

    fclose(arquivo);
    printf("Arquivo %s gerado com sucesso.\n", nomeArquivo);
}

float calcularAmplitude(FILE* arquivo) {
    
    float valor;
    float maior = -100000; 
    float menor = 100000;  

    while (fread(&valor, sizeof(float), 1, arquivo) !=0) {
        if (valor > maior) {
            maior = valor;
        }
        if (valor < menor) {
            menor = valor;
        }
    }

    return maior - menor;
}

void lerNomeArquivo(char* nomeArquivo){

    printf("Digite o nome do arquivo: ");
    scanf(" %s", nomeArquivo);
}

int main(){

    apresentacao();
    
    char nome[100];

    lerNomeArquivo(nome);
    
    gerarArquivo(nome);

    FILE* arquivo = fopen(nome, "rb"); //Abrindo o arquivo para leitura em binário

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    float amplitude = calcularAmplitude(arquivo);
    printf("\nA amplitude dos valores no arquivo é: %.2f\n", amplitude);

    fclose(arquivo);

    return 0;
}
