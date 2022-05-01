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
    char name[60];
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

void popLastCart(Map* mapCarts, Map* mapNames);

void cartCheckout(Map *mapCarts, Map *mapNames);

void deleteStock(Map *mapNames, Cart *cart);

int stockCheck(Cart *cart, Map *mapNames);

#endif
