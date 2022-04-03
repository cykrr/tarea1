/* Entrada y salida estándar */
#include <stdio.h>

/* manipulación de Strings */
#include <string.h>

#include "csv.h"
#include "menu.h"
#include "util.h"
#include "search.h"
#include "song.h"
#include "playlist.h"
/* main function */
int main(){
    List *listaCanciones = listCreate();
    List *listaPlaylists = listCreate();

    char in = '\0';

    mostrarMenu(listaCanciones, 0);

    int repetida = 0;

    while(in != 'q' ){
        mostrarMenu(listaCanciones, repetida);
        fflush(stdin);
        scanf("%c", &in);
        getchar();

        switch(in) {
            
            case 'i':
                addSong(listaCanciones);
                break;
            case 'x':
            	deleteSong(listaCanciones);
            	break;
            case 'b':
                mostrarMenuBuscar();
                scanf("%c", &in);
                getchar();
                switch(in){
                    case'n':
                        searchSong(listaCanciones);
                        break;
                    case 'g':
                        searchGenre(listaCanciones);
                        break;
                    case 'a':
                        searchArtist(listaCanciones);
                        break;
                    case 'q': {
                        exit(1);
                        break;
                    }
                }
                break;
            case 'm':
                mostrarLista(listaCanciones, 0);
                break;
            case 'y': {
                char archivo[20];
                printf("Nombre archivo: ");
                scanf("%s", archivo);
                getchar();
                break;
            }
            case 'e':{
                char archivo[20];
                printf("Nombre archivo: ");
                scanf("%s", archivo);
                getchar();

                CSVexport(listaCanciones, archivo);
                break;
            }
            case 'p': {
                char opcion = 0;
                while( opcion != 'q') {
                    mostrarMenuPlaylists();
                    scanf("%c", &opcion);
                    getchar();
                    switch(opcion) {
                        case 'n': {
                            printf("Nombre de la nueva playlist: ");
                            char nombre[30];
                            scanf("%s", nombre);
                            getchar();
                            List *playlist = listCreate();
                            strcpy(playlist->name, nombre);
                            listPushBack(csv.playlists, playlist);
                            break;
                        }
                        case 'm': {
                            printf("Nombre de la playlist: ");
                            char nombre[30];
                            scanf("%s", nombre);
                            getchar();
                            showPlaylist(nombre, csv.playlists);

                            break;
                        }
                        case 'M': {
                            for(List* list = listFirst(csv.playlists);
                                list != NULL;
                                list = listNext(csv.playlists)) {

                                mostrarLista(list, 0);
                            }
                        }
                    }
                }
            }

            case 'c': {
                listClean(listaCanciones);
                break;
          }


        }


    }
    return 0;
}

