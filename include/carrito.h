#ifndef CARRITO_H
#define CARRITO_H
#include <string.h>
typedef struct Carrito {
    char *nombre;
    // Necesitamos implementar una pila en vez de una lista
    Lista *lista;
} Carrito;
#endif
