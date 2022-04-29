#ifndef CARRITO_H
#define CARRITO_H
#include <string.h>
#include "list.h"
#include "map.h"
typedef struct Cart {
    char *name;
    // Necesitamos implementar una pila en vez de una lista
    List *list;

    int size;
} Cart;

int deleteItem(Cart *cart);

void addToCart(Map *mapCarts);

Cart *cartCreate(char *cartName);

#endif
