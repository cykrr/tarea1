#include "menu.h"
#include "util.h"

void mostrarMenu(List* lista, int repetida){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Reproductor de Musica\n");

    printf("'i' : Ingresar cancion\n");
    printf("'n' : Buscar cancion\n");
    printf("'m' : Mostrar lista\n");

    printf("'y' : Importar archivo\n");
    printf("'e' : Exportar archivo\n");

    printf("'q' : Salir\n");


}

void mostrarMenuBuscar(){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Menu de busqueda\n");
    printf("i: Por Nombre\n");
    printf("n: Por Artista\n");
    printf("m: Por Genero\n");
    printf("q: Salir\n");

}

void mostrarLista(List *lista, int repetida){

    if(lista->length){
        strcat(buf, "Canciones añadidas:\n");
        for(Song *song = listHead(lista); song != NULL; song = listNext(lista)){
            mostrarCancion(song);
        }
        strcat(buf, "\n");
    } else {
        strcat(buf, "\033[0;31mError:  No hay canciones\n\n\033[0m");
    }
}

void mostrarCancion(Song *song){
    strcat(buf, "  Nombre: " );
    strcat(buf, song->name);
    strcat(buf, "\n  Artista: " );
    strcat(buf, song->artist);
    strcat(buf, "\n  Género(s):\n" );
    for(char* data = (char*)listHead(song->genres);
            data != NULL; 
            data=(char*)listNext(song->genres)) {
        strcat(buf, "    ");
        strcat(buf, data);
        strcat(buf, "\n");
    }

    strcat(buf, "  Año: " );
    strcat(buf, song->year );
    strcat(buf, "\n  Lista: " );
    strcat(buf, song->playlist);
    strcat(buf, "\n\n");
}
