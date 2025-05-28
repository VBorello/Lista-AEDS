#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHOWS 1000
#define MAX_LINE 500
#define MAX_FIELD 100

typedef struct{
 
    char SHOW_ID[MAX_FIELD];
    char TYPE[MAX_FIELD];
    char TITLE[MAX_FIELD];
    char DIRECTOR[MAX_FIELD];
    char CAST[MAX_FIELD];
    char COUNTRY[MAX_FIELD];
    char DATE_ADDED[MAX_FIELD];
    char RELEASE_YEAR[MAX_FIELD];
    char RATING[MAX_FIELD];
    char DURATION[MAX_FIELD];
    char LISTED_IN[MAX_FIELD];
    char DESCRIPTION[MAX_FIELD];
}Show;

typedef struct{
 
    Show array[MAX_SHOWS];
    int n;
}Lista;

void initLista(Lista *lista){
   
    lista->n = 0;
}

void inserirFim(Lista *lista, Show show){
    
    if(lista->n >= MAX_SHOWS){
        printf("Erro ao inserir!\n");
        return;
    }
    
    lista->array[lista->n++] = show;
}

Show removerFim(Lista *lista){
    
    if(lista->n == 0){
        printf("Erro ao remover!\n");
        exit(1);
    }

    return lista->array[--lista->n];
}

Show removerInicio(Lista *lista){
   
    if(lista->n == 0){
        printf("Erro ao remover!\n");
        exit(1);
    }
    
    Show resposta = lista->array[0];
    
    for(int i = 0; i < lista->n - 1; i++){
        lista->array[i] = lista->array[i + 1];
    }
    
    lista->n--;
    
    return resposta;
}

void mostrar(Lista *lista){
    
    for(int i = 0; i < lista->n; i++){
        Show show = lista->array[i];
        printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %s ## %s ## %s ## [%s] ##\n",
               show.SHOW_ID, show.TITLE, show.TYPE, show.DIRECTOR, show.CAST, show.COUNTRY,
               show.DATE_ADDED, show.RELEASE_YEAR, show.RATING, show.DURATION, show.LISTED_IN);
    }
}

Show parseShow(char *line){
    
    Show show;
    int field = 0;
    int insideQuotes = 0;

    char buffer[MAX_LINE] = "";
    int bufferIndex = 0;

    for(int i = 0; i <= strlen(line); i++){
        char c = line[i];

        if(c == '"' && (i == 0 || line[i - 1] != '\\')){
            insideQuotes = !insideQuotes;
        } 
        else if(c == ',' && !insideQuotes){
            buffer[bufferIndex] = '\0';
            
            switch (field){
                case 0: strcpy(show.SHOW_ID, buffer); break;
                case 1: strcpy(show.TYPE, buffer); break;
                case 2: strcpy(show.TITLE, buffer); break;
                case 3: strcpy(show.DIRECTOR, buffer); break;
                case 4: strcpy(show.CAST, buffer); break;
                case 5: strcpy(show.COUNTRY, buffer); break;
                case 6: strcpy(show.DATE_ADDED, buffer); break;
                case 7: strcpy(show.RELEASE_YEAR, buffer); break;
                case 8: strcpy(show.RATING, buffer); break;
                case 9: strcpy(show.DURATION, buffer); break;
                case 10: strcpy(show.LISTED_IN, buffer); break;
                case 11: strcpy(show.DESCRIPTION, buffer); break;
            }

            field++;
            bufferIndex = 0;
        } 
        else{
            buffer[bufferIndex++] = c;
        }
    }

    return show;
}

void ler(char *arquivo, Show *shows, int *count){
    
    FILE *file = fopen(arquivo, "r");
    
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    char linha[MAX_LINE];
    fgets(linha, MAX_LINE, file); 

    *count = 0;

    while(fgets(linha, MAX_LINE, file) != NULL){
        linha[strcspn(linha, "\n")] = '\0'; 
        shows[(*count)++] = parseShow(linha);
    }

    fclose(file);
}

Show buscarPorId(char *id, Show *shows, int count){
    
    for(int i = 0; i < count; i++){
        if(strcmp(shows[i].SHOW_ID, id) == 0){
            return shows[i];
        }
    }
    
    Show empty;
    strcpy(empty.TITLE, "NaN");
    
    return empty;
}

int compararShows(const void *a, const void *b){
    
    Show *showA = (Show *)a;
    Show *showB = (Show *)b;
    
    return strcmp(showA->TITLE, showB->TITLE);
}

void ordenarLista(Lista *lista){

    qsort(lista->array, lista->n, sizeof(Show), compararShows);
}

int main(){
    
    Show shows[MAX_SHOWS];
    int showCount;

    ler("/tmp/disneyplus.csv", shows, &showCount);

    Lista lista;
    initLista(&lista);

    char input[MAX_FIELD];
    
    while (1){
        
        scanf(" %s", input);
        if(strcmp(input, "FIM") == 0){
            
            break;
        }

        Show s = buscarPorId(input, shows, showCount);
        
        if(strcmp(s.TITLE, "NaN") != 0){
            inserirFim(&lista, s);
        }
    }

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        char cmd[MAX_FIELD];
        scanf(" %s", cmd);

        if(strcmp(cmd, "II") == 0){

            char id[MAX_FIELD];
            scanf(" %s", id);
            
            Show s = buscarPorId(id, shows, showCount);
            inserirFim(&lista, s);
        } 
        else if(strcmp(cmd, "RI") == 0){
            
            Show r = removerInicio(&lista);
            printf("(R) %s\n", r.TITLE);
        } 
        else if(strcmp(cmd, "RF") == 0){
            
            Show r = removerFim(&lista);
            printf("(R) %s\n", r.TITLE);
        }
    }

    ordenarLista(&lista);
    mostrar(&lista);

    return 0;
}