#include "menu.h"
#include "util.h"

void mostrarMenu(List* lista, int repetida){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Reproductor de Musica\n");

    printf("'i' : Ingresar Producto\n");
    printf("'x' : Eliminar Producto\n");
    printf("'b' : Buscar Producto\n");

    printf("'m' : Mostrar todos los productos\n");
    printf("'p' : Mostrar carritos de compras\n");

    printf("'y' : Importar archivo\n");
    printf("'e' : Exportar archivo\n");

    printf("'q' : Salir\n");


}

void mostrarMenuBuscar(){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Menu de busqueda\n");
    printf("n: Por Nombre\n");
    printf("a: Por Marca\n");
    printf("g: Por Tipo\n");
    printf("q: Salir\n");

}

void mostrarLista(List *lista, int repetida){

    if(lista->length){
        strcat(buf, "Canciones añadidas:\n");
        for(Song *song = listFirst(lista); song != NULL; song = listNext(lista)){
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
