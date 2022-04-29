#include "carrito.h"
#include <stdio.h>
#include "util.h"
#include "item.h"

int deleteItem(Cart *cart){
    listPopFront(cart->list);

    return EXIT_FAILURE;
}

Cart *cartCreate(char *cartName) {
    Cart *cart = malloc(sizeof(Cart));
    if (!cart) {
        strcat(buf, COLOR_RED "Error reservando memoria" COLOR_RESET);
        return NULL;
    }
    strcpy(cart->name, cartName);
    cart->size = 0;
    cart->total = 0;
    cart->list = listCreate();
    return cart;
}

void addToCart(Map *mapCarts, Map* mapName) {
    char cartName[60];
    char productName[100];
    printf("Ingrese el nombre del carrito: ");
    scanf("%[^\n]*s", cartName);
    getchar();
    Cart *cart = searchMap(mapCarts, cartName);
    if (!cart) {
        cart = cartCreate(cartName);
    }
    printf("Ingrese nombre del producto a agregar");
    scanf("%[^\n]*s", productName);

    Item *item = searchMap(mapName, productName);

    // nombre producto
    // cuantos productos?
    // añadir producto.
}

void showCarts(Map *mapCarts) {
    for(Cart *cart = firstMap(mapCarts); 
            cart != NULL; 
            cart = nextMap(mapCarts)) {
        strcat(buf, "Nombre carrito: ");
        strcat(buf, cart->name);
        strcat(buf, "\n");
        strcat(buf, "Cantidad de productos: ");
        {
            char productos[10];
            sprintf(productos, "%d", cart->size);
            strcat(buf, productos);
        }
        strcat(buf, "\n");
        strcat(buf, "Total a pagar: ");
        {
            char total[10];
            sprintf(total, "%d", cart->total);
            strcat(buf, total);
        }
        strcat(buf, "\n");

    }
}
