#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 1000
#define MAX_CAMPOS 20

typedef struct {
    char show_id[20];
    char tipo[20];
    char titulo[200];
    char diretor[200];
    char elenco[500];
    char pais[100];
    char data_adicionada[50];
    int ano_lancamento;
    char classificacao[10];
    int duracao;
    char tipo_duracao[20];
    char generos[200];
} SHOW;

void ler(char* linha, SHOW* s) {
    char* atributos[MAX_CAMPOS];
    int i = 0, tamCampo = 0, dentroAspas = 0;
    char* campo = malloc(MAX_LINHA);
    
    for (int j = 0; ; j++) {
        char c = linha[j];

        if (c == '"') {
            dentroAspas = !dentroAspas;
        } else if ((c == ',' && !dentroAspas) || c == '\0' || c == '\n') {
            campo[tamCampo] = '\0';

            // Remove aspas externas
            if (campo[0] == '"' && campo[strlen(campo) - 1] == '"') {
                campo[strlen(campo) - 1] = '\0';
                atributos[i] = strdup(campo + 1);
            } else {
                atributos[i] = strdup(campo);
            }

            i++;
            tamCampo = 0;

            if (c == '\0' || c == '\n') break;
        } else {
            campo[tamCampo++] = c;
        }
    }

    free(campo);

    strcpy(s->show_id, atributos[0]);
    strcpy(s->tipo, atributos[1]);
    strcpy(s->titulo, atributos[2]);
    strcpy(s->diretor, strcmp(atributos[3], "NaN") == 0 ? "" : atributos[3]);
    strcpy(s->elenco, strcmp(atributos[4], "NaN") == 0 ? "" : atributos[4]);
    strcpy(s->pais, strcmp(atributos[5], "NaN") == 0 ? "" : atributos[5]);
    strcpy(s->data_adicionada, strcmp(atributos[6], "NaN") == 0 ? "" : atributos[6]);
    s->ano_lancamento = strcmp(atributos[7], "NaN") == 0 ? -1 : atoi(atributos[7]);
    strcpy(s->classificacao, strcmp(atributos[8], "NaN") == 0 ? "" : atributos[8]);

    if (strcmp(atributos[9], "NaN") == 0) {
        s->duracao = -1;
        strcpy(s->tipo_duracao, "");
    } else {
        int dur = atoi(atributos[9]);
        s->duracao = dur;
        int k = 0;
        while (atributos[9][k] >= '0' && atributos[9][k] <= '9') k++;
        strcpy(s->tipo_duracao, atributos[9][k] ? atributos[9] + k : "");
    }

    strcpy(s->generos, strcmp(atributos[10], "NaN") == 0 ? "" : atributos[10]);

    for (int k = 0; k < i; k++) {
        free(atributos[k]);
    }
}

void imprimir(SHOW s) {
    printf("%s %s %s %s %s %s %s %d %s %d %s %s\n",
        s.show_id,
        s.tipo,
        s.titulo,
        s.diretor,
        s.elenco,
        s.pais,
        s.data_adicionada,
        s.ano_lancamento,
        s.classificacao,
        s.duracao,
        s.tipo_duracao,
        s.generos);
}

int main() {
    char linha[MAX_LINHA * 10]; // espaço maior para juntar linhas com quebras
    char temp[MAX_LINHA];
    linha[0] = '\0';

    while (fgets(temp, MAX_LINHA, stdin)) {
        if (strncmp(temp, "FIM", 3) == 0)
            break;

        strcat(linha, temp);

        // Conta aspas para ver se fechou
        int aspas = 0;
        for (int i = 0; linha[i]; i++) {
            if (linha[i] == '"') aspas++;
        }

        if (aspas % 2 == 0) {
            SHOW s;
            ler(linha, &s);
            imprimir(s);
            linha[0] = '\0'; // limpa para próxima
        }
    }

    return 0;
}
