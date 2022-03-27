#include "csv.h"

/* Lee el archivo csv linea por linea 
 * y crea un struct Song por linea, 
 * guarda respectivamente el nombre,
 * el artista. 
 *
 * Para el género crea 
 * una lista enlazada en el heap de strings (char *).
 *
 * SE ASUME QUE:
 *
 * ningun campo es mayor de 99 chars.
 *
 *
 */
void populateList(CSV *csv){
    ssize_t read; size_t length = 0; char *line = NULL;

    /* leer linea a "read" hasta EOF */
    while((read = getline(&line, &length, csv->fd) != EOF)){
        /* struct song para guardar la linea */
        Song song;
        /* string para guardar letra x letra */
        char linecpy[100];
        /* contador para recorrer letra x letra */
        int i = 0;
        /* borrar la string */
        strcpy(linecpy, "");

        while( line[i] != ','){
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
            linecpy[j] = line[i];
            j++;
            i++;
        }
        putchar('\n');
        linecpy[j] = '\0';

        strcpy(song.artist, linecpy);

        i++;

        j = 0;
        if ( line [i] == '\"') {
            i++;
            while (line[i] != '\"'){
                linecpy[j] =  line[i];
                if (line[i] == ','){

                }
                i++; j++;
            }
        }


        printf("Artist: %s\n", song.artist);


        printf("Full: %s\n", line);
    }
}

void importCSV(CSV *csv, char *name){

    List *list = listCreate();
    
    csv->fd = fopen(name, "rw");
    if(!csv->fd){
        printf("Error abriendo archivo %s\n", name);
    }


    populateList(csv);
    
}

void exportCSV(CSV *csv, char *name){
    
}

