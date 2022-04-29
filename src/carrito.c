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
    int stock;

    fflush(stdin);
    printf("Ingrese el nombre del carrito: ");
    scanf("%[^\n]*s", cartName);
    getchar();

    Cart *cart = searchMap(mapCarts, cartName);
    if (!cart) {
        cart = cartCreate(cartName);
    }

    fflush(stdin);
    printf("Ingrese nombre del producto a agregar: ");
    scanf("%[^\n]*s", productName);
    getchar();

    Item *item = searchMap(mapName, productName);
    if(!item) {
        strcat(buf, COLOR_RED "Error: No existe dicho producto\n" 
                COLOR_RESET);
        return;
    }

    printf("Cuantos productos desea añadir?: ");
    fflush(stdin);
    scanf("%d", &stock);
    getchar();

    CartItem * cartItem = searchCartItem(cart->list, productName);
    if(!cartItem) {
        cartItem = cartItemCreate(item, stock);
    }

    cartItem->stock = stock;
    // añadir producto.
    listPushBack(cart->list, cartItem);
}

void showCarts(Map *mapCarts) {
    int cartCount = 0;
    int itemCount = 0;

    for(Cart *cart = firstMap(mapCarts); 
            cart != NULL; 
            cart = nextMap(mapCarts), 
            cartCount++) {
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
    if (!cartCount) {
        strcat(buf, COLOR_RED "No existen carritos\n" COLOR_RESET);
    }
}

CartItem *cartItemCreate(Item *item, int stock) {
    CartItem *new = malloc(sizeof(CartItem));
    new->stock = stock;
    new->item = item;
    return new;
}    

CartItem *searchCartItem(List *list, char *itemName) {
    CartItem *cartItem;
    for(cartItem = listFirst(list);
            cartItem != NULL;
            cartItem = listNext(list)) {
        if(strcmp(itemName, cartItem->item->name) == 0)
            return cartItem;
    }
    return NULL;
}
