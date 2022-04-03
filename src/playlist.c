#include <string.h>
#include "playlist.h"
#include "song.h"
#include "list.h"
#include "menu.h"

Playlist *playlistCreate(){
	Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
        strcpy(playlist->name, "");
        playlist->length = 0;
        playlist->songsPl = NULL;
	return playlist;
}


void addSongToPlaylist(List *ListPlaylist,Song *cancion){

    if(ListPlaylist == NULL) return;
    if (ListPlaylist -> length == 0){
        Playlist *playlist = playlistCreate();
        strcpy(playlist->name,cancion->playlist);
        List *listaCanciones = listCreate();
        listPushFront(listaCanciones,cancion);
        playlist->songsPl = listaCanciones;
        listPushFront(ListPlaylist,playlist);
    }else{
        int existe = 0;
            for (Playlist *auxPlaylist = listFirst(ListPlaylist); auxPlaylist != NULL; auxPlaylist = listNext(ListPlaylist)){
                if(strcmp(cancion->playlist, auxPlaylist ->name) == 0){
                    listPushBack(auxPlaylist -> songsPl, cancion);
                    existe = 1;
                }
            }

        if(!existe){
            Playlist *playlist = playlistCreate();
            strcpy(playlist->name,cancion->playlist);
            List *listaCanciones = listCreate();
            listPushFront(listaCanciones,cancion);
            playlist->songsPl = listaCanciones;
            listPushBack(ListPlaylist,playlist);
        }
    }
    return;
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

void csvToPlaylist(List *songList,List *ListPlaylist){
    if(songList->length){
        for(Song *song = listFirst(songList); song != NULL; song = listNext(songList)){
            addSongToPlaylist(ListPlaylist,song);
        }
    }
}

void mostrarCancionesPlaylist(List *lista){
    if(lista->length){
        List *listaMostrada = voidToList(lista->head->data);
        mostrarLista(listaMostrada,0);
    }
}

void mostrarLargo(List *lista){
    printf("%zu",lista->head->(*data)->name);
}