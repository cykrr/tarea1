#ifndef CARRITO_H
#define CARRITO_H
#include <string.h>
#include "list.h"
typedef struct Carrito {
    char *nombre;
    // Necesitamos implementar una pila en vez de una lista
    List *lista;
} Cart;

int deleteItem(Cart *cart);

#endif
