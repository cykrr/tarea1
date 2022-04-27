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
    int stock;
    int price;

    fflush(stdin);
    printf("Nombre del producto: ");
    scanf("%[^\n]*s", item->name);
    getchar();

    printf("\nMarca: ");
    scanf("%[^\n]*s", item->brand);
    getchar();

    printf("\nTipo de producto: "); scanf("%[^\n]*s", item->type);
    getchar();

    printf("\nCantidadaaa: ");
    scanf("%d",&item->stock);
    getchar();

    printf("\nPrecio: ");
    scanf("%d",&item->price);
    getchar();
    int found = 0;

    if(searchMap(mapNames,item -> name) == NULL){
        insertMap(mapNames, item->name, item);
        insertMap(mapTypes, item->type, item);
        insertMap(mapBrands, item->brand, item);
    }else{
        Item *aux = searchMap(mapNames,item -> name);
        aux->stock += item->stock;
        Item *aux1 = searchMap(mapTypes,item->type);
        aux1->stock += item->stock;
        Item *aux2 = searchMap(mapBrands,item->brand);
        aux2->stock += item->stock;
        found++;
    }

    putchar('\n');

    insertMap(mapNames, item->name, item);
    insertMap(mapTypes, item->type, item);
    insertMap(mapBrands, item->brand, item);

    return EXIT_SUCCESS;

}



void findItem(Map* map, void * key) {

    char name[60];
    printf("Nombre del producto: ");
    scanf("%[^\n]*s",name);
    getchar();

    Item *buscado = searchMap(map,name);
    if(buscado == NULL){
        printf("Producto no encontrado");
    }else{
        showItem(buscado);
    }
    return;
}

void showItem(Item *item){
    strcat(buf, "  Nombre: " );
    strcat(buf,item->name);
    strcat(buf, "  Brand: " );
    strcat(buf,item->brand);
    strcat(buf, "  Type: " );
    strcat(buf,item->type);
    printf("Stock %d",item->stock);
    printf("Price %d",item->price);
    strcat(buf, "\n\n");
}
