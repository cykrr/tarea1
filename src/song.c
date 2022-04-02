#include "song.h"
Song *createSong(){
	Song *song = (Song *)malloc(sizeof(Song));
        strcpy(song->name, "");
        strcpy(song->artist, "");
        strcpy(song->playlist, "");
        strcpy(song->year, "");
        song->genres = NULL;
	return song;
}



int addSong(List *list){

    Song *song = createSong();

    fflush(stdin);
    printf("Nombre cancion: ");
    scanf("%[^\n]*s", song->name);
    getchar();

    printf("\nArtista: ");
    scanf("%[^\n]*s", song->artist);
    getchar();

    {
    printf("\nGeneros: (separados por comas. Ejemplo: Rock, Pop)\n");
    List* generos;
    char generosString[30];
    scanf("%[^\n]*s", generosString);
    generos = genresToList(generosString);
    song->genres = generos;
    getchar();
    }

    printf("\nPlaylist: ");
    scanf("%[^\n]*s", song->playlist);
    getchar();

    printf("\nAño: ");
    scanf("%[^\n]*s", song->year);
    getchar();
    

    putchar('\n');

    int existe = 0;
    for(Song* songAux = listHead(list); songAux != NULL; songAux = listNext(list)){
        if(strcmp(songAux->name, song->name) == 0){
                existe = 1;
                break;
        }
    }

    if(!existe){
        listPushBack(list, song);
    } else {
        strcat(buf, "\x1b[31mError:  la cancion ya existe\x1b[0m\n");
    }

    return existe;

}

int deleteSong(List *list){
    char busqueda[60];
    int found = 0;

    printf("Introduce el nombre de la cancion a borrar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();
    
    for(Song *song = listHead(list); song != NULL; song = listNext(list)){

        if(strcmp(song -> name, busqueda) == 0){
            strcat(buf, "Cancion eliminada: \n");
            listPop(list);
            found = 1;
            break;
        }
    }

    if (!found) {
        strcat(buf, "\033[0;31mError: Cancion no encontrada \033[0m \n");
    }

    return EXIT_SUCCESS;
}
