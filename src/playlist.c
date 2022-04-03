#include "playlist.h"
#include "song.h"


int showPlaylist(char* name, List* lists) {

    int found = 0;
    List* find = findPlaylist(lists, name);

    if(find) { 
        mostrarLista(find, 0);
    } else {
        strcat(buf, COLOR_RED "Error: no se encontro la playlist (");
        strcat(buf, name); 
        strcat(buf, ")\n"COLOR_RESET); 

    } 
    return EXIT_SUCCESS;
}

int deletePlaylist(List *playlists, char *name) {
    int found = 0;
    for(List *list = listFirst(playlists); list != NULL; 
            list = listNext(playlists) ) {

        if( strcmp(list->name, name) == 0 ) {
            listPopCurrent(playlists);
            found ++;
        }
    }
    if (!found) {
        strcat(buf, COLOR_RED "Error: no se encontro la" 
                "playlist\n"COLOR_RESET);
        return EXIT_FAILURE;
    }

    // obtener el string sin la extension


    return EXIT_SUCCESS;
}

int playlistImport(
        List *playlists,
        List *canciones, 
        List *add) {

    // si la playlist no existe;
    if(!findPlaylist(playlists, add->name)) { 
        // Recorremos las canciones de la nueva playlist.
        for(Song *i = listFirst(add); i != NULL; i = listNext(add)) {
            // si no existe la playlist:
            List *playlistBusqueda = findPlaylist(playlists, i->playlist);
            if(!playlistBusqueda) { 
                List *list = listCreate(); // la creamos
                strcpy(list->name, i->playlist);
                addSongPtr(list, i); //le anadimos la cancion
                listPushBack(playlists, list); // la anadimos a las playlists
            } else { // si existe la playlist
                addSongPtr(playlistBusqueda, i);
            }
            addSongPtr(canciones, i);

        }
        listPushBack(playlists, add);
    }
    return  EXIT_SUCCESS;
}

List *findPlaylist(List *playlists, char *name) {
    int existe = 0;
    for(List* list = listFirst(playlists); list != NULL; list = listNext(playlists)){
        if(strcmp(list->name, name) == 0){
            return list;
        }
    }
    return NULL;
}

int addSongPtr(List *playlist, Song *cancion) { 
    if(!findSong(playlist, cancion->name)) {
        listPushBack(playlist, cancion);
    } else {
        strcat(buf, "la cancion ");
        strcat(buf, cancion->name);
        strcat(buf, " ya existe\n");

    }
    return EXIT_SUCCESS;
}
