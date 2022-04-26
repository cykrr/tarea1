#include "search.h"
#include "string.h"
int searchSong(List *list){

    char busqueda[30];
    int found = 0;

    printf("Introduce el nombre de la canción a buscar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();


    return EXIT_SUCCESS;
}

int searchGenre(List *list){
    char busqueda[30];
    int found = 0;
    printf("Introduce el genero que desea buscar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();
    if (!found) {
        strcat(buf, "\033[0;31mError: Ninguna cancion con ese genero en la lista \033[0m \n");
    }
    return EXIT_SUCCESS;
}

int searchArtist(List *list) {
    char busqueda[30];
    int found = 0;

    printf("Introduce del artista de la canción a buscar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();

    if (!found) {
        strcat(buf, "\033[0;31mError: Cancion no encontrada (");
        strcat(buf, busqueda);
        strcat(buf, ")\033[0m\n");
    }
    return EXIT_SUCCESS;
}
