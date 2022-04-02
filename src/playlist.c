#include "playlist.h"

int showPlaylist(char* name, List* lists) {
    for(List *list = listFirst(lists); list != NULL;
            list = listNext(lists)) {

        if( strcmp(name, list->name) == 0) {
            mostrarLista(list, 0);
        }

    }
    return EXIT_SUCCESS;
}
