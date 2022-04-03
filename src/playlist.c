#include "playlist.h"
#include "song.h"

int showPlaylist(char* name, List* lists) {
    int found = 0;
    for(List *list = listFirst(lists); list != NULL;
            list = listNext(lists)) {

        if( strcmp(name, list->name) == 0) {
            mostrarLista(list, 0);
            found ++;
        }

    }
    if (!found) strcat(buf, COLOR_RED "Error: no se encontro la playlist\n" COLOR_RESET);
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
            // si no existe la cancion en la playlist, la anadimos
            if(findPlaylist(playlists, i->playlist) != NULL) {
                addSongPtr(findPlaylist(playlists, i->playlist), i);
            }
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
    }
    return EXIT_SUCCESS;
}
