
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1000
#define K 10

typedef struct {
    char show_id[20];
    char type[100];
    char title[300];
    char director[200];
    char cast[500];
    char country[100];
    char date_added[100];
    int release_year;
    char rating[20];
    char duration[50];
    char listed_in[300];
} Show;

void trim(char *str) {
    char *start = str;
    while (*start == ' ' || *start == '\n' || *start == '\r') start++;
    if (start != str) memmove(str, start, strlen(start) + 1);

    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n' || *end == '\r')) *end-- = '\0';
}

void tratarCampo(char *campo) {
    trim(campo);
    if (strlen(campo) == 0) strcpy(campo, "NaN");
}

void lerShow(char *linha, Show *s) {
    char *token;
    token = strtok(linha, ",");
    strcpy(s->show_id, token ? token : "NaN");

    token = strtok(NULL, ",");
    strcpy(s->type, token ? token : "NaN");

    token = strtok(NULL, ",");
    strcpy(s->title, token ? token : "NaN");

    token = strtok(NULL, ",");
    strcpy(s->director, token ? token : "NaN");

    token = strtok(NULL, ",");
    strcpy(s->cast, token ? token : "NaN");

    token = strtok(NULL, ",");
    strcpy(s->country, token ? token : "NaN");

    token = strtok(NULL, ",");
    if (token) trim(token);
    strcpy(s->date_added, (token && strlen(token) > 0) ? token : "March 1, 1900");

    token = strtok(NULL, ",");
    s->release_year = token ? atoi(token) : 0;

    token = strtok(NULL, ",");
    strcpy(s->rating, token ? token : "NaN");

    token = strtok(NULL, ",");
    strcpy(s->duration, token ? token : "NaN");

    token = strtok(NULL, ",");
    strcpy(s->listed_in, token ? token : "NaN");

    tratarCampo(s->show_id);
    tratarCampo(s->type);
    tratarCampo(s->title);
    tratarCampo(s->director);
    tratarCampo(s->cast);
    tratarCampo(s->country);
    tratarCampo(s->date_added);
    tratarCampo(s->rating);
    tratarCampo(s->duration);
    tratarCampo(s->listed_in);
}

void imprimirShow(Show s) {
    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
           s.show_id, s.title, s.type, s.director, s.cast, s.country, s.date_added,
           s.release_year, s.rating, s.duration, s.listed_in);
}

void insertionSort(Show array[], int n, int *comp, int *mov) {
    for (int i = 1; i < n; i++) {
        Show temp = array[i];
        int j = i - 1;
        while (j >= 0 && (array[j].release_year > temp.release_year ||
                         (array[j].release_year == temp.release_year &&
                          strcmp(array[j].title, temp.title) > 0))) {
            (*comp)++;
            array[j + 1] = array[j];
            (*mov)++;
            j--;
        }
        (*comp)++;
        array[j + 1] = temp;
        (*mov)++;
    }
}

int main() {
    FILE *fp = fopen("/tmp/disneyplus.csv", "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Show lista[K];
    int count = 0;
    char linha[1000];
    char entrada[20];
    char *todasLinhas[MAX];
    int total = 0;

    // Ler todas as linhas do CSV
    while (fgets(linha, sizeof(linha), fp) && total < MAX) {
        todasLinhas[total] = strdup(linha);
        total++;
    }
    fclose(fp);

    // Ler entradas
    while (scanf("%s", entrada) && strcmp(entrada, "FIM") != 0 && count < K) {
        for (int i = 0; i < total; i++) {
            if (strstr(todasLinhas[i], entrada)) {
                lerShow(todasLinhas[i], &lista[count++]);
                break;
            }
        }
    }

    clock_t inicio = clock();
    int comp = 0, mov = 0;
    insertionSort(lista, count, &comp, &mov);
    clock_t fim = clock();

    for (int i = 0; i < count; i++) {
        imprimirShow(lista[i]);
    }

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    FILE *log = fopen("matricula_insercao.txt", "w");
    fprintf(log, "812313	%d	%d	%.6f", comp, mov, tempo);
    fclose(log);

    for (int i = 0; i < total; i++) free(todasLinhas[i]);
    return 0;
}
