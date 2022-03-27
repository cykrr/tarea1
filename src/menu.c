#include "menu.h"

void mostrarMenu(List* lista){
    system("clear");
    printf("Reproductor de Musica\n");
    printf("i: Ingresar cancion\n");
    printf("q: Salir\n");

    mostrarLista(lista);

}

void mostrarLista(List *lista){
    printf("Canciones añadidas\n");

    for(Node *node = lista->head; node != NULL; node = node->next){
        printf("%s", ((Song*)node->data)->name);
    }
}

