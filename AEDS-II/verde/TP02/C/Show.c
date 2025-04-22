#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_LINHA 1024
#define MAX_CAMPOS 12
#define TAM_MAX_LISTA 100
#define MAX_SHOWS 5000

typedef struct{
    char *SHOW_ID;
    char *TYPE;
    char *TITLE;
    char **DIRECTOR;
    int DIRECTOR_COUNT;
    char **CAST;
    int CAST_COUNT;
    char *COUNTRY;
    char *DATE_ADDED;
    int RELEASE_YEAR;
    char *RATING;
    char *DURATION;
    char **LISTED_IN;
    int LISTED_COUNT;
} Show;

char *CLONE(const char *s){
    char *copy = malloc(strlen(s) + 1);
    if (copy) strcpy(copy, s);
    return copy;
}

char **split_lista(const char *str, int *qtd){
    char **lista = malloc(TAM_MAX_LISTA * sizeof(char *));
    *qtd = 0;
    char *aux = CLONE(str);
    char *token = strtok(aux, ",");
    while (token != NULL && *qtd < TAM_MAX_LISTA){
        while (*token == ' ') token++;
        lista[(*qtd)++] = CLONE(token);
        token = strtok(NULL, ",");
    }
    free(aux);
    return lista;
}

void ordenar_lista(char **lista, int tamanho){
    for (int i = 0; i < tamanho - 1; i++){
        for (int j = 0; j < tamanho - i - 1; j++){
            if (strcmp(lista[j], lista[j + 1]) > 0){
                char *temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int LER_LINHA(char *linha, Show *s){
    char *campos[MAX_CAMPOS];
    int index_campos = 0;
    char buffer[TAM_LINHA];
    int index_buffer = 0;
    int entreAspas = 0;

    for (int i = 0; linha[i] != '\0'; i++){
        if (linha[i] == '"'){
            entreAspas = !entreAspas;
        } else if (linha[i] == ',' && !entreAspas){
            buffer[index_buffer] = '\0';
            campos[index_campos] = CLONE(buffer);
            index_buffer = 0;
            index_campos++;
            if (index_campos >= MAX_CAMPOS) break;
        } else{
            buffer[index_buffer++] = linha[i];
        }
    }
    buffer[index_buffer] = '\0';
    campos[index_campos++] = CLONE(buffer);

    if (index_campos < 11) return 0;

    s -> SHOW_ID = campos[0];
    s -> TYPE = campos[1];
    s -> TITLE = campos[2];

    s -> DIRECTOR = split_lista(campos[3], &s -> DIRECTOR_COUNT);
    ordenar_lista(s -> DIRECTOR, s -> DIRECTOR_COUNT);

    s -> CAST = split_lista(campos[4], &s -> CAST_COUNT);
    ordenar_lista(s -> CAST, s -> CAST_COUNT);

    s -> COUNTRY = campos[5];
    s -> DATE_ADDED = campos[6];
    s -> RELEASE_YEAR = atoi(campos[7]);
    s -> RATING = campos[8];
    s -> DURATION = campos[9];

    s -> LISTED_IN = split_lista(campos[10], &s -> LISTED_COUNT);
    ordenar_lista(s -> LISTED_IN, s -> LISTED_COUNT);

    return 1;
}

void print_lista(char **lista, int qtd){
    if (qtd == 0){
        printf("NaN");
    } else{
        for (int i = 0; i < qtd; i++){
            if (i > 0) printf(", ");
            printf("%s", lista[i]);
        }
    }
}

void print_show(Show *s){
    printf("=> %s ## %s ## %s ## ", s -> SHOW_ID, s -> TITLE, s -> TYPE);
    print_lista(s -> DIRECTOR, s -> DIRECTOR_COUNT);
    printf(" ## [");
    print_lista(s -> CAST, s -> CAST_COUNT);
    printf("] ## %s ## %s ## ", s -> COUNTRY, s -> DATE_ADDED);

    if (s -> RELEASE_YEAR != -1)
        printf("%d ## ", s -> RELEASE_YEAR);
    else
        printf("NaN ## ");

    printf("%s ## %s ## [", s -> RATING, s -> DURATION);
    print_lista(s -> LISTED_IN, s -> LISTED_COUNT);
    printf("] ##\n");
}

int main(){
    FILE *arq = fopen("/tmp/disneyplus.csv", "r");

    if (!arq){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    Show shows[MAX_SHOWS];
    int show_qtd = 0;
    char linha[TAM_LINHA];

    fgets(linha, TAM_LINHA, arq); // Pular cabeçalho

    while (fgets(linha, TAM_LINHA, arq) && show_qtd < MAX_SHOWS){
        if (LER_LINHA(linha, &shows[show_qtd])){
            show_qtd++;
        }
    }
    fclose(arq);

    char entrada[20];
    scanf("%s", entrada);

    while (strcmp(entrada, "FIM") != 0){
        int found = 0;
        for (int i = 0; i < show_qtd; i++){
            if (strcmp(shows[i].SHOW_ID, entrada) == 0){
                print_show(&shows[i]);
                found = 1;
                break;
            }
        }
        if (!found) printf("Show n\xC3\xA3o encontrado.\n");
        scanf("%s", entrada);
    }

    return 0;
}
