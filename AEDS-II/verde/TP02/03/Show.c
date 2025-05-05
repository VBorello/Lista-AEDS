#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SHOWS 3000
#define MAX_LINE 1000

typedef struct{
    char SHOW_ID[20];
    char TYPE[50];
    char TITLE[200];
    char DIRECTOR[100];
    char CAST[300];
    char COUNTRY[100];
    char DATE_ADDED[50];
    int RELEASE_YEAR;
    char RATING[20];
    char DURATION[20];
    char GENRE[100];
    char DESCRIPTION[300];

}Show;

void removeAspas(char *str){

    int len = strlen(str);
    
    if(len >= 2 && str[0] == '"' && str[len - 1] == '"'){
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}

void parseCSVLine(char *line, Show *s){

    char *ptr = line;
    char *campos[12];
    int campoAtual = 0;

    while(*ptr && campoAtual < 12){
        if(*ptr == '"'){
            ptr++;
            campos[campoAtual] = ptr;
            while(*ptr && !(*ptr == '"' && (*(ptr + 1) == ',' || *(ptr + 1) == '\0')))
                ptr++;
            *ptr = '\0';
            ptr += 2;
        } else{
            campos[campoAtual] = ptr;
            while(*ptr && *ptr != ',')
                ptr++;
            if(*ptr){
                *ptr = '\0';
                ptr++;
            }
        }
        campoAtual++;
    }

    strcpy(s->SHOW_ID, campos[0]);
    strcpy(s->TYPE, campos[1]);
    strcpy(s->TITLE, campos[2]);
    strcpy(s->DIRECTOR, campos[3]);
    strcpy(s->CAST, campos[4]);
    strcpy(s->COUNTRY, campos[5]);
    strcpy(s->DATE_ADDED, campos[6]);
    s->RELEASE_YEAR = atoi(campos[7]);
    strcpy(s->RATING, campos[8]);
    strcpy(s->DURATION, campos[9]);
    strcpy(s->GENRE, campos[10]);
    strcpy(s->DESCRIPTION, campos[11]);
}

int compararTitulo(const void *a, const void *b){

    return strcmp(((Show *)a)->TITLE, ((Show *)b)->TITLE);
}

int buscaBinaria(Show vetor[], int n, char *titulo, int *comparacoes){
    
    int esq = 0, dir = n - 1;
    while(esq <= dir){
        
        int meio = (esq + dir) / 2;
        
        (*comparacoes)++;
        int cmp = strcmp(vetor[meio].TITLE, titulo);
        
        if(cmp == 0){
            return 1;
        }
        else if(cmp < 0){
            esq = meio + 1;
        }
        else{
            dir = meio - 1;
        } 
    }
    return 0;
}

int main(){
    
    FILE *csv = fopen("/tmp/disneyplus.csv", "r");
    
    if(!csv){
    
        perror("Erro ao abrir o arquivo CSV");
        return 1;
    }

    Show todos[MAX_SHOWS];
    
    int total = 0;
    char line[MAX_LINE];

    fgets(line, MAX_LINE, csv); 

    while(fgets(line, MAX_LINE, csv) && total < MAX_SHOWS){

        line[strcspn(line, "\n")] = '\0';
        parseCSVLine(line, &todos[total++]);
    }

    fclose(csv);

    char input[200];

    Show selecionados[MAX_SHOWS];
    int n = 0;

    while(scanf(" %[^\n]", input) && strcmp(input, "FIM") != 0){

        for(int i = 0; i < total; i++){

            if(strcmp(todos[i].SHOW_ID, input) == 0){
                selecionados[n++] = todos[i];
                break;
            }
        }
    }

    qsort(selecionados, n, sizeof(Show), compararTitulo);

    char titulos[MAX_SHOWS][200];
    int numTitulos = 0;

    while(scanf(" %[^\n]", input) && strcmp(input, "FIM") != 0){
        strcpy(titulos[numTitulos++], input);
    }

    int comparacoes = 0;
    clock_t inicio = clock();

    for(int i = 0; i < numTitulos; i++){

        int achou = buscaBinaria(selecionados, n, titulos[i], &comparacoes);
        printf("%s\n", achou ? "SIM" : "NAO");
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000.0;

    FILE *log = fopen("matricula_binaria.txt", "w");

    if(log){
        fprintf(log, "1234567\t%.3f\t%d\n", tempo, comparacoes);
        fclose(log);
    }

    return 0;
}
