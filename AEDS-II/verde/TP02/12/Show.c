#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000
#define TAM_CAMPO 200
#define MATRÍCULA "802305"

typedef struct{

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

int mesParaInt(char *mes){

    if(strcmp(mes, "January") == 0) return 1;
    if(strcmp(mes, "February") == 0) return 2;
    if(strcmp(mes, "March") == 0) return 3;
    if(strcmp(mes, "April") == 0) return 4;
    if(strcmp(mes, "May") == 0) return 5;
    if(strcmp(mes, "June") == 0) return 6;
    if(strcmp(mes, "July") == 0) return 7;
    if(strcmp(mes, "August") == 0) return 8;
    if(strcmp(mes, "September") == 0) return 9;
    if(strcmp(mes, "October") == 0) return 10;
    if(strcmp(mes, "November") == 0) return 11;
    if(strcmp(mes, "December") == 0) return 12;
    return 0;

}

void parseData(char *data, int *dia, int *mes, int *ano){
    
    if(strcmp(data, "") == 0){
        *dia = 1;
        *mes = 1;
        *ano = 1900;
        return;
    }
    
    char mesStr[TAM_CAMPO];
    sscanf(data, "%[^ ] %d, %d", mesStr, dia, ano);
    *mes = mesParaInt(mesStr);
}

void lerShow(char *linha, Show *s){
    
    char *campos[12];
    int i = 0, j = 0;
    int dentroAspas = 0;
    char *token = malloc(strlen(linha) + 1);
    
    strcpy(token, linha);
    char *p = token;

    campos[i] = p;
    
    while(*p){
    
        if(*p == '"') dentroAspas = !dentroAspas;
    
        else if(*p == ',' && !dentroAspas){
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
    
    if(strlen(campos[4]) == 0){
        strcpy(s->cast[0], "NaN");
        s->qtd_cast = 1;
    }
    else{
        char *token_cast = strtok(campos[4], ",");
    
        while(token_cast && s->qtd_cast < 5){
            while(*token_cast == ' ') token_cast++;
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
    
    if(strlen(campos[10]) == 0){
        strcpy(s->listed_in[0], "NaN");
        s->qtd_listed = 1;
    }
    else{
    
        char *token_listed = strtok(campos[10], ",");
        while(token_listed && s->qtd_listed < 5){
            while(*token_listed == ' ') token_listed++;
            strcpy(s->listed_in[s->qtd_listed++], token_listed);
            token_listed = strtok(NULL, ",");
        }
    }

    free(token);
}

void imprimir(Show s){
    
    printf("=> %s ## %s ## %s ## %s ## [", s.show_id, s.title, s.type, s.director);
    for(int i = 0; i < s.qtd_cast; i++){
        printf("%s", s.cast[i]);
        if(i < s.qtd_cast - 1) printf(", ");
    }
    
    printf("] ## %s ## %s ## %d ## %s ## %s ## [", s.country, s.date_added, s.release_year, s.rating, s.duration);
    
    for(int i = 0; i < s.qtd_listed; i++){
        printf("%s", s.listed_in[i]);
        if(i < s.qtd_listed - 1) printf(", ");
    }
    printf("] ##\n");
}

int compararData(Show a, Show b){
    
    if(a.ano != b.ano) return a.ano - b.ano;
    if(a.mes != b.mes) return a.mes - b.mes;
    if(a.dia != b.dia) return a.dia - b.dia;
    return strcmp(a.title, b.title);
}

void bolha(Show *v, int n, int *comp, int *mov){
    
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            (*comp)++;
    
            if(compararData(v[j], v[j + 1]) > 0){
                Show tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                (*mov) += 3;
            }
        }
    }
}

int main(){
    
    char entrada[MAX][TAM_CAMPO];
    int n = 0;

    while(1){
    
        fgets(entrada[n], TAM_CAMPO, stdin);
    
        entrada[n][strcspn(entrada[n], "\n")] = 0;
        if(strcmp(entrada[n], "FIM") == 0) break;
        n++;
    }

    FILE *arq = fopen("/tmp/disneyplus.csv", "r");
    
    if(!arq){

        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    char linha[1000];
    fgets(linha, 1000, arq);

    Show lista[MAX];
    int total = 0;

    while(fgets(linha, 1000, arq) != NULL){

        for(int i = 0; i < n; i++){
        
            if(strncmp(linha, entrada[i], strlen(entrada[i])) == 0 && linha[strlen(entrada[i])] == ','){
   
                lerShow(linha, &lista[total++]);
                break;
            }
        }
    }

    fclose(arq);

    int comp = 0, mov = 0;
    clock_t inicio = clock();
   
    bolha(lista, total, &comp, &mov);
    clock_t fim = clock();

    for(int i = 0; i < total; i++){

        imprimir(lista[i]);
    }

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;

    FILE *log = fopen("matricula_bolha.txt", "w");
    
    fprintf(log, MATRÍCULA "\t%d\t%d\t%.0lf\n", comp, mov, tempo);
    fclose(log);

    return 0;
}
