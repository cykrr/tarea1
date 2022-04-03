#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "list.h"
#include "menu.h"
#include <string.h>
/* Mostrar nombres de las listas de reproducción ():
 * La aplicación muestra por pantalla los nombres
 * de todas las listas de reproducción y la
 * cantidad de canciones que tiene cada lista.
 */
int showPlaylists();

/*  Mostrar una lista de reproducción (char* Lista_reproduccion):
 *  El usuario ingresa el nombre de una lista de reproducción y
 *  la aplicación muestra por pantalla todas las canciones 
 *  pertenecientes a ella (y su respectiva información).
 *  Si la lista de reproducción no existe se debe mostrar
 *  un mensaje por pantalla. 
 */
int showPlaylist(char *playlist, List *lists);

int deletePlaylist(List *playlists, char *name);

int playlistImport(List *playlists, List *canciones, List* add);

List *findPlaylist(List* playlists, char *name);

int addSongPtr(List* playlist, Song* cancion);

#endif
