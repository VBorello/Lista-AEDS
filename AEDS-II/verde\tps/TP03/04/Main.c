#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    
    int dia;
    int mes;
    int ano;

}Date;

typedef struct{
    
    char show_id[10];  
    char type[50];
    char title[250];
    char director[100];
    char *cast[21]; 
    char country[70];
    Date date_added;
    int release_year;
    char rating[20];
    char duration[20];
    char *listed_in[21]; 

}Show;

Show shows[1368];

char* limparAspas(char *str){
    
    if(str == NULL || strcmp(str, "NaN") == 0) return strdup("NaN");
    
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

void split(char linha[], char *campos[]){
    
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
            
            if(*(ponteiro+1)) ponteiro += 2; 
            else{
                ponteiro++;
            }  
        } 
        else{
            inicio = ponteiro;
            while(*ponteiro && *ponteiro != ',') ponteiro++;
            if(*ponteiro){
                *ponteiro = '\0';
                ponteiro++; 
            }
            
            campos[qtd++] = strlen(inicio) ? limparAspas(inicio) : strdup("NaN");
        }
    }

    while(qtd < 12){
        campos[qtd++] = strdup("NaN");
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
                char *tmp = organizado[i];
                organizado[i] = organizado[j];
                organizado[j] = tmp;
            }
        }
    }
}

void guardarCast(int index, char *guardar[]){
    
    int i;
    
    for(i = 0; guardar[i] != NULL && i < 20; i++){
        shows[index].cast[i] = strdup(guardar[i]);
    }
    
    shows[index].cast[i] = NULL;
}

void guardarListed_in(int index, char *guardar[]){
    
    int i;
    
    for(i = 0; guardar[i] != NULL && i < 20; i++){
        shows[index].listed_in[i] = strdup(guardar[i]);
    }
    
    shows[index].listed_in[i] = NULL;
}

Date separarData(char *date){
    
    if(date == NULL || strcmp(date, "NaN") == 0){
        return (Date){0, 0, 0};
    }

    char *partes[3];

    int z = 0;
    
    char *token = strtok(date, " ,");
    
    while(token != NULL && z < 3){
        partes[z++] = token;
        token = strtok(NULL, " ,");
    }

    if(z != 3) return (Date){0, 0, 0};

    char *meses[12] ={"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    int nMeses = 0;
    
    for(int i = 0; i < 12; i++){
        if(strcmp(meses[i], partes[0]) == 0){
            nMeses = i + 1;
            break;
        }
    }

    return (Date){atoi(partes[1]), nMeses, atoi(partes[2])};
}

void ler(){
    
    FILE *file = fopen("/tmp/disneyplus.csv", "r");
    
    if(!file){
        printf("Erro ao abrir o arquivo.\n");
        
        return;
    }

    char linha[2000];
    fgets(linha, 2000, file); 

    while(fgets(linha, 2000, file) != NULL){
    
        linha[strcspn(linha, "\n")] = '\0';

        char *divisao[12] ={0};
        split(linha, divisao);

        int index = acharIndex(divisao[0]);
        strncpy(shows[index].show_id, divisao[0], 9);
        shows[index].show_id[9] = '\0';
        
        strcpy(shows[index].type, divisao[1]);
        strcpy(shows[index].title, divisao[2]);
        strcpy(shows[index].director, divisao[3]);

        char cast[1000];
        strcpy(cast, divisao[4]);
    
        char *castArray[21] ={0};
        ordenarVetor(castArray, cast);
        guardarCast(index, castArray);

        strcpy(shows[index].country, divisao[5]);
        shows[index].date_added = separarData(divisao[6]);
        shows[index].release_year = atoi(divisao[7]);
        strcpy(shows[index].rating, divisao[8]);
        strcpy(shows[index].duration, divisao[9]);

        char listed[1000];
        strcpy(listed, divisao[10]);
    
        char *listedArray[21] ={0};
        ordenarVetor(listedArray, listed);
        guardarListed_in(index, listedArray);

        for(int i = 0; i < 12; i++){
            free(divisao[i]);
        }
    }

    fclose(file);
}

char* formatarData(Date formatar){
    
    if(formatar.ano == 0) return strdup("NaN");

    char *meses[12] ={"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    char *dataFormatada = malloc(30 * sizeof(char));
    sprintf(dataFormatada, "%s %d, %d", meses[formatar.mes - 1], formatar.dia, formatar.ano);
    
    return dataFormatada;
}

void lerShow(Show sh){
    
    printf("=> %s ## %s ## %s ## %s ## [", sh.show_id, sh.title, sh.type, sh.director);
    for(int i = 0; sh.cast[i] != NULL; i++){
        printf("%s%s", sh.cast[i], (sh.cast[i+1] ? ", " : ""));
    }
    printf("] ## %s ## ", sh.country);

    char *dataFormatada = formatarData(sh.date_added);
    
    printf("%s ## ", dataFormatada);
    free(dataFormatada);

    printf("%d ## %s ## %s ## [", sh.release_year, sh.rating, sh.duration);
    
    for(int i = 0; sh.listed_in[i] != NULL; i++){
        printf("%s%s", sh.listed_in[i], (sh.listed_in[i+1] ? ", " : ""));
    }
    printf("] ##\n");
}

Show array[5]; 

int qtd = 0; 
int primeiro = 0;
int ultimo = 0;

int media(){

    int somarAnos = 0;
    int i = primeiro;
    
    for(int j = 0; j < qtd; j++){
        somarAnos += array[i].release_year;
        i = (i + 1) % 5;
    }
    
    return somarAnos / qtd;
}

Show remover(){

    if(qtd == 0){
        Show vazio ={0};

        return vazio;
    }
    
    Show saida = array[primeiro];

    primeiro = (primeiro + 1) % 5;
    qtd--;

    return saida;
}

void inserir(Show x){

    if(qtd == 5){
        remover();
    }
    
    array[ultimo] = x;
    ultimo = (ultimo + 1) % 5;
    
    if(qtd < 5){
        qtd++;
    }
    
    printf("[Media] %d\n", media());
}

void mostrar(){

    int i = primeiro;
    
    for(int j = 0; j < qtd; j++){
        printf("[%d] ", j);
        lerShow(array[i]);
        i = (i + 1) % 5;
    }
}

int main(){

    ler();
    
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
            printf("(R) %s\n", resp.title);
        }
    }
    
    mostrar();
    
    return 0;
}