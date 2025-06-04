#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int dia;
    int mes;
    int ano;

} Date;

typedef struct{

    char SHOW_ID[10];  
    char TYPE[50];
    char TITLE[250];
    char DIRECTO[100];
    char *CAST[21]; 
    char COUNTRY[70];
    Date DATE_ADDED;
    int RELEASE_YEAR;
    char RATING[20];
    char DURATION[20];
    char *LISTED_IN[21]; 

}Show;

Show shows[1368];

char* limparAspas(char *str){
    
    if (str == NULL || strcmp(str, "NaN") == 0) return strdup("NaN");
    
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

void split(char linha[], char *vetsplit[]){

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
            
            vetsplit[qtd++] = limparAspas(inicio);
            
            if(*(ponteiro+1)){
                ponteiro += 2;
            }  
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
            vetsplit[qtd++] = strlen(inicio) ? limparAspas(inicio) : strdup("NaN");
        }
    }

    while(qtd < 12){
        vetsplit[qtd++] = strdup("NaN");
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
        
        while(*token == ' '){
            token++;
        } 
        
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
    
    for(i = 0; guardar[i] != NULL && i < 20; i++) {
        shows[index].CAST[i] = strdup(guardar[i]);
    }
    
    shows[index].CAST[i] = NULL;
}

void guardarListed(int index, char *guardar[]){
    
    int i;

    for (i = 0; guardar[i] != NULL && i < 20; i++) {
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

    if(z != 3){
        return (Date){0, 0, 0};
    } 

    char *meses[12] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    int numMes = 0;
    
    for(int i = 0; i < 12; i++){
        if(strcmp(meses[i], campos[0]) == 0){
            numMes = i + 1;
            
            break;
        }
    }

    return(Date){atoi(campos[1]), numMes, atoi(campos[2])};
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
        strcpy(shows[index].DIRECTO, divisao[3]);

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

        for(int i = 0; i < 12; i++){
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

    printf("=> %s ## %s ## %s ## %s ## [", sh.SHOW_ID, sh.TITLE, sh.TYPE, sh.DIRECTO);
    
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

typedef struct Celula{

    Show elemento;
    struct Celula* prox;

}Celula;

typedef struct{

    Celula* primeiro;
    Celula* ultimo;
    int tamanho;

}FilaCircular;

FilaCircular fila;

void inicializarFila(){

    fila.primeiro = NULL;
    fila.ultimo = NULL;
    fila.tamanho = 0;
}

int media(){

    if(fila.tamanho == 0){
        return 0;
    } 
    
    int somaAnos = 0;

    Celula* i = fila.primeiro;
    int count = 0;
    
    while(count < fila.tamanho){

        somaAnos += i -> elemento.RELEASE_YEAR;
        i = i -> prox;
        count++;
    }
    
    return somaAnos / fila.tamanho;
}

Show remover(){

    if(fila.tamanho == 0){
        Show vazio = {0};
      
        return vazio;
    }
    
    Show resp = fila.primeiro -> elemento;
    Celula* temp = fila.primeiro;
    
    if(fila.tamanho == 1){
        fila.primeiro = NULL;
        fila.ultimo = NULL;
    } 
    else{

        fila.primeiro = fila.primeiro -> prox;
        fila.ultimo -> prox = fila.primeiro; 
    }
    
    free(temp);
    fila.tamanho--;
    
    return resp;
}

void inserir(Show x){

    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova -> elemento = x;
    
    if(fila.tamanho == 5){
        remover();
    }
    
    if(fila.tamanho == 0){

        fila.primeiro = nova;
        fila.ultimo = nova;
        nova -> prox = nova; 
    }
    else{
        
        nova -> prox = fila.primeiro;
        fila.ultimo -> prox = nova;
        fila.ultimo = nova;
    }
    
    fila.tamanho++;
    printf("[Media] %d\n", media());
}

void mostrar(){

    if(fila.tamanho == 0) return;
    
    Celula* atual = fila.primeiro;
    
    for(int i = 0; i < fila.tamanho; i++){
        printf("[%d] ", i);
        lerShow(atual -> elemento);
        atual = atual -> prox;
    }
}

int main(){

    leiaShow();
    inicializarFila(); 
    
    char linha[30];
    fgets(linha, 30, stdin);
    
    linha[strcspn(linha, "\n")] = '\0';
    
    while(strcmp(linha, "FIM") != 0){

        int index = acharIndex(linha);
        inserir(shows[index]);
        fgets(linha, 30, stdin);
        linha[strcspn(linha, "\n")] = '\0';
    }

    fgets(linha, 30, stdin);
    linha[strcspn(linha, "\n")] = '\0';
    int tam = atoi(linha);

    for(int i = 0; i < tam; i++){

        fgets(linha, 30, stdin);
        linha[strcspn(linha, "\n")] = '\0';
       
        char *token = strtok(linha, " ");

        if(strcmp(token, "I") == 0){

            token = strtok(NULL, " ");
            int index = acharIndex(token);
            inserir(shows[index]);
        } 
        else if(strcmp(token, "R") == 0){

            Show resp = remover();
            printf("(R) %s\n", resp.TITLE);
        }
    }
    
    mostrar();
    
    while(fila.tamanho > 0){

        remover();
    }
    
    return 0;
}