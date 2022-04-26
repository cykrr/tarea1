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
    

    putchar('\n');

    insertMap(mapNames, item->name, item);
    insertMap(mapTypes, item->type, item);
    insertMap(mapBrands, item->brand, item);

    return EXIT_SUCCESS;

}



