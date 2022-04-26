#include "playlist.h"


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


List *findPlaylist(List *playlists, char *name) {
    int existe = 0;
    for(List* list = listFirst(playlists); list != NULL; list = listNext(playlists)){
        if(strcmp(list->name, name) == 0){
            return list;
        }
    }
    return NULL;
}
