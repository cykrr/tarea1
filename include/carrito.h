#ifndef CARRITO_H
#define CARRITO_H
#include <string.h>
#include "list.h"
#include "map.h"
#include "item.h"

// Item en el carrito
typedef struct {
    Item *item;
    int stock;
} CartItem;



typedef struct Cart {   //Carrito
    char name[60];
    List *list;         //Lista de productos del carrito
    int size;           //Cantidad de items en el carrito
    int total;          //Total en pesos del carrito
    CartItem lastCartItem;//Ultimo item ingresado al carrito
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

void updateCart(Cart *cart);

void showCartMain(Map *mapCarts);

#endif
