#include "csv.h"
#include <stdio.h>

void importCSV(CSV *csv, char *name){
    ssize_t read; size_t length = 0; char *line = NULL;

    listCreate(&csv->list);
    
    csv->fd = fopen(name, "rw");
    if(!csv->fd){
        printf("Error abriendo archivo %s\n", name);
    }

    while((read = getline(&line, &length, csv->fd) != EOF)){
        printf("%s", line);
    }
    
}

void exportCSV(CSV *csv, char *name){
    
}

