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


const char *get_csv_field (char * tmp, int k) {
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){

        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }


    return NULL;
}


 
void populateList(CSV *csv){
    ssize_t read; size_t length = 0; char *line = NULL;

    /* leer linea a "read" hasta EOF */
    while((read = getline(&line, &length, csv->fd) != EOF)){
        
        Song* song = createSong();

        strcpy(song->name, get_csv_field(line, 0));

        strcpy(song->artist, get_csv_field(line, 1));
        strcpy(song->year, get_csv_field(line, 3));
        strcpy(song->playlist, get_csv_field(line, 4));

        int i = 1;
        List *genres = genresToList(get_csv_field(line, 2));



        strcat(buf, "Name: "); strcat(buf, song->name); strcat(buf, "\n");
        strcat(buf, "Artist: "); strcat(buf, song->artist); strcat(buf, "\n");
        strcat(buf, "Genres: \n");
        for(char* data = (char*)listHead(genres); data != NULL; data=(char*)listNext(genres)) {
            strcat(buf, "  ");
            strcat(buf, data);
            strcat(buf, "\n");
        }
        strcat(buf, "Year: "); strcat(buf, song->year); strcat(buf, "\n");
        strcat(buf, "Playlist: "); strcat(buf, song->playlist); strcat(buf, "\n");

        strcat(buf, "\n");
    }
}

void CSVimport(CSV *csv, char *name){

    
    csv->fd = fopen(name, "rw");
    if(!csv->fd){
        printf("Error abriendo archivo %s\n", name);
    }


    populateList(csv);
    
}

void CSVexport(CSV *csv, char *name){
    
}

void CSVcreate(CSV *csv){
    csv->fd = NULL;
    csv->list = listCreate();
    csv->name = NULL;
}

