#include "item.h"
#include "playlist.h"

Item *createItem(){
	Item *item = (item *)malloc(sizeof(item));
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
    scanf("%[^\n]*i", item->stock);
    getchar();

    printf("\nPrecio: ");
    scanf("%[^\n]*i", item->price);
    getchar();
    

    putchar('\n');

    insertMap(mapNames, item->name, item);
    insertMap(mapTypes, item->type, item);
    insertMap(mapBrands, item->brand, item);

    return EXIT_SUCCESS;

}



