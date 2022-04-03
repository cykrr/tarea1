#ifndef CSV_H
#define CSV_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "song.h"
#include "util.h"


typedef struct {
    char name[20];
    FILE *fd;
    List *list;
    List *playlists;
}CSV;

/*  Importar canciones desde un 
 *  archivo CSV (char* nombre_archivo):
 *  El usuario ingresa el nombre del
 *  archivo y la aplicación carga 
 *  todas las canciones.
 */
void CSVimport(CSV *csv, char *fileName);

/*  Exportar canciones
 *  CSV(char* nombre_archivo):
 *  La aplicación exporta las canciones
 *  y sus datos a un archivo csv indicado
 *  por el usuario.
 */
void CSVexport(List *list, char *fileName);

void CSVcreate(CSV *csv);
#endif
