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
