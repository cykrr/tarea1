#include "csv.h"
#include "util.h"
#include "menu.h"

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
    while(tmp[i] !='\0' && tmp[i] != '\n'){

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

        song->genres = genresToList(get_csv_field(line, 2));


        Song*  busqueda = findSong(csv->list, song->name);

        if(!busqueda){
            listPushBack(csv->list, song);
        } else {
            strcat(buf, "\x1b[31mError:  la cancion ");
            strcat(buf, busqueda->name);
            strcat(buf, " ya existe\x1b[0m\n");
        }
    }
}

List *CSVimport(char *name){
    CSV *import = CSVnew();

    char *namecpy = strdup(name);
    if(strchr(namecpy, '.')) *(strchr(namecpy, '.')) = '\0'; 

    strcpy(import->list->name, namecpy);

    import->fd = fopen(name, "r");
    if(!import->fd){ // nos vamos
        free(import);
        return NULL;
    }

    populateList(import);
    fclose(import->fd);
    return import->list;

}

void CSVexport(List *list, char *name){
    remove(name);
    FILE* file = fopen(name, "w");
    if (!file) {
        printf("Error creando el archivo %s\n", name);
    }
    for(Song *song = listFirst(list); song != NULL; song=listNext(list)) {
        fprintf(file, "%s,", song->name);
        fprintf(file, "%s,", song->artist);
        if(song->genres->length != 1) fprintf(file, "\"");

        int i = 0;
        for(char *genre = listFirst(song->genres); genre != NULL; genre = listNext(song->genres), i++){
            fprintf(file, "%s", genre);
            
            if(song->genres->length != i+1)
                fprintf(file, ", ");
        }

        fprintf( file, (song->genres->length != 1) ? "\","  : "," );

        fprintf(file, "%s,", song->year);
        fprintf(file, "%s", song->playlist);

        fprintf(file, "\n");

    }
    fclose(file);
}

void CSVcreate(CSV *csv){
    csv->fd = NULL;
    csv->list = listCreate(); // Almacena Song*
}

CSV *CSVnew() {
    CSV* csv = (CSV*)malloc(sizeof(CSV));
    if(!csv) { 
        strcpy(buf, "Error creando CSV\n");
        exit(1);
    }
    CSVcreate(csv);
    return csv;
}

