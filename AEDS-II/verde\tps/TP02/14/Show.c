#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000
#define TAM_CAMPO 200
#define MATRICULA "802305"

typedef struct {
    char show_id[TAM_CAMPO];
    char type[TAM_CAMPO];
    char title[TAM_CAMPO];
    char director[TAM_CAMPO];
    char cast[5][TAM_CAMPO];
    int qtd_cast;
    char country[TAM_CAMPO];
    char date_added[TAM_CAMPO];
    int dia, mes, ano;
    int release_year;
    char rating[TAM_CAMPO];
    char duration[TAM_CAMPO];
    char listed_in[5][TAM_CAMPO];
    int qtd_listed;
} Show;

void parseData(char *data, int *dia, int *mes, int *ano) {
    if (strcmp(data, "") == 0) {
        *dia = 1;
        *mes = 1;
        *ano = 1900;
        return;
    }
    char mesStr[TAM_CAMPO];
    sscanf(data, "%[^ ] %d, %d", mesStr, dia, ano);

    char *meses[] = {"January","February","March","April","May","June",
                     "July","August","September","October","November","December"};
    for (int i = 0; i < 12; i++) {
        if (strcmp(mesStr, meses[i]) == 0) {
            *mes = i + 1;
            return;
        }
    }
    *mes = 1;
}

void lerShow(char *linha, Show *s) {
    char *campos[12];
    int i = 0, dentroAspas = 0;
    char *token = malloc(strlen(linha) + 1);
    strcpy(token, linha);
    char *p = token;
    campos[i] = p;
    while (*p) {
        if (*p == '"') dentroAspas = !dentroAspas;
        else if (*p == ',' && !dentroAspas) {
            *p = '\0';
            campos[++i] = p + 1;
        }
        p++;
    }

    strcpy(s->show_id, campos[0]);
    strcpy(s->type, campos[1]);
    strcpy(s->title, campos[2]);
    strcpy(s->director, strlen(campos[3]) == 0 ? "NaN" : campos[3]);

    s->qtd_cast = 0;
    if (strlen(campos[4]) == 0) {
        strcpy(s->cast[0], "NaN");
        s->qtd_cast = 1;
    } else {
        char *token_cast = strtok(campos[4], ",");
        while (token_cast && s->qtd_cast < 5) {
            while (*token_cast == ' ') token_cast++;
            strcpy(s->cast[s->qtd_cast++], token_cast);
            token_cast = strtok(NULL, ",");
        }
    }

    strcpy(s->country, strlen(campos[5]) == 0 ? "NaN" : campos[5]);
    strcpy(s->date_added, strlen(campos[6]) == 0 ? "March 1, 1900" : campos[6]);
    parseData(s->date_added, &s->dia, &s->mes, &s->ano);

    s->release_year = atoi(campos[7]);
    strcpy(s->rating, strlen(campos[8]) == 0 ? "NaN" : campos[8]);
    strcpy(s->duration, strlen(campos[9]) == 0 ? "NaN" : campos[9]);

    s->qtd_listed = 0;
    if (strlen(campos[10]) == 0) {
        strcpy(s->listed_in[0], "NaN");
        s->qtd_listed = 1;
    } else {
        char *token_listed = strtok(campos[10], ",");
        while (token_listed && s->qtd_listed < 5) {
            while (*token_listed == ' ') token_listed++;
            strcpy(s->listed_in[s->qtd_listed++], token_listed);
            token_listed = strtok(NULL, ",");
        }
    }

    free(token);
}

void imprimir(Show s) {
    printf("=> %s ## %s ## %s ## %s ## [", s.show_id, s.title, s.type, s.director);
    for (int i = 0; i < s.qtd_cast; i++) {
        printf("%s", s.cast[i]);
        if (i < s.qtd_cast - 1) printf(", ");
    }
    printf("] ## %s ## %s ## %d ## %s ## %s ## [", s.country, s.date_added, s.release_year, s.rating, s.duration);
    for (int i = 0; i < s.qtd_listed; i++) {
        printf("%s", s.listed_in[i]);
        if (i < s.qtd_listed - 1) printf(", ");
    }
    printf("] ##\n");
}

int maxReleaseYear(Show *v, int n) {
    int max = v[0].release_year;
    for (int i = 1; i < n; i++) {
        if (v[i].release_year > max)
            max = v[i].release_year;
    }
    return max;
}

void countingSortPorDigito(Show *v, int n, int exp, int *comp, int *mov) {
    Show output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digito = (v[i].release_year / exp) % 10;
        count[digito]++;
    }

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digito = (v[i].release_year / exp) % 10;
        output[--count[digito]] = v[i];
        (*mov) += 3;
    }

    for (int i = 0; i < n; i++) v[i] = output[i];
}

void desempatePorTitulo(Show *v, int n, int *comp, int *mov) {
    for (int i = 1; i < n; i++) {
        Show chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].release_year == chave.release_year && strcmp(v[j].title, chave.title) > 0) {
            (*comp)++;
            v[j + 1] = v[j];
            (*mov) += 3;
            j--;
        }
        v[j + 1] = chave;
        (*mov) += 3;
    }
}

void radixSort(Show *v, int n, int *comp, int *mov) {
    int max = maxReleaseYear(v, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortPorDigito(v, n, exp, comp, mov);

    desempatePorTitulo(v, n, comp, mov);
}

int main() {
    char entrada[MAX][TAM_CAMPO];
    int n = 0;
    while (1) {
        fgets(entrada[n], TAM_CAMPO, stdin);
        entrada[n][strcspn(entrada[n], "\n")] = 0;
        if (strcmp(entrada[n], "FIM") == 0) break;
        n++;
    }

    FILE *arq = fopen("/tmp/disneyplus.csv", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[1000];
    fgets(linha, 1000, arq);

    Show lista[MAX];
    int total = 0;

    while (fgets(linha, 1000, arq)) {
        for (int i = 0; i < n; i++) {
            if (strncmp(linha, entrada[i], strlen(entrada[i])) == 0 && linha[strlen(entrada[i])] == ',') {
                lerShow(linha, &lista[total++]);
                break;
            }
        }
    }

    fclose(arq);

    int comp = 0, mov = 0;
    clock_t inicio = clock();
    radixSort(lista, total, &comp, &mov);
    clock_t fim = clock();

    for (int i = 0; i < total; i++) imprimir(lista[i]);

    double tempo = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    FILE *log = fopen("matricula_radixsort.txt", "w");
    fprintf(log, "%s\t%d\t%d\t%.0lf\n", MATRICULA, comp, mov, tempo);
    fclose(log);

    return 0;
}
