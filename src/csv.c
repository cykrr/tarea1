#include "csv.h"

void populateList(CSV *csv){
    ssize_t read; size_t length = 0; char *line = NULL;

    while((read = getline(&line, &length, csv->fd) != EOF)){
        Song song;
        char linecpy[100];
        int i = 0;
        strcpy(linecpy, "");

        while( line[i] != ','){
            printf("%d ", i);
            linecpy[i] = line[i];
            i++;
        }
        putchar('\n');
        linecpy[i] = '\0';
        strcpy(song.name, linecpy);
        printf("Name: %s\n", song.name);

        strcpy(linecpy, "");

        int j = 0;
        i++;
        while( line[i] != ','){
            printf("%d ", i);
            linecpy[j] = line[i];
            j++;
            i++;
        }
        putchar('\n');
        linecpy[j] = '\0';

        strcpy(song.artist, linecpy);

        printf("Artist: %s\n", song.artist);


        printf("Full: %s\n", line);
    }
}

void importCSV(CSV *csv, char *name){

    List *list = createList();
    
    csv->fd = fopen(name, "rw");
    if(!csv->fd){
        printf("Error abriendo archivo %s\n", name);
    }


    populateList(csv);
    
}

void exportCSV(CSV *csv, char *name){
    
}

