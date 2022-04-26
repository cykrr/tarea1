#ifndef ITEM_H
#define ITEM_H
#include "list.h"
#include "util.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    char name[60];
    char brand[30];
    char type[20];
    int stock;
    int price;
}Item;

Item *createItem();


/* Agregar canción (char* nombre, char*
 * artista, char** géneros, int año, char*
 * Lista_reproducción): El usuario ingresa
 * los datos de una canción y la aplicación
 * deberá agregarla en la lista de reproducción
 * indicada por el usuario. Además debe 
 * validarse que la canción no exista
 * previamente en la lista de reproducción. 
 * */
int addItem(Map* mapNames, Map* mapTypes, Map* mapBrands);


/* Eliminar cancion (char* Nombre, char* artista, int año):
 * El usuario ingresa el nombre de una canción y la
 * aplicación elimina la canción correspondiente de todas
 * las listas de reproducción correspondientes. De no 
 * existir la canción se debe mostrar un aviso por pantalla.
 */
int deleteSong(List *list);

Song *findSong(List *playlist, char *nombre);

#endif
