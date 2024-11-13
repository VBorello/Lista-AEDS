#include <stdio.h>
#include <stdlib.h>

int contarNumeros(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int count = 0;
    double temp;
    while (fscanf(arquivo, "%lf", &temp) == 1) {
        count++;
    }

    fclose(arquivo);
    return count;
}

double *lerNumeros(const char *nomeArquivo, int quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    double *numeros = (double *)malloc(quantidade * sizeof(double));
    if (!numeros) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return NULL;
    }

    for (int i = 0; i < quantidade; i++) {
        fscanf(arquivo, "%lf", &numeros[i]);
    }

    fclose(arquivo);
    return numeros;
}

double calcularMedia(double *numeros, int quantidade) {
    double soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += numeros[i];
    }
    return soma / quantidade;
}

int contarMenoresQueMedia(double *numeros, int quantidade, double media) {
    int count = 0;
    for (int i = 0; i < quantidade; i++) {
        if (numeros[i] < media) {
            count++;
        }
    }
    return count;
}

void processarArquivo(const char *nomeArquivo) {
    int quantidade = contarNumeros(nomeArquivo);
    if (quantidade <= 0) {
        printf("O arquivo não contém números válidos ou ocorreu um erro.\n");
        return;
    }

    double *numeros = lerNumeros(nomeArquivo, quantidade);
    if (!numeros) {
        return;
    }

    double media = calcularMedia(numeros, quantidade);
    int menores = contarMenoresQueMedia(numeros, quantidade, media);

    printf("Média: %.2lf\n", media);
    printf("Número de valores menores que a média: %d\n", menores);

    free(numeros);
}

int main() {
    const char *nomeArquivo = "dados.txt"; 
    processarArquivo(nomeArquivo);
    return 0;
}
