#include "files.h"
#include "csv.h"
#include <stdio.h>
#include <stdlib.h>

int importFile(Map *nameMap, Map *brandMap, Map* typeMap) {
    printf("Nombre del archivo: ");
    char name[50];
    scanf("%s", name);
    
    FILE *fd = fopen(name, "r");
    if(!fd) {
        free(fd);
        printf("Error cargando archivo.\n");
        return 1;
    }
    ssize_t read; size_t length = 0; char *line = NULL; 

    while((read = getline(&line, &length, fd) != EOF)) {
        get_csv_field(line, 0) ;
    }
    return 0;
}
