#include <string.h>
#include "playlist.h"
#include "song.h"
#include "list.h"

Playlist *playlistCreate(){
	Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
        strcpy(playlist->name, "");
        playlist->length = 0;
        playlist->songsPl = NULL;
	return playlist;
}


int addPlaylist(List *ListPlaylist,Playlist *playlist){

    if(ListPlaylist == NULL) return 0;
    if (ListPlaylist -> length == 0){
        listPushFront(ListPlaylist,playlist);
    }else{
    int existe = 0;
        for(Playlist* playlistAux = listFirst(ListPlaylist); playlistAux != NULL; playlistAux = listNext(ListPlaylist)){
        if(strcmp(playlistAux->name, playlist->name) == 0){
                existe = 1;
                break;
        }
    }

    if(!existe){
        listPushBack(ListPlaylist, playlist);
    }
    }

}


void showPlaylists(List *ListPlaylist){

    if(ListPlaylist->length){
        strcat(buf, "Playlist añadidas:\n");
        for(Playlist *playlist = listFirst(ListPlaylist); playlist != NULL; playlist = listNext(ListPlaylist)){
            mostrarPlaylist(playlist);
        }
        strcat(buf, "\n");
    } else {
        strcat(buf, "\033[0;31mError:  No hay playlist\n\n\033[0m");
    }
}

void mostrarPlaylist(Playlist *playlist){
    strcat(buf, "  Nombre: " );
    strcat(buf, playlist->name);
    strcat(buf, "\n  Canciones: " );
    strcat(buf, "\n\n");
}