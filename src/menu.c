#include "menu.h"
#include "util.h"

void mostrarMenu(List* lista, int repetida){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Tienda\n");

    printf("'i' : Importar archivo por nombre\n");
    printf("'a' : Agregar producto\n");
    printf("'x' : Quitar producto\n");
    printf("'b' : Buscar producto\n");
    printf("'t' : Buscar productos por tipo\n");
    printf("'m' : Buscar productos por marca\n");
    printf("'n' : Buscar productos por nombre\n");
    printf("'M' : Mostrar todos los productos\n");
    printf("'A' : Agregar al carrito\n");
    printf("'X' : Quitar al carrito\n");

    printf("'p' : Concretar compra\n");
    printf("'C' : Mostrar carritos\n");


    printf("'q' : Salir\n");
}

void mostrarMenuBuscar(){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Menu de busqueda\n");
    printf("n: Por Nombre\n");
    printf("a: Por Artista\n");
    printf("g: Por Genero\n");
    printf("q: Salir\n");

}

void mostrarMenuPlaylists(){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Playlists\n");
    printf("'n': Nueva playlist\n");
    printf("'x': Borrar playlist\n");
    printf("'m': Mostrar playlist\n");
    printf("'M': Mostrar las playlists\n");
    printf("q: Salir\n");

}

void mostrarLista(List *lista, int repetida){

    strcat(buf, "Mostrando playlist ");
    strcat(buf, lista->name);
    strcat(buf, "\n");
    if(lista->length){
        strcat(buf, "Canciones añadidas:\n");
        for(Song *song = listFirst(lista); song != NULL; song = listNext(lista)){
            mostrarCancion(song);
        }
        strcat(buf, "\n");
    } else {
        strcat(buf, COLOR_RED "Error:  No hay canciones en la lista (");
        strcat(buf, lista->name);
        strcat(buf, ")\n"COLOR_RESET);
    }
}

void mostrarCancion(Song *song){
    strcat(buf, "  Nombre: " );
    strcat(buf, song->name);
    strcat(buf, "\n  Artista: " );
    strcat(buf, song->artist);
    strcat(buf, "\n  Género(s):\n" );
    for(char* data = listFirst(song->genres); data != NULL; data=listNext(song->genres)) {
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
