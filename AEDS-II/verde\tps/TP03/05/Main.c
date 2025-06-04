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
    
    for(char *src = str; *src; src++) {
        if(*src == '"') {
            if(entreAspas && *(src+1) == '"') {
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

void split(char linha[], char *splitVetor[]){

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
            
            splitVetor[qtd++] = limparAspas(inicio);
            
            if(*(ponteiro+1)) ponteiro += 2; 
            else{
                ponteiro++;
            }  
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

            splitVetor[qtd++] = strlen(inicio) ? limparAspas(inicio) : strdup("NaN");
        }
    }

    while(qtd < 12){
        splitVetor[qtd++] = strdup("NaN");
    }
}

int acharIndex(char *id){

    return atoi(id + 1) - 1;
}

void ordenarVetor(char *organizado[], char organizar[]){

    if(strcmp(organizar, "NaN") == 0){
        organizado[0] = strdup("NaN");
        organizado[1] = NULL;
        
        return;
    }

    int tam = 0;
    char *token = strtok(organizar, ",");
    
    while(token != NULL && tam < 20){
    
        while(*token == ' ') token++;
        
        if(strlen(token) > 0){
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

void guardarListed(int index, char *guardar[]){

    int i;
    
    for(i = 0; guardar[i] != NULL && i < 20; i++){
        shows[index].LISTED_IN[i] = strdup(guardar[i]);
    }
    
    shows[index].LISTED_IN[i] = NULL;
}

Date separarData(char *date){

    if(date == NULL || strcmp(date, "NaN") == 0){
        return (Date){0, 0, 0};
    }

    char *campos[3];
    int z = 0;

    char *token = strtok(date, " ,");
    
    while(token != NULL && z < 3){
        campos[z++] = token;
        token = strtok(NULL, " ,");
    }

    if(z != 3) return (Date){0, 0, 0};

    char *meses[12] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    int nMeses = 0;
    
    for(int i = 0; i < 12; i++){
        if(strcmp(meses[i], campos[0]) == 0){
            nMeses = i + 1;
            break;
        }
    }

    return (Date){atoi(campos[1]), nMeses, atoi(campos[2])};
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

        char *divisao[12] = {0};
        split(linha, divisao);

        int index = acharIndex(divisao[0]);
        strncpy(shows[index].SHOW_ID, divisao[0], 9);
        shows[index].SHOW_ID[9] = '\0';
        
        strcpy(shows[index].TYPE, divisao[1]);
        strcpy(shows[index].TITLE, divisao[2]);
        strcpy(shows[index].DIRECTOR, divisao[3]);

        char CAST[1000];
        strcpy(CAST, divisao[4]);
        
        char *CASTArray[21] = {0};
        ordenarVetor(CASTArray, CAST);
        guardarCast(index, CASTArray);

        strcpy(shows[index].COUNTRY, divisao[5]);
        shows[index].DATE_ADDED = separarData(divisao[6]);
        shows[index].RELEASE_YEAR = atoi(divisao[7]);
        strcpy(shows[index].RATING, divisao[8]);
        strcpy(shows[index].DURATION, divisao[9]);

        char listed[1000];
        strcpy(listed, divisao[10]);
        
        char *listedArray[21] = {0};
        ordenarVetor(listedArray, listed);
        guardarListed(index, listedArray);

        for(int i = 0; i < 12; i++) {
            free(divisao[i]);
        }
    }

    fclose(file);
}

char* formatarData(Date formatar){

    if(formatar.ano == 0) return strdup("NaN");

    char *meses[12] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    char *dataFormatada = malloc(30 * sizeof(char));
    sprintf(dataFormatada, "%s %d, %d", meses[formatar.mes - 1], formatar.dia, formatar.ano);

    return dataFormatada;
}

void lerShow(Show sh){

    printf("=> %s ## %s ## %s ## %s ## [", sh.SHOW_ID, sh.TITLE, sh.TYPE, sh.DIRECTOR);
    
    for(int i = 0; sh.CAST[i] != NULL; i++) {
        printf("%s%s", sh.CAST[i], (sh.CAST[i+1] ? ", " : ""));
    }

    printf("] ## %s ## ", sh.COUNTRY);

    char *dataFormatada = formatarData(sh.DATE_ADDED);
    
    printf("%s ## ", dataFormatada);
    free(dataFormatada);

    printf("%d ## %s ## %s ## [", sh.RELEASE_YEAR, sh.RATING, sh.DURATION);
    
    for(int i = 0; sh.LISTED_IN[i] != NULL; i++) {
        printf("%s%s", sh.LISTED_IN[i], (sh.LISTED_IN[i+1] ? ", " : ""));
    }

    printf("] ##\n");
}

typedef struct{

    Show elemento;
    struct celula* prox;

}Celula;

typedef struct{

    Celula* primeiro;
    Celula* ultimo;

}Lista;

Lista lista;

void inicio(){

    lista.primeiro = (Celula*)malloc(sizeof(Celula));
    lista.primeiro -> prox = NULL; 
    lista.ultimo = lista.primeiro;
}

void inserirInicio(Show x){
    
    Celula *aux = (Celula*) malloc(sizeof(Celula));

    aux -> elemento = x;
    aux -> prox = lista.primeiro -> prox;
    
    lista.primeiro -> prox = aux;

    if(lista.ultimo == lista.primeiro){
        lista.ultimo = aux;
    }

}

void inserirFim(Show x){

    Celula *aux = (Celula*) malloc(sizeof(Celula));

    aux -> elemento = x;
    aux -> prox = NULL;

    lista.ultimo -> prox = aux;
    lista.ultimo = aux;
}

void inserir(Show x, int pos){

    Celula *i = lista.primeiro;
    
    for(int j = 0; j < pos && i -> prox != NULL; j++) {
        i = i -> prox;
    }

    Celula *aux = (Celula*)malloc(sizeof(Celula));

    aux -> elemento = x;
    aux -> prox = i -> prox;
    i -> prox = aux;

    if(aux -> prox == NULL) {
        lista.ultimo = aux;
    }

}

Show removerInicio(){

    Celula *i = lista.primeiro -> prox;
    
    lista.primeiro -> prox = i -> prox;
    i -> prox = NULL;
    
    Show saida = i -> elemento;

    if(lista.ultimo == i){
        lista.ultimo = lista.primeiro;
    }

    free(i);
    return saida;
}

Show removerFim(){

    Celula *i;
    
    for(i = lista.primeiro; i -> prox != lista.ultimo; i = i -> prox);
    
    Show saida = lista.ultimo -> elemento;
    lista.ultimo = i;
    
    i = i -> prox;
    lista.ultimo -> prox = NULL;

    free(i);
    
    return saida;
}

Show remover(int pos){

    Celula *i = lista.primeiro;

    for(int j = 0; j < pos && i -> prox != NULL; j++){
        i = i -> prox;
    }

    Celula* aux = i -> prox;
    Show saida = aux -> elemento;
    
    i -> prox = aux -> prox;
    aux -> prox = NULL;

    if(aux == lista.ultimo){
        lista.ultimo = i;
    }

    free(aux);

    return saida;
}
void mostrar(){

    for(Celula *i = lista.primeiro -> prox; i != NULL; i = i -> prox ){
        lerShow(i -> elemento);
    }
}

int main() {

    leiaShow();
    
    inicio();

    char linha[30];
    
    fgets(linha,30,stdin);
    linha[strcspn(linha, "\n")] = '\0';
    
    while(strcmp(linha,"FIM") != 0 ){
        int index = acharIndex(linha);

        inserirFim(shows[index]);
        fgets(linha,30,stdin);
        linha[strcspn(linha, "\n")] = '\0';
    }

    fgets(linha,30,stdin);
    linha[strcspn(linha, "\n")] = '\0';

    int num = atoi(linha);

    for(int i = 0; i < num;i++){

       fgets(linha,30,stdin);
       linha[strcspn(linha, "\n")] = '\0'; 

       char* token = strtok(linha," ");

       if(strcmp(token, "II") == 0){
            token = strtok(NULL, " ");
            int index = acharIndex(token);
            
            inserirInicio(shows[index]);
           
        } 
        else if(strcmp(token, "IF") == 0){
        
            token = strtok(NULL, " ");
            int index = acharIndex(token);

            inserirFim(shows[index]);
            
        }
        else if(strcmp(token, "I*") == 0){
            
            token = strtok(NULL, " ");
            int pos = atoi(token);

            token = strtok(NULL, " ");
            int index = acharIndex(token);
        
            inserir(shows[index], pos);
            
        } 
        else if(strcmp(token, "RI") == 0){

            Show saida = removerInicio();
            printf("(R) %s\n", saida.TITLE);

        }
        else if(strcmp(token, "RF") == 0){

            Show saida = removerFim();
            printf("(R) %s\n", saida.TITLE);

        }
        else if(strcmp(token, "R*") == 0){

            token = strtok(NULL, " ");
            int pos = atoi(token);
        
            Show saida = remover(pos);
            printf("(R) %s\n", saida.TITLE);
        }

    }

    mostrar();
    
    return 0;
}