#include "search.h"
int searchSong(List *list){

    char busqueda[30];
    int found = 0;

    printf("Introduce el nombre de la canción a buscar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();

    for (Song *song = listFirst(list); song != NULL; song = listNext(list)){

        if(strcmp(song->name, busqueda) == 0){
            strcat(buf, "Resultado busqueda: \n");
            mostrarCancion(song);
            found = 1;

        }
    }
    if (!found) {
        strcat(buf, "\033[0;31mError: Cancion no encontrada (");
        strcat(buf, busqueda);
        strcat(buf, ")\033[0m\n");
    }
    return EXIT_SUCCESS;
}

int searchGenre(List *list){
    char busqueda[30];
    int found = 0;
    printf("Introduce el genero que desea buscar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();
    for(Song *song = listFirst(list); song != NULL;song = listNext(list)) {
        for(char* name = listHead(song->genres); name != NULL; name = listNext(list)) {
            if (strcmp(busqueda, name) == 0) {
                mostrarCancion(song);
            }
        }

    }
    if (!found) {
        strcat(buf, "\033[0;31mError: Ninguna cancion con ese genero en la lista \033[0m \n");
    }
    return EXIT_SUCCESS;
}
