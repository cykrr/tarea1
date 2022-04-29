#ifndef CARRITO_H
#define CARRITO_H
#include <string.h>
#include "list.h"
#include <stdio.h>
#include "map.h"
typedef struct{
    char *name;
    // Necesitamos implementar una pila en vez de una lista
    List *listProducts;
    int totalCart;
} Cart;


typedef struct {
    char name[60];
    char cart[60];
    int price;
    int amount;
    int totalItem;  
}ItemCart;

Cart *createCart();

ItemCart *createItemCart();

int addItemCart(Map *mapCart, Map *mapName);

int deleteItem(Map *mapCart);

#endif
