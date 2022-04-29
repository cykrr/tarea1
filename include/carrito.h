#ifndef CARRITO_H
#define CARRITO_H
#include <string.h>
#include "list.h"
#include "map.h"
typedef struct Cart {
    char name[30];
    // Necesitamos implementar una pila en vez de una lista
    List *list;

    int size;
    int total;
} Cart;

int deleteItem(Cart *cart);

void addToCart(Map *mapCarts, Map *mapName);

Cart *cartCreate(char *cartName);

void showCarts(Map *mapCarts);
#endif
