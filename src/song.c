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
    scanf("%[^\n]*s", generosString); //Lee como un string completo a los generos, estos se separan en la función sig.
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
    for(Song* songAux = listFirst(list); songAux != NULL; songAux = listNext(list)){
        if(strcmp(songAux->name, song->name) == 0){ //Comprueba si el elemento aux, es igual a uno ya existente
                existe = 1; //Si es así cambia este valor
                break;
        }
    }
    
    //Si no existia otro agrega la nueva canción a la lista
    if(!existe){
        listPushBack(list, song);
    } else {
        strcat(buf, "\x1b[31mError:  la cancion ya existe\x1b[0m\n"); //Si existia otro no lo guarda y muestra este mensaje
    }

    return existe;

}

int deleteSong(List *list){
    char busqueda[60];
    int found = 0;

    printf("Introduce el nombre de la cancion a borrar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();
    
    for(Song *song = listFirst(list); song != NULL; song = listNext(list)){

        if(strcmp(song -> name, busqueda) == 0){ //Comprueba si hay alguna coincidencia 
            strcat(buf, "Cancion eliminada: \n");
            listPopCurrent(list); //Elimina si hay coincidencia
            found = 1;
            return EXIT_SUCCESS;
        }
    }

    if (!found) {
        strcat(buf, "\033[0;31mError: Cancion no encontrada \033[0m \n"); //En caso de no encontrar la canción
        return EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}
