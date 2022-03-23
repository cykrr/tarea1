#ifndef CSV_H
#define CSV_H
#include <stdio.h>

typedef struct {
    char *name;
    FILE *fd;
}CSV;

/*  Importar canciones desde un 
 *  archivo CSV (char* nombre_archivo):
 *  El usuario ingresa el nombre del
 *  archivo y la aplicación carga 
 *  todas las canciones.
 */
void importCSV(CSV *csv, char *fileName);

/*  Exportar canciones
 *  CSV(char* nombre_archivo):
 *  La aplicación exporta las canciones
 *  y sus datos a un archivo csv indicado
 *  por el usuario.
 */
void exportCSV(CSV *csv, char *fileName);
#endif
