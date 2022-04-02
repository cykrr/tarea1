#ifndef SEARCH_H
#define SEARCH_H
#include "list.h"
#include "song.h"
#include "util.h"
#include "menu.h"
/* Buscar cancion por nombre (char* nombre):
 * El usuario ingresa el nombre de una canción
 * y la aplicación muestra por pantalla todas
 * las canciones (y su respectiva información) 
 * que tengan ese nombre. Si no existe ninguna 
 * canción con ese nombre debe mostrar un aviso. 
 */
int searchSong(List *list);

/*  Buscar canción por artista (char* artista):
 *  El usuario ingresa el nombre de un artista
 *  o banda y la aplicación muestra por pantalla
 *  todas las canciones (y su respectiva 
 *  información) que pertenezcan al artista 
 *  indicado. De no existir el artista,
 *  debe mostrar un mensaje por pantalla. 
 */
int searchArtist(List *list);

/* Buscar cancion por género (char* género):
 * El usuario ingresa el nombre de un género
 * musical y la aplicación muestra por
 * pantalla todas las canciones (y su 
 * respectiva información) que pertenezcan
 * al género indicado. De no existir el
 * género, debe mostrar un mensaje por pantalla. 
 */
int searchGenre(List *list);


/* Mostrar todas las canciones ():
 * Muestra todas las canciones de Helen,
 * sin importar a qué lista de
 * reproducción pertenezca. 
 */

int searchPlaylist(List *list);
#endif
