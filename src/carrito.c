#include "carrito.h"
#include <stdio.h>
#include "util.h"
#include "item.h"

int deleteItem(Cart *cart)
{
    listPopFront(cart->list);

    return EXIT_FAILURE;
}

Cart *cartCreate(char *cartName)
{
    Cart *cart = malloc(sizeof(Cart));
    if (!cart)
    {
        strcat(buf, COLOR_RED "Error reservando memoria" COLOR_RESET);
        return NULL;
    }
    strcpy(cart->name, cartName);
    free(cartName);
    cart->size = 0;
    cart->total = 0;
    cart->list = listCreate();
    return cart;
}

void addToCart(Map *mapCarts, Map *mapName)
{
    char cartName[60];
    char productName[100];
    int stock;

    fflush(stdin);
    printf("Ingrese el nombre del carrito: ");
    scanf("%[^\n]*s", cartName);
    getchar();

    fflush(stdin);
    printf("Ingrese nombre del producto a agregar: ");
    scanf("%[^\n]*s", productName);
    getchar();

    Item *item = searchMap(mapName, productName); //Comprueba que exista el producto
    if (!item)
    {
        strcat(buf, COLOR_RED "Error: No existe dicho producto\n" COLOR_RESET);
        return;
    }

    printf("Cuantos productos desea añadir?: ");
    fflush(stdin);
    scanf("%d", &stock);
    getchar();
    //Comprueba si hay stock sufiente para agregar al carrito
    if(item -> stock < stock){
        strcat(buf, COLOR_RED "Error: Stock insuficiente\n" COLOR_RESET);
        return;
    }

    Cart *cart = searchMap(mapCarts, cartName);
    if (!cart)
    {
        cart = cartCreate(_strdup(cartName));
        insertMap(mapCarts, cart->name, cart);
    }

    //Guarda el ultimo item añadido, después de verificar que el carrito existe
    cart->lastCartItem.item = item;
    cart->lastCartItem.stock = stock;

    CartItem *cartItem = searchCartItem(cart->list, productName);

    if (!cartItem)
    {
        cartItem = cartItemCreate(item, stock);
        listPushBack(cart->list, cartItem);
        cartItem->stock = stock;
        cart->total += cartItem->item->price * cartItem->stock;
        cart->size += stock;
    }else{
        cart->total -= cartItem->item->price * cartItem->stock;
        cartItem->stock += stock;
        cart->size += stock;
        cart->total += cartItem->item->price * cartItem->stock;
    }


}

void showCarts(Map *mapCarts)
{
    int cartCount = 0;

    for (Cart *cart = firstMap(mapCarts);
         cart != NULL;
         cart = nextMap(mapCarts),
              cartCount++)
    {
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
            sprintf(total, "$%d", cart->total);
            strcat(buf, total);
        }
        strcat(buf, "\n");
    }
    if (!cartCount)
    {
        strcat(buf, COLOR_RED "No existen carritos\n" COLOR_RESET);
    }
}

void deleteStock(Map *mapNames, Cart *cart){
    for (CartItem *item = listFirst(cart->list); item != NULL; item = listNext(cart->list))
    {
        Item *aux = item->item;
        aux -> stock -= item -> stock;

    }
}

int stockCheck(Cart *cart, Map *mapNames)
{
    int disponible = 1;
    for (CartItem *item = listFirst(cart->list); item != NULL; item = listNext(cart->list))
    {
        Item *aux = searchMap(mapNames, item -> item -> name);
        if(aux -> stock < item -> stock){
            disponible = 0;
            break;
        }
    }
    return disponible;
}

void showCart(Cart *cart)
{
    strcat(buf,"Productos del carrito: \n");
    for (CartItem *item = listFirst(cart->list); item != NULL; item = listNext(cart->list))
    {
        char texto[100];
        strcat(buf, "\n");
        strcat(buf, item->item->name);
        strcat(buf, " ");
        sprintf(texto, "%d", item->stock);
        strcat(buf, texto);
        strcat(buf, " unidades: ");
        strcat(buf, "\n    Valor: ");
        sprintf(texto, "$%d", item -> item -> price);
        strcat(buf, texto);
        strcat(buf, " c/u \n    Total: ");
        sprintf(texto, "$%d", item -> item -> price * item -> stock);
        strcat(buf, texto);
        strcat(buf, "\n");
    }
}

CartItem *cartItemCreate(Item *item, int stock)
{
    CartItem *new = malloc(sizeof(CartItem));
    new->stock = stock;
    new->item = item;
    return new;
}

CartItem *searchCartItem(List *list, char *itemName)
{
    CartItem *cartItem;
    for (cartItem = listFirst(list);
         cartItem != NULL;
         cartItem = listNext(list))
    {
        if (strcmp(itemName, cartItem->item->name) == 0)
            return cartItem;
    }
    return NULL;
}

void popLastCart(Map* mapCarts, Map* mapNames){
    char *cartName = malloc(sizeof(char) * 60);

    fflush(stdin);
    printf("Ingrese el nombre del carrito: ");
    scanf("%[^\n]*s", cartName);
    getchar();
    Cart* cartAux = searchMap(mapCarts, cartName);
    if (cartAux == NULL){
        strcat(buf, "El carrito \"");
        strcat(buf, cartName);
        strcat(buf, "\" no existe\n");
        return;
    }
    CartItem* auxSearch = listFirst(cartAux->list);
    while( cartAux->lastCartItem.item != auxSearch->item){
        auxSearch = listNext(cartAux->list);
    }
    //CartItem* item;
    strcat(buf, "El producto ");
    strcat(buf, cartAux->lastCartItem.item->name);
    strcat(buf, " fue eliminado\n\n");
    //listPopBack(cartAux->list);
    auxSearch->stock -= cartAux->lastCartItem.stock;
    //cartAux->total -= item->item->price;

}

void cartCheckout(Map *mapCarts, Map *mapNames)
{
    char *cartName = malloc(sizeof(char) * 60);

    fflush(stdin);
    printf("Ingrese el nombre del carrito: ");
    scanf("%[^\n]*s", cartName);
    getchar();

    Cart *cart = searchMap(mapCarts, cartName);
    if (!cart)
    {
        strcat(buf, "El carrito \"");
        strcat(buf, cartName);
        strcat(buf, "\" no existe\n");
    }
    else
    {
        if(stockCheck(cart, mapNames) == 1)
        {
            showCart(cart);
            strcat(buf, "\nTotal a pagar: "COLOR_GREEN);
            char total[10];
            sprintf(total, "$%d", cart->total);
            strcat(buf, total);
            strcat(buf, "\n");
            strcat(buf, "\nCompra exitosa! \n\n"COLOR_RESET);
            printf("%s", buf);
            deleteStock(mapNames, cart);
            eraseMap(mapCarts, cartName);
        }
        else
        {
            printf("\nCompra fallida: stock insuficiente\n");
            printf("Desea arreglar su carro? y/n");
            char repuesta;
            scanf("%c\n",&repuesta);
            if(repuesta == 'y'){
                updateCart(cart);
                if(stockCheck(cart, mapNames) == 1){
                    showCart(cart);
                    strcat(buf, "\nTotal a pagar: "COLOR_GREEN);
                    char total[10];
                    sprintf(total, "$%d", cart->total);
                    strcat(buf, total);
                    strcat(buf, "\n");
                    eraseMap(mapCarts, cartName);
                    strcat(buf, "\nCompra exitosa! \n\n"COLOR_RESET);
                    deleteStock(mapNames, cart);
                }
            }
        }
    }

    free(cartName);
}


void updateCart(Cart *cart){
    for (CartItem *item = listFirst(cart->list); item != NULL; item = listNext(cart->list))
    {
        while(item -> item -> stock < item -> stock){
            printf("Producto: %s\nEn stock: %d\nCuantos desea llevar?\n",item ->item->name,item -> item -> stock);
            cart -> size -= item -> stock;
            cart->total -= item->item->price * item->stock;
            scanf("%d",&(item->stock));
            cart -> size += item -> stock;
            cart->total += item->item->price * item->stock;
            printf("\n");
        }

    }
}

void showCartMain(Map *mapCarts){

    printf("Ingrese el nombre del carrito: ");
    char cartName[60];
    fflush(stdin);
    scanf("%[^\n]*s", cartName);
    getchar();
    putchar('\n');
    Cart *cart = searchMap(mapCarts, cartName);
    if(cart == NULL){
        strcat(buf,"Carrito no existe\n");
        return;
    }
    showCart(cart);

}          

