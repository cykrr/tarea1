#include "menu.h"
#include "util.h"

void mostrarMenu(List* lista, int repetida){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Reproductor de Musica\n");
    printf("i: Ingresar cancion\n");
    printf("n: Buscar cancion\n");
    printf("m: Mostrar lista\n");
    printf("q: Salir\n");


}

void mostrarLista(List *lista, int repetida){
    strcat(buf, "Canciones añadidas:\n");

    if(lista->head){
        for(Node *node = lista->head; node != NULL; node = node->next){
            mostrarCancion(voidToSong(node->data));
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
    strcat(buf, "\n  Género(s): " );
    strcat(buf, song->genres);
    strcat(buf, "\n  Año: " );
    strcat(buf, song->year );
    strcat(buf, "\n\n");
}
