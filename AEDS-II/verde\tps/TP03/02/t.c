#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SHOWS 10000
#define MAX_LEN 3000
#define MAX_LISTA 1000

typedef struct{
    
    char SHOW_ID[50];
    char TYPE[100];
    char TITLE[300];
    char DIRECTOR[300];
    char CAST[1000];
    char COUNTRY[200];
    char DATE_ADDED[100];
    char RATING[100];
    char RELEASE_YEAR[10];
    char DURATION[50];
    char LISTED_IN[300];
    char DESCRIPTION[1000];

}Show;

typedef struct{

    Show array[MAX_LISTA];
    int n;
}Lista;

char linhasCSV[MAX_SHOWS][MAX_LEN];
char ids[MAX_SHOWS][50];
int totalRegistros = 0;

char* vazio(char *str){

    return (str[0] == '\0') ? "NaN" : str;
}

int comparar(const void *a, const void *b){

    return strcmp(*(const char **)a, *(const char **)b);
}

void trim(char *str){
    
    char *end;
    while(isspace((unsigned char)*str)) str++;
    
    if(*str == 0){
        return;
    } 

    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}

void ordenarEConcatenar(char *str, char *saida){
    
    char *tokens[50];
    int count = 0;
    char temp[1000];
    strcpy(temp, str);

    char *token = strtok(temp, ",");
    
    while(token != NULL){
        trim(token);
        tokens[count++] = token;
        token = strtok(NULL, ",");
    }

    qsort(tokens, count, sizeof(char *), comparar);

    saida[0] = '\0';
    
    for(int i = 0; i < count; i++){
        
        strcat(saida, tokens[i]);
        if(i < count - 1) strcat(saida, ", ");
    }
}

void parseCSVLine(char *linha, Show *s){
    
    char *campos[12];
    int i = 0, j = 0, k = 0;
    int entreAspas = 0;
    char campo[1000];

    while(linha[i]){
        
        if(linha[i] == '"'){
            entreAspas = !entreAspas;
        } 
        else if(linha[i] == ',' && !entreAspas){
        
            campo[k] = '\0';
            campos[j] = strdup(campo);
            j++; k = 0;
        } 
        else{
            campo[k++] = linha[i];
        }
        
        i++;
    }
    
    campo[k] = '\0';
    campos[j++] = strdup(campo);

    i = 0;
    
    strcpy(s->SHOW_ID, vazio(campos[i++]));
    strcpy(s->TYPE, vazio(campos[i++]));
    strcpy(s->TITLE, vazio(campos[i++]));
    strcpy(s->DIRECTOR, vazio(campos[i++]));

    if(strlen(campos[i]) == 0){
        strcpy(s->CAST, "NaN");
    } 
    else{
        ordenarEConcatenar(campos[i], s->CAST);
    }
    i++;

    strcpy(s->COUNTRY, vazio(campos[i++]));
    strcpy(s->DATE_ADDED, vazio(campos[i++]));
    strcpy(s->RELEASE_YEAR, vazio(campos[i++]));
    strcpy(s->RATING, vazio(campos[i++]));
    strcpy(s->DURATION, vazio(campos[i++]));
    strcpy(s->LISTED_IN, vazio(campos[i++]));
    strcpy(s->DESCRIPTION, vazio(campos[i++]));

    
    for(int x = 0; x < j; x++) free(campos[x]);
}

void imprimir(Show *s){

    char categorias[300];
    ordenarEConcatenar(s->LISTED_IN, categorias);
    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %s ## %s ## %s ## [%s] ##\n",
           s->SHOW_ID, s->TITLE, s->TYPE, s->DIRECTOR,
           s->CAST, s->COUNTRY, s->DATE_ADDED,
           s->RELEASE_YEAR, s->RATING, s->DURATION,
           categorias);
}

void inserirFim(Lista *l, Show s){
    l->array[l->n++] = s;
}

void inserirInicio(Lista *l, Show s){
    
    for(int i = l->n; i > 0; i--){
        l->array[i] = l->array[i - 1];
    }

    l->array[0] = s;
    l->n++;
}

void inserir(Lista *l, Show s, int pos){
    
    for(int i = l->n; i > pos; i--){
        l->array[i] = l->array[i - 1];
    }
    
    l->array[pos] = s;
    l->n++;
}

Show removerInicio(Lista *l){
    
    Show resp = l->array[0];
    
    for(int i = 0; i < l->n - 1; i++){
        l->array[i] = l->array[i + 1];
    }
    
    l->n--;

    return resp;
}

Show removerFim(Lista *l){

    return l->array[--l->n];
}

Show remover(Lista *l, int pos){

    Show resp = l->array[pos];
    
    for(int i = pos; i < l->n - 1; i++){
        l->array[i] = l->array[i + 1];
    }
    
    l->n--;

    return resp;
}

void mostrar(Lista *l){
    
    for(int i = 0; i < l->n; i++){
        imprimir(&l->array[i]);
    }
}

void carregarCSV(){
    
    FILE *fp = fopen("/tmp/disneyplus.csv", "r");
    
    if(!fp){
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    char linha[MAX_LEN];
    fgets(linha, MAX_LEN, fp); 

    while(fgets(linha, MAX_LEN, fp)){

        linha[strcspn(linha, "\r\n")] = '\0'; 
        strcpy(linhasCSV[totalRegistros], linha);
        
        char *id = strtok(linha, ",");
        
        strcpy(ids[totalRegistros], id);
        totalRegistros++;
    }

    fclose(fp);
}

Show buscarPorId(char *id){
    
    for(int i = 0; i < totalRegistros; i++){
        if(strcmp(id, ids[i]) == 0){
            Show s;
            parseCSVLine(linhasCSV[i], &s);
            return s;
        }
    }

    Show vazio;
    strcpy(vazio.SHOW_ID, "");

    return vazio;
}

int main(){
    carregarCSV();
    Lista lista;
    lista.n = 0;

    char entrada[100];
    while(1){
        
        fgets(entrada, 100, stdin);

        entrada[strcspn(entrada, "\r\n")] = '\0';
        
        if(strcmp(entrada, "FIM") == 0){
            break;
        } 
        
        Show s = buscarPorId(entrada);
        
        if(strlen(s.SHOW_ID) > 0){
            inserirFim(&lista, s);
        }
    }

    int n;
    scanf("%d\n", &n);
    
    for(int i = 0; i < n; i++){

        fgets(entrada, 100, stdin);
        entrada[strcspn(entrada, "\r\n")] = '\0';
        char cmd[5], arg1[20], arg2[20];
        int pos;

        if(sscanf(entrada, "%s %s %s", cmd, arg1, arg2) >= 2){
            if(strcmp(cmd, "II") == 0){

                Show s = buscarPorId(arg1);
                inserirInicio(&lista, s);
            } 
            else if(strcmp(cmd, "IF") == 0){
                
                Show s = buscarPorId(arg1);
                inserirFim(&lista, s);
            } 
            else if(strcmp(cmd, "I*") == 0){
                
                pos = atoi(arg1);
                Show s = buscarPorId(arg2);
                inserir(&lista, s, pos);
            } 
            else if(strcmp(cmd, "RI") == 0){
                
                Show r = removerInicio(&lista);
                printf("(R) %s\n", r.TITLE);
            } 
            else if(strcmp(cmd, "RF") == 0){
                
                Show r = removerFim(&lista);
                printf("(R) %s\n", r.TITLE);
            } 
            else if(strcmp(cmd, "R*") == 0){
                
                pos = atoi(arg1);
                Show r = remover(&lista, pos);
                printf("(R) %s\n", r.TITLE);
            }
        }
    }

    mostrar(&lista);

    return 0;
}
