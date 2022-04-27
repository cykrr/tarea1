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

    printf("\nTipo de producto: ");
    scanf("%[^\n]*s", item->type);
    getchar();

    printf("\nCantidadaaa: ");
    scanf("%d",stock);
    getchar();

    printf("\nPrecio: ");
    scanf("%d",price);
    getchar();
    int found = 0;

    if(searchMap(mapNames,item -> name) == NULL){
        insertMap(mapNames, item->name, item);
        insertMap(mapTypes, item->type, item);
        insertMap(mapBrands, item->brand, item);
    }else{
        Pair *aux = searchMap(mapNames,item -> name);
        ((Item*)(aux->data))->stock += item->stock;
        Pair *aux1 = searchMap(mapTypes,item->type);
        ((Item*)(aux1->data))->stock += item->stock;
        Pair *aux2 = searchMap(mapBrands,item->brand);
        ((Item*)(aux2->data))->stock += item->stock;
        found++;
    }
    

    putchar('\n');

    return found;

}



void findItem(Map* map, void * key) {

    char name[60];
    printf("Nombre del producto: ");
    scanf("%[^\n]*s",name);
    getchar();

    Pair *buscado = searchMap(map,name);
    if(buscado == NULL){
        printf("Producto no encontrado");
    }else{
        showItem(buscado);
    }


    return;
}

void showItem(Pair *item){
    strcat(buf, "  Nombre: " );
    strcat(buf,((Item*)(item->data))->name);
    strcat(buf, "  Brand: " );
    strcat(buf,((Item*)(item->data))->brand);
    strcat(buf, "  Type: " );
    strcat(buf,((Item*)(item->data))->type);
    printf("Stock %d",((Item*)(item->data))->stock);
    printf("Price %d",((Item*)(item->data))->price);
    strcat(buf, "\n\n");
}