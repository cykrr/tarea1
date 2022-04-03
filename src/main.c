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
    strcpy(listaCanciones->name, "Lista principal");
    List *listaPlaylists = listCreate();
    listPushBack(listaPlaylists, listaCanciones);

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
                List *list = CSVimport(archivo);
                playlistImport(listaPlaylists,
                        listaCanciones, 
                        list);
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
                            listPushBack(listaPlaylists, playlist);
                            break;
                        }
                        case 'm': {
                            printf("Nombre de la playlist: ");
                            char nombre[30];
                            scanf("%s", nombre);
                            getchar();
                            showPlaylist(nombre, listaPlaylists);

                            break;
                        }
                        case 'M': {
                            if (listaPlaylists->length)
                            for(List* list = listFirst(listaPlaylists);
                                list != NULL;
                                list = listNext(listaPlaylists)) {

                                strcat(buf, "Playlist: ");
                                strcat(buf, list->name);
                                strcat(buf, "\n");
                                strcat(buf, 
                                        "Cantidad de canciones: ");

                                char str[4];
                                sprintf(str, "%zd", list->length);
                                strcat(buf, str);
                                strcat(buf, "\n");
                                strcat(buf, "\n");
                            }
                            else {
                                strcat(buf, COLOR_RED "Error: no hay playlists\n" COLOR_RESET);
                            }
                            break;
                        }
                        case 'x': {
                            printf("Nombre de la playlist: ");
                            char nombre[30];
                            scanf("%s", nombre);
                            getchar();
                            deletePlaylist(listaPlaylists, nombre);
                            break;
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

