#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SHOWS 1368
#define MAX_STRING 500

typedef struct {
    char showId[50];
    char type[50];
    char title[150];
    char director[300];
    char cast[500];
    char country[100];
    char dateAdded[50];
    int releaseYear;
    char rating[50];
    char duration[50];
    char listedIn[300];
} Show;

int comparisons = 0;
int movements = 0;

void ler(Show *show, char *line);
void imprimir(Show show);
void quickSort(Show arr[], int low, int high);
int partition(Show arr[], int low, int high);
void swap(Show *a, Show *b);
void formatArrayString(char *dest, const char *src);
void parseCSVField(char *dest, char **src);
void sortStringArray(char *array[], int count);
int compareDates(const char *date1, const char *date2);
int compareShows(const Show *a, const Show *b);

int main(){

    Show shows[MAX_SHOWS];
    Show filteredShows[MAX_SHOWS];
    int filteredCount = 0;
    char line[MAX_STRING];
    char id[50];
    clock_t start, end;
    double cpu_time_used;

    FILE *file = fopen("/tmp/disneyplus.csv", "r");
    
    if(!file){
        perror("Error opening file");
        return 1;
    }

    fgets(line, sizeof(line), file);

    int totalShows = 0;
    
    while(fgets(line, sizeof(line), file) && totalShows < MAX_SHOWS){
        
        ler(&shows[totalShows], line);
        totalShows++;
    }
    fclose(file);

    while(1){
        scanf("%s", id);
        if (strcmp(id, "FIM") == 0) break;

        for(int i = 0; i < totalShows; i++) {
            if(strcmp(shows[i].showId, id) == 0) {
                filteredShows[filteredCount] = shows[i];
                filteredCount++;
                
                break;
            }
        }
    }

    start = clock();

    quickSort(filteredShows, 0, filteredCount - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    FILE *log = fopen("matricula_quicksort.txt", "w");
    
    if(log) {
        fprintf(log, "123456\t%d\t%d\t%.0f\n", comparisons, movements, cpu_time_used);
        fclose(log);
    }

    for(int i = 0; i < filteredCount; i++){

        imprimir(filteredShows[i]);
    }

    return 0;
}

void parseCSVField(char *dest, char **src){
    
    int quoted = 0;
    char *ptr = *src;
    char *dest_ptr = dest;
    
    while(isspace(*ptr)) ptr++;
    
    if(*ptr == '"'){
        quoted = 1;
        ptr++;
    }
    
    while(*ptr){
        if(quoted && *ptr == '"'){
            if(*(ptr+1) == '"'){
                *dest_ptr++ = *ptr++;
                ptr++;
            } 
            else{
                ptr++;
                break;
            }
        }
        else if (!quoted && *ptr == ','){
            break;
        } 
        else{
            *dest_ptr++ = *ptr++;
        }
    }
    
    if(*ptr == ',') ptr++;
    
    *src = ptr;
    *dest_ptr = '\0';
    
    dest_ptr--;
    
    while(dest_ptr >= dest && isspace(*dest_ptr)){

        *dest_ptr-- = '\0';
    }
}

void ler(Show *show, char *line){

    char *ptr = line;
    
    parseCSVField(show->showId, &ptr);
    parseCSVField(show->type, &ptr);
    parseCSVField(show->title, &ptr);
    parseCSVField(show->director, &ptr);
    parseCSVField(show->cast, &ptr);
    parseCSVField(show->country, &ptr);
    parseCSVField(show->dateAdded, &ptr);
    
    char year[20];
    parseCSVField(year, &ptr);
    show->releaseYear = atoi(year);
    
    parseCSVField(show->rating, &ptr);
    parseCSVField(show->duration, &ptr);
    parseCSVField(show->listedIn, &ptr);
    
    if(strlen(show->director) == 0) strcpy(show->director, "NaN");
    if(strlen(show->dateAdded) == 0) strcpy(show->dateAdded, "NaN");
}

void sortStringArray(char *array[], int count){

    for(int i = 0; i < count-1; i++) {
        for(int j = i+1; j < count; j++) {
            if(strcmp(array[i], array[j]) > 0) {
                
                char *temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void formatArrayString(char *dest, const char *src){

    strcpy(dest, "[");
    char temp[strlen(src)+1];
    strcpy(temp, src);
    
    char *elements[100];
    int count = 0;
    char *token = strtok(temp, ",");
    
    while(token != NULL && count < 100){

        while(isspace((unsigned char)*token)) token++;
        char *end = token + strlen(token) - 1;
        while(end > token && isspace((unsigned char)*end)) end--;
        *(end+1) = '\0';
        
        elements[count++] = token;
        token = strtok(NULL, ",");
    }
    
    sortStringArray(elements, count);
    
    for(int i = 0; i < count; i++){
        if (i > 0) strcat(dest, ", ");
        strcat(dest, elements[i]);
    }
    
    strcat(dest, "]");
}

void imprimir(Show show){

    char formattedCast[600];
    char formattedListedIn[400];
    
    formatArrayString(formattedCast, show.cast);
    formatArrayString(formattedListedIn, show.listedIn);
    
    printf("=> %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ##\n",
           show.showId,
           show.title,
           show.type,
           show.director,
           formattedCast,
           show.country,
           show.dateAdded,
           show.releaseYear,
           show.rating,
           show.duration,
           formattedListedIn);
}

int compareDates(const char *date1, const char *date2){
    
    if(strcmp(date1, "NaN") == 0 && strcmp(date2, "NaN") == 0) return 0;
    if(strcmp(date1, "NaN") == 0) return -1;
    if(strcmp(date2, "NaN") == 0) return 1;
    
    return strcmp(date1, date2);
}

int compareShows(const Show *a, const Show *b){
    
    int dateCompare = compareDates(a->dateAdded, b->dateAdded);
   
    if(dateCompare != 0){
        return dateCompare;
    }

    return strcmp(a->title, b->title);
}

void quickSort(Show arr[], int low, int high){
    
    if(low < high){
        
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(Show arr[], int low, int high){

    Show pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++){
        comparisons++;
        if(compareShows(&arr[j], &pivot) < 0){
            i++;
            swap(&arr[i], &arr[j]);
            movements += 3;
        }
    }

    swap(&arr[i + 1], &arr[high]);
    movements += 3;
    return (i + 1);
}

void swap(Show *a, Show *b){

    Show temp = *a;
    *a = *b;
    *b = temp;
}