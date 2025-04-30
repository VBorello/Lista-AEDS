#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 12

typedef struct{
    char* SHOW_ID;
    char* TYPE;
    char* TITLE;
    char** DIRECTOR;
    int director_count;
    char** CAST;
    int cast_count;
    char* COUNTRY;
    char* DATE_ADDED;
    int RELEASE_YEAR;
    char* RATING;
    char* DURATION;
    char** LISTED_IN;
    int listed_in_count;
} Show;

Show* criarShow(){
    Show* show = (Show*)malloc(sizeof(Show));
    show->SHOW_ID = strdup("NaN");
    show->TYPE = strdup("NaN");
    show->TITLE = strdup("NaN");
    show->DIRECTOR = NULL;
    show->director_count = 0;
    show->CAST = NULL;
    show->cast_count = 0;
    show->COUNTRY = strdup("NaN");
    show->DATE_ADDED = strdup("NaN");
    show->RELEASE_YEAR = -1;
    show->RATING = strdup("NaN");
    show->DURATION = strdup("NaN");
    show->LISTED_IN = NULL;
    show->listed_in_count = 0;
    return show;
}

void liberarShow(Show* show){
    free(show->SHOW_ID);
    free(show->TYPE);
    free(show->TITLE);
    
    for (int i = 0; i < show->director_count; i++){
        free(show->DIRECTOR[i]);
    }
    free(show->DIRECTOR);
    
    for (int i = 0; i < show->cast_count; i++){
        free(show->CAST[i]);
    }
    free(show->CAST);
    
    free(show->COUNTRY);
    free(show->DATE_ADDED);
    free(show->RATING);
    free(show->DURATION);
    
    for (int i = 0; i < show->listed_in_count; i++){
        free(show->LISTED_IN[i]);
    }
    free(show->LISTED_IN);
    
    free(show);
}

char** splitString(const char* str, const char* delim, int* count){
    if (str == NULL || strlen(str) == 0){
        *count = 0;
        return NULL;
    }
    
    char* copy = strdup(str);
    char* token = strtok(copy, delim);
    char** result = NULL;
    int size = 0;
    
    while (token != NULL){
        result = (char**)realloc(result, (size + 1) * sizeof(char*));
        result[size] = strdup(token);
        size++;
        token = strtok(NULL, delim);
    }
    
    free(copy);
    *count = size;
    return result;
}

Show* parseLinha(char* linha){
    char* campos[MAX_FIELDS];
    int campoIndex = 0;
    bool dentroAspas = false;
    char* inicioCampo = linha;
    
    for (char* p = linha; *p; p++){
        if (*p == '"'){
            dentroAspas = !dentroAspas;
        } else if (*p == ',' && !dentroAspas){
            *p = '\0';
            campos[campoIndex++] = inicioCampo;
            inicioCampo = p + 1;
        }
    }
    campos[campoIndex] = inicioCampo;
    
    Show* show = criarShow();
    
    if (campoIndex >= 0) show->SHOW_ID = strdup(campos[0]);
    if (campoIndex >= 1) show->TYPE = strdup(campos[1]);
    if (campoIndex >= 2) show->TITLE = strdup(campos[2]);
    
    if (campoIndex >= 3){
        show->DIRECTOR = splitString(campos[3], ", ", &show->director_count);
    }
    
    if (campoIndex >= 4){
        show->CAST = splitString(campos[4], ", ", &show->cast_count);
    }
    
    if (campoIndex >= 5) show->COUNTRY = strdup(campos[5]);
    if (campoIndex >= 6) show->DATE_ADDED = strdup(campos[6]);
    
    if (campoIndex >= 7){
        show->RELEASE_YEAR = atoi(campos[7]);
    }
    
    if (campoIndex >= 8) show->RATING = strdup(campos[8]);
    if (campoIndex >= 9) show->DURATION = strdup(campos[9]);
    
    if (campoIndex >= 10){
        show->LISTED_IN = splitString(campos[10], ", ", &show->listed_in_count);
    }
    
    return show;
}

int main(){
    clock_t inicio = clock();
    int comparacoes = 0;
    
    FILE* arquivo = fopen("/tmp/disneyplus.csv", "r");
    if (arquivo == NULL){
        perror("Erro ao abrir arquivo");
        return 1;
    }
    
    char linha[MAX_LINE_SIZE];
    fgets(linha, sizeof(linha), arquivo);
    
    Show** programas = NULL;
    int numProgramas = 0;
    
    while (fgets(linha, sizeof(linha), arquivo)){
        
        linha[strcspn(linha, "\n")] = '\0';
        Show* programa = parseLinha(linha);
        programas = (Show**)realloc(programas, (numProgramas + 1) * sizeof(Show*));
        programas[numProgramas++] = programa;
    }
    fclose(arquivo);
    
    char entrada[MAX_LINE_SIZE];
    scanf("%[^\n]%*c", entrada);
    
    while (strcmp(entrada, "FIM") != 0){
        bool encontrado = false;
        
        for (int i = 0; i < numProgramas; i++){
            comparacoes++;
            if (programas[i]->TITLE && strcmp(programas[i]->TITLE, entrada) == 0){
                encontrado = true;
                break;
            }
        }
        
        printf("%s\n", encontrado ? "SIM" : "NAO");
        scanf("%[^\n]%*c", entrada);
    }
    
    for (int i = 0; i < numProgramas; i++){
        liberarShow(programas[i]);
    }
    free(programas);
    
    clock_t fim = clock();
    double duracao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
    
    FILE* log = fopen("123456_sequencial.txt", "w");
    if (log != NULL){
        fprintf(log, "123456\t%.0f\t%d\n", duracao, comparacoes);
        fclose(log);
    }
    
    return 0;
}