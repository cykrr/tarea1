#ifndef CARRITO_H
#define CARRITO_H
#include <string.h>
#include "list.h"
#include "map.h"
#include "item.h"

// Item en el carrito
typedef struct {
    // Item en la tienda
    Item *item;
    int stock;
} CartItem;

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

void showCart(Cart *cart);

CartItem *cartItemCreate(Item* item, int stock);

CartItem *searchCartItem(List *list, char *itemName);

void cartCheckout(Map *mapCarts, Map *mapNames, Map *mapTypes, Map *mapBrands);

#endif
