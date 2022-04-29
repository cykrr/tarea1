#include "carrito.h"
#include "map.h"
#include "item.h"


Cart *createCart(){
	Cart *cart = (Cart *)malloc(sizeof(Cart));
    strcpy(cart->name, "");
    List *listProducts = listCreate();
    cart -> listProducts = listProducts;
    cart -> totalCart = 0;
	return cart;
}


ItemCart *createItemCart(){
	ItemCart *itemCart = (ItemCart *)malloc(sizeof(ItemCart));
        strcpy(itemCart->name, "");
        strcpy(itemCart->cart, "");
        itemCart -> amount = 0;
        itemCart -> price = 0;
        itemCart -> totalItem = 0;
	return itemCart;
}


int addItemCart(Map *mapCart, Map *mapName){

    ItemCart *itemCart = createItemCart();

    fflush(stdin);
    printf("Nombre del producto: ");
    scanf("%[^\n]*s", itemCart->name);
    getchar();

    printf("\nCantidad: ");
    scanf("%d", &itemCart->amount);
    getchar();

    printf("\nCarrito: ");
    scanf("%[^\n]*s",itemCart->cart);
    getchar();

    Cart *actualCart = searchMap(mapCart,itemCart->cart);

    if(actualCart == NULL){
        actualCart = createCart();
        strcpy(actualCart->name,itemCart->cart);
        insertMap(mapCart,itemCart->name,actualCart);
    }


    Item *aux = searchMap(mapName,itemCart -> name);


    if( aux == NULL){
        return 0; // producto no existe;
    }else{
        if(aux -> stock < itemCart -> amount){
            return 2; // stock insuficiente
        }
        listPushBack(actualCart -> listProducts,itemCart);
        itemCart -> price = aux -> price;
        itemCart -> totalItem = (itemCart -> price) * (itemCart -> amount);

    }

    return 3;

}

int deleteItem(Map *mapCart){

    char *carro;

    fflush(stdin);
    printf("Nombre del carro: ");
    scanf("%[^\n]*s", carro);
    getchar();

    Cart * actual = searchMap(mapCart,carro);    

    listPopBack( actual -> listProducts);

    return 1;
}