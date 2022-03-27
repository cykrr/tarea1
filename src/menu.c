#include "menu.h"

void mostrarMenu(List* lista, int repetida){
    system("clear");
    if (repetida) {
        printf("Error: Cancion repetida.\n\n");
    }

    if(lista->head) mostrarLista(lista, repetida);

    printf("Reproductor de Musica\n");
    printf("i: Ingresar cancion\n");
    printf("q: Salir\n");


}

void mostrarLista(List *lista, int repetida){
    printf("Canciones añadidas\n");

    for(Node *node = lista->head; node != NULL; node = node->next){
        printf("Nombre: %s\n", ((Song*)node->data)->name);
        printf("Artista: %s\n", ((Song*)node->data)->artist);
    }
    putchar('\n');
}

