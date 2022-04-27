#include "item.h"

Item *createItem(){
	Item *item = (Item *)malloc(sizeof(Item));
        strcpy(item->name, "");
        strcpy(item->brand, "");
        strcpy(item->type, "");
        item -> stock = 0;
        item -> price = 0;
	return item;
}


int addItem(Map* mapNames, Map* mapTypes, Map* mapBrands){

    Item *item = createItem();

    fflush(stdin);
    printf("Nombre del producto: ");
    scanf("%[^\n]*s", item->name);
    getchar();

    printf("\nMarca: ");
    scanf("%[^\n]*s", item->brand);
    getchar();

    printf("\nTipo de producto: ");
    scanf("%[^\n]*s", item->type);
    getchar();

    printf("\nCantidad: ");
    scanf("%[^\n]*s", item->stock);
    getchar();

    printf("\nPrecio: ");
    scanf("%[^\n]*s", item->price);
    getchar();

    //Si el producto no esta en la list lo agrega
    //Si ya esta deberia subir el stock pero no me funca
    //Uso el pair como en lab, se me hace mas simple y no sabia como hacerlo sin esto

    if(searchMap(mapNames,item -> name) == NULL){
        insertMap(mapNames, item->name, item);
        insertMap(mapTypes, item->type, item);
        insertMap(mapBrands, item->brand, item);
    }else{
        Pair *aux = searchMap(mapNames,item -> name);
        aux -> data -> stock += item -> stock;
        Pair *aux = searchMap(mapTypes,item->type);
        aux -> data -> stock += item -> stock;
        Pair *aux = searchMap(mapBrands,item->brand);
        aux -> data -> stock += item -> stock;

    }
    

    putchar('\n');

    return EXIT_SUCCESS;

}



