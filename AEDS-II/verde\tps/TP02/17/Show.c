#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000
#define TAM 200
#define K 10
#define MATRICULA "802305"

typedef struct {
    char show_id[TAM];
    char type[TAM];
    char title[TAM];
    char director[TAM];
    char cast[5][TAM];
    int qtd_cast;
    char country[TAM];
    char date_added[TAM];
    int dia, mes, ano;
    int release_year;
    char rating[TAM];
    char duration[TAM];
    char listed_in[5][TAM];
    int qtd_listed;
} Show;

void parseData(char *data, int *dia, int *mes, int *ano) {
    if (strcmp(data, "") == 0) { *dia = 1; *mes = 1; *ano = 1900; return; }
    char mesStr[TAM];
    sscanf(data, "%[^ ] %d, %d", mesStr, dia, ano);
    char *meses[] = {"January","February","March","April","May","June",
                     "July","August","September","October","November","December"};
    for (int i = 0; i < 12; i++) if (strcmp(mesStr, meses[i]) == 0) { *mes = i + 1; return; }
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

int comparar(Show a, Show b, int *comp) {
    (*comp)++;
    if (a.release_year != b.release_year)
        return a.release_year - b.release_year;
    return strcmp(a.title, b.title);
}

void swap(Show *a, Show *b, int *mov) {
    Show tmp = *a;
    *a = *b;
    *b = tmp;
    (*mov) += 3;
}

void heapifyMin(Show *v, int n, int i, int *comp, int *mov) {
    int menor = i;
    int esq = 2*i + 1, dir = 2*i + 2;
    if (esq < n && comparar(v[esq], v[menor], comp) < 0)
        menor = esq;
    if (dir < n && comparar(v[dir], v[menor], comp) < 0)
        menor = dir;
    if (menor != i) {
        swap(&v[i], &v[menor], mov);
        heapifyMin(v, n, menor, comp, mov);
    }
}

void buildMinHeap(Show *v, int n, int *comp, int *mov) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(v, n, i, comp, mov);
}

void heapifyMax(Show *v, int n, int i, int *comp, int *mov) {
    int maior = i;
    int esq = 2*i + 1, dir = 2*i + 2;
    if (esq < n && comparar(v[esq], v[maior], comp) > 0)
        maior = esq;
    if (dir < n && comparar(v[dir], v[maior], comp) > 0)
        maior = dir;
    if (maior != i) {
        swap(&v[i], &v[maior], mov);
        heapifyMax(v, n, maior, comp, mov);
    }
}

void heapSortParcial(Show *v, int n, int *comp, int *mov) {
    Show heap[K];
    int tam = 0;

    // Preenche os primeiros K elementos no heap mínimo
    for (int i = 0; i < n; i++) {
        if (tam < K) {
            heap[tam++] = v[i];
            (*mov) += 3;
            if (tam == K) buildMinHeap(heap, K, comp, mov);
        } else if (comparar(v[i], heap[0], comp) > 0) {
            heap[0] = v[i];
            (*mov) += 3;
            heapifyMin(heap, K, 0, comp, mov);
        }
    }

    // Ordenar o heap final (k maiores)
    for (int i = K/2 - 1; i >= 0; i--)
        heapifyMax(heap, K, i, comp, mov);

    for (int i = K-1; i > 0; i--) {
        swap(&heap[0], &heap[i], mov);
        heapifyMax(heap, i, 0, comp, mov);
    }

    // Copia os k maiores ordenados para início do vetor
    for (int i = 0; i < K; i++) {
        v[i] = heap[i];
        (*mov) += 3;
    }
}

int main() {
    char entrada[MAX][TAM];
    int n = 0;
    while (1) {
        fgets(entrada[n], TAM, stdin);
        entrada[n][strcspn(entrada[n], "\n")] = 0;
        if (strcmp(entrada[n], "FIM") == 0) break;
        n++;
    }

    FILE *arq = fopen("/tmp/disneyplus.csv", "r");
    if (!arq) return 1;
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
    heapSortParcial(lista, total, &comp, &mov);
    clock_t fim = clock();

    for (int i = 0; i < K && i < total; i++) imprimir(lista[i]);

    double tempo = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    FILE *log = fopen("matricula_heapsort_parcial.txt", "w");
    fprintf(log, "%s\t%d\t%d\t%.0lf\n", MATRICULA, comp, mov, tempo);
    fclose(log);

    return 0;
}
