#include "song.h"
#include "playlist.h"
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

    addSongPtr(list, song);

    return EXIT_SUCCESS;

}

int deleteSong(List *list){
    char busqueda[60];

    printf("Introduce el nombre de la cancion a borrar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();
    
    Song *cancion = findSong(list, busqueda);
    if(cancion) { 
            listPopCurrent(list);
            return EXIT_SUCCESS;
    } else {
        strcat(buf, "\033[0;31mError: Cancion no encontrada \033[0m \n");
        return EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}

Song *findSong(List *playlist, char *name) {
    int existe = 0;
    for(Song* songAux = listFirst(playlist); songAux != NULL; songAux = listNext(playlist)){
        if(strcmp(songAux->name, name) == 0){
            return songAux;
        }
    }
    return NULL;
}
