#include "carrito.h"
#include <stdio.h>
#include "util.h"
#include "item.h"

int deleteItem(Cart *cart){
    listPopFront(cart->list);

    return EXIT_FAILURE;
}

