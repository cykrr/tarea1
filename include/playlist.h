#ifndef PLAYLIST_H
#define PLAYLIST_H
/* Mostrar nombres de las listas de reproducción ():
 * La aplicación muestra por pantalla los nombres
 * de todas las listas de reproducción y la
 * cantidad de canciones que tiene cada lista.
 */
void showPlaylists();

/*  Mostrar una lista de reproducción (char* Lista_reproduccion):
 *  El usuario ingresa el nombre de una lista de reproducción y
 *  la aplicación muestra por pantalla todas las canciones 
 *  pertenecientes a ella (y su respectiva información).
 *  Si la lista de reproducción no existe se debe mostrar
 *  un mensaje por pantalla. 
 */
int showPlaylist(char *playlist);

typedef struct{
	char name[10];
	int size;
}playl;

//addPlaylist(List *list, playl playlist);
#endif
