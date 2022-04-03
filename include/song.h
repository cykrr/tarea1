#ifndef SONG_H
#define SONG_H
#include "list.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    char name[60];
    char artist[30];
    char playlist[20];
    List *genres;
    char year[10];
}Song;

Song *createSong();


/* Agregar canción (char* nombre, char*
 * artista, char** géneros, int año, char*
 * Lista_reproducción): El usuario ingresa
 * los datos de una canción y la aplicación
 * deberá agregarla en la lista de reproducción
 * indicada por el usuario. Además debe 
 * validarse que la canción no exista
 * previamente en la lista de reproducción. 
 * */
int addSong(List* listas, List * lista);


/* Eliminar cancion (char* Nombre, char* artista, int año):
 * El usuario ingresa el nombre de una canción y la
 * aplicación elimina la canción correspondiente de todas
 * las listas de reproducción correspondientes. De no 
 * existir la canción se debe mostrar un aviso por pantalla.
 */
int deleteSong(List *list);

Song *findSong(List *playlist, char *nombre);

#endif
