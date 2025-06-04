#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    
    int dia; 
    int mes; 
    int ano;

}Date;

typedef struct{

    char SHOW_ID[10];  
    char TYPE[50];
    char TITLE[250];
    char DIRECTOR[100];
    char *CAST[21]; 
    char COUNTRY[70];
    Date DATE_ADDED;
    int RELEASE_YEAR;
    char RATING[20];
    char DURATION[20];
    char *LISTED_IN[21]; 

}Show;

Show shows[1368];

char* limparAspas(char *str) {
    
    if(str == NULL || strcmp(str, "NaN") == 0){
        return strdup("NaN");
    } 
    
    char *saida = malloc(strlen(str) + 1);
    char *dest = saida;
    
    int entreAspas = 0;
    
    for(char *src = str; *src; src++){
        if(*src == '"'){
            if(entreAspas && *(src+1) == '"'){
                *dest++ = '"';
                src++;
            }
            entreAspas = !entreAspas;
        } 
        else{
            *dest++ = *src;
        }
    }

    *dest = '\0';
    
    if(strlen(saida) == 0){
        free(saida);
      
        return strdup("NaN");
    }
    return saida;
}

void split(char linha[], char *campos[]) {
    
    char *ponteiro = linha;
    char *inicio;
    int qtd = 0;
    
    while(*ponteiro && qtd < 12){
        if(*ponteiro == '"'){

            ponteiro++; 
            inicio = ponteiro;

            while(*ponteiro && !(*ponteiro == '"' && (*(ponteiro+1) == ',' || *(ponteiro+1) == '\0'))){
                ponteiro++;
            } 
            
            *ponteiro = '\0';
            
            campos[qtd++] = limparAspas(inicio);
            
            if (*(ponteiro+1)){
                ponteiro += 2;
            }  
            else ponteiro++;
        } 
        else{
        
            inicio = ponteiro;
            while(*ponteiro && *ponteiro != ','){
                ponteiro++;
            } 
            
            if(*ponteiro){
                *ponteiro = '\0';
                ponteiro++; 
            }
            campos[qtd++] = strlen(inicio) ? limparAspas(inicio) : strdup("NaN");
        }
    }

    while (qtd < 12){
        campos[qtd++] = strdup("NaN");
    }
}

int indexFinder(char *id){

    return atoi(id + 1) - 1;
}

void organizandoVet(char *organizado[], char organizar[]){
    
    if(strcmp(organizar, "NaN") == 0){
        organizado[0] = strdup("NaN");
        organizado[1] = NULL;
    
        return;
    }

    int tam = 0;
    char *token = strtok(organizar, ",");

    while(token != NULL && tam < 20){
        while (*token == ' ') token++;
        
        if(strlen(token) > 0) {
            organizado[tam++] = strdup(token);
        }

        token = strtok(NULL, ",");
    }
    organizado[tam] = NULL;

    for(int i = 0; i < tam - 1; i++){
        for(int j = i + 1; j < tam; j++){
            if(strcmp(organizado[i], organizado[j]) > 0){
                char *aux = organizado[i];
                
                organizado[i] = organizado[j];
                organizado[j] = aux;
            }
        }
    }
}

void guardarCast(int index, char *guardar[]){

    int i;
    
    for(i = 0; guardar[i] != NULL && i < 20; i++){
        shows[index].CAST[i] = strdup(guardar[i]);
    }

    shows[index].CAST[i] = NULL;
}

void guardadeListed(int index, char *guardar[]) {
    
    int i;
    
    for(i = 0; guardar[i] != NULL && i < 20; i++){
        shows[index].LISTED_IN[i] = strdup(guardar[i]);
    }

    shows[index].LISTED_IN[i] = NULL;
}

Date parseDate(char *date){
    
    if(date == NULL || strcmp(date, "NaN") == 0){
        return (Date){0, 0, 0};
    }

    char *dSeparado[3];
    
    int z = 0;
    char *token = strtok(date, " ,");

    while(token != NULL && z < 3){
        dSeparado[z++] = token;
        token = strtok(NULL, " ,");
    }

    if(z != 3){
        return (Date){0, 0, 0};
    } 

    char *meses[12] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    int nMeses = 0;

    for(int i = 0; i < 12; i++){
        
        if(strcmp(meses[i], dSeparado[0]) == 0){
            nMeses = i + 1;
            
            break;
        }
    }

    return(Date){atoi(dSeparado[1]), nMeses, atoi(dSeparado[2])};
}

void leiaShow(){

    FILE *file = fopen("/tmp/disneyplus.csv", "r");
    
    if(!file){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[2000];
    fgets(linha, 2000, file); 

    while(fgets(linha, 2000, file) != NULL){
        linha[strcspn(linha, "\n")] = '\0';

        char *separar[12] = {0};
        split(linha, separar);

        int index = indexFinder(separar[0]);
        strncpy(shows[index].SHOW_ID, separar[0], 9);
        shows[index].SHOW_ID[9] = '\0';
        
        strcpy(shows[index].TYPE, separar[1]);
        strcpy(shows[index].TITLE, separar[2]);
        strcpy(shows[index].DIRECTOR, separar[3]);

        char CAST[1000];
        strcpy(CAST, separar[4]);
        
        char *CASTArray[21] = {0};
        organizandoVet(CASTArray, CAST);
        guardarCast(index, CASTArray);

        strcpy(shows[index].COUNTRY, separar[5]);
        shows[index].DATE_ADDED = parseDate(separar[6]);
        shows[index].RELEASE_YEAR = atoi(separar[7]);
        strcpy(shows[index].RATING, separar[8]);
        strcpy(shows[index].DURATION, separar[9]);

        char listed[1000];
        strcpy(listed, separar[10]);
        
        char *listedArray[21] = {0};
        organizandoVet(listedArray, listed);
        guardadeListed(index, listedArray);

        for(int i = 0; i < 12; i++){
            free(separar[i]);
        }
    }

    fclose(file);
}

char* formatarData(Date formatar){

    if(formatar.ano == 0){
        return strdup("NaN");
    } 

    char *meses[12] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    char *dataFormatada = malloc(30 * sizeof(char));
    sprintf(dataFormatada, "%s %d, %d", meses[formatar.mes - 1], formatar.dia, formatar.ano);
    
    return dataFormatada;
}

void lerShow(Show sh){
    
    printf("=> %s ## %s ## %s ## %s ## [", sh.SHOW_ID, sh.TITLE, sh.TYPE, sh.DIRECTOR);
    
    for(int i = 0; sh.CAST[i] != NULL; i++){
        printf("%s%s", sh.CAST[i], (sh.CAST[i+1] ? ", " : ""));
    }
    printf("] ## %s ## ", sh.COUNTRY);

    char *dataFormatada = formatarData(sh.DATE_ADDED);
    printf("%s ## ", dataFormatada);
    free(dataFormatada);

    printf("%d ## %s ## %s ## [", sh.RELEASE_YEAR, sh.RATING, sh.DURATION);
    
    for(int i = 0; sh.LISTED_IN[i] != NULL; i++){
        printf("%s%s", sh.LISTED_IN[i], (sh.LISTED_IN[i+1] ? ", " : ""));
    }

    printf("] ##\n");
}

typedef struct celula Celula;

struct celula{

    Show elemento;
    Celula* prox;  
    Celula* anterior;
    int pos;

};

typedef struct{

    Celula* primeiro;
    Celula* ultimo;
    int tam;

}Lista;

Lista lista;

void inicio(){

    lista.primeiro = (Celula*)malloc(sizeof(Celula));
    lista.primeiro -> prox = NULL; 
    lista.primeiro -> anterior = NULL;
    
    lista.tam = 0;
    lista.ultimo = lista.primeiro;
}

void inserirInicio(Show x){

    Celula *aux = (Celula*) malloc(sizeof(Celula));
    aux -> elemento = x;

    if(lista.primeiro -> prox == NULL){
        aux -> prox = NULL;
        aux -> anterior = lista.primeiro;
        lista.primeiro -> prox = aux;
        lista.ultimo = aux;
    }
    else{
        aux -> prox = lista.primeiro -> prox;
        aux -> anterior = lista.primeiro;
        aux -> prox -> anterior = aux;  
        lista.primeiro -> prox = aux;
    }

    lista.tam++;
}

void inserirFim(Show x){

    Celula *tmp = (Celula*) malloc(sizeof(Celula));
    tmp -> elemento = x;
    tmp -> prox = NULL;
    tmp -> anterior = lista.ultimo;

    lista.ultimo -> prox = tmp;
    lista.ultimo = tmp;
    lista.tam++;
}

void inserir(Show x, int pos){

    Celula *i = lista.primeiro;
    for (int j = 0; j < pos && i -> prox != NULL; j++) {
        i = i -> prox;
    }
    if(i -> prox == NULL){
        inserirFim(x);
    }
    else{
        Celula *tmp = (Celula*)malloc(sizeof(Celula));
        tmp -> elemento = x;
        tmp -> prox = i -> prox;
        tmp -> anterior = i;
        i -> prox -> anterior = tmp;
        i -> prox = tmp;
    }

    lista.tam++;
}

Show removerInicio(){

    Celula *i = lista.primeiro -> prox;
    lista.primeiro -> prox = i -> prox;
    
    i -> prox = NULL;
    Show saida = i -> elemento;

    if(lista.ultimo == i){
        lista.ultimo = lista.primeiro;
    }

    lista.tam--;
    free(i);

    return saida;
}

Show removerFim(){

    Celula *i = lista.ultimo;
    Show saida = i -> elemento;
    
    lista.ultimo = i -> anterior;
    lista.ultimo -> prox = NULL;

    i -> anterior = NULL;
    
    free(i);
    lista.tam--;

    return saida;
}

Show remover(int pos){

    Celula *i = lista.primeiro;
    
    for(int j = 0; j < pos && i -> prox != NULL; j++){
        i = i -> prox;
    }
    
    Celula* aux = i -> prox;
    Show saida;
    
    if(aux -> prox == NULL){
        saida = removerFim();
    }
    else{
        saida = aux -> elemento;
        i -> prox = aux -> prox;
        aux -> prox -> anterior = i;
        aux -> prox = NULL;
        aux -> anterior=NULL;

        free(aux);  
    }
    lista.tam--;

    return saida;
}
void mostrar(){

    for(Celula *i = lista.primeiro -> prox; i!=NULL; i= i -> prox ){
        lerShow(i -> elemento);
    }
}
int compararDatas(Date a, Date b) {
    
    if(a.ano == 0 && b.ano == 0){
        return 0;
    } 

    if(a.ano == 0){
        return -1;
    }

    if(b.ano == 0){
        return 1;
    } 
    
    if(a.ano != b.ano){
        return a.ano - b.ano;
    } 

    if(a.mes != b.mes){
        return a.mes - b.mes;
    } 
    
    return a.dia - b.dia;
}

int compararShows(int id1, int id2){
    
    Show *show1 = &shows[id1];
    Show *show2 = &shows[id2];
    
    int cmpData = compararDatas(show1 -> DATE_ADDED, show2 -> DATE_ADDED);
    if (cmpData != 0) return cmpData;
    
    return strcasecmp(show1 -> TITLE, show2 -> TITLE);
}

void trocarNo(Celula *a, Celula *b){
    Show aux = a -> elemento;

    a -> elemento = b -> elemento;
    b -> elemento = aux;
}

int compararNos(Celula *a, Celula *b){
    
    int compararData = compararDatas(a -> elemento.DATE_ADDED, b -> elemento.DATE_ADDED);
    if (compararData != 0) return compararData;
    
    return strcasecmp(a -> elemento.TITLE, b -> elemento.TITLE);
}

Celula* partir(Celula *inicio, Celula *fim){
    
    Celula *pivo = fim;
    Celula *i = inicio -> anterior;
    
    for(Celula *j = inicio; j != fim; j = j -> prox){
        if(compararNos(j, pivo) <= 0){

            i = (i == NULL) ? inicio : i -> prox;
            trocarNo(i, j);
        }
    }
    
    i = (i == NULL) ? inicio : i -> prox;
    trocarNo(i, fim);
    
    return i;
}

void quickRec(Celula *inicio, Celula *fim){
    
    if(fim != NULL && inicio != fim && inicio != fim -> prox){
        Celula *pivo = partir(inicio, fim);
        quickRec(inicio, pivo -> anterior);
        quickRec(pivo -> prox, fim);
    }
}

void quick(){
    
    if (lista.tam <= 1){
        return;
    } 
    
    quickRec(lista.primeiro -> prox, lista.ultimo);
}

int main(){

    leiaShow();
    inicio();
    
    char linha[30];
    
    fgets(linha,30,stdin);
    linha[strcspn(linha, "\n")] = '\0';
    
    while(strcmp(linha,"FIM") != 0 ){
        int index = indexFinder(linha);

        inserirFim(shows[index]);
        fgets(linha,30,stdin);
        
        linha[strcspn(linha, "\n")] = '\0';
    }

    quick();
    mostrar();

    return 0;
}