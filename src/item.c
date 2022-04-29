#include "item.h"
#include "map.h"
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
    scanf("%d", &item->stock);
    getchar();

    printf("\nPrecio: ");
    scanf("%d", &item->price);
    getchar();
    int found = 0;

    if(searchMap(mapNames,item -> name) == NULL) { 
        insertMap(mapNames, item->name, item);
        insertMapList(mapTypes, item -> type, item);
        insertMapList(mapBrands, item -> brand, item);
    } else{ 
        //comprobar que el producto sea 100% igual(nombre,marca,brand)
        Item *aux = searchMap(mapNames,item -> name);
        aux->stock += item->stock;
        found++;
    }

    putchar('\n');


    return EXIT_SUCCESS;

}

void insertMapList(Map * map, char *key, Item * item){
    List *aux = searchMap(map,key);
    if(aux == NULL){
        aux = listCreate();
        insertMap(map, key, aux);
    }
    listPushBack(aux,item);
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
    strcat(buf, "\n    Brand: " );
    strcat(buf,item->brand);
    strcat(buf, "\n    Type: " );
    strcat(buf,item->type);
    char numero[10];
    sprintf(numero, "%d",item->stock);
    strcat(buf, "\n    Stock: " );
    strcat(buf, numero);
    strcat(buf, "\n    Precio: " );
    sprintf(numero, "%d",item->price);
    strcat(buf, numero);
    strcat(buf, "\n\n");
}

void showItems(Map *nameMap) {
    int itemCount = 0;
    for(Item *item = firstMap(nameMap);
            item != NULL; 
            item = nextMap(nameMap), itemCount++) 
    {
        showItem(item);
    }

    if(!itemCount) {
        strcat(buf, COLOR_RED 
                "Error!: No hay productos agregados\n"
                COLOR_RESET);
    }

}

void showItemsByBrand(Map* mapBrands) {
    char brand[30];
    printf("Ingrese la marca a mostrar: ");
    scanf("%[^\n]*s", brand);
    getchar();
    List *list = searchMap(mapBrands, brand);
    if(!list) {
        strcat(buf, COLOR_RED "Error: no existe la marca ");
        strcat(buf, brand);
        strcat(buf, COLOR_RESET);
        strcat(buf, "\n");
    } else if (list) {
        strcat(buf, "Mostrando lista de productos de la marca ");
        strcat(buf, brand);
        strcat(buf, "\n");
        showList(list);
    }
}

void showItemsByType(Map* mapTypes) {
    char type[30];
    printf("Ingrese tipo de producto a mostrar: ");
    scanf("%[^\n]*s", type);
    getchar();
    List *list = searchMap(mapTypes, type);
    if(!list) {
        strcat(buf, COLOR_RED "Error: no existe el tipo ");
        strcat(buf, type);
        strcat(buf, COLOR_RESET);
        strcat(buf, "\n");
    } else if (list) {
        strcat(buf, "Mostrando lista de productos del tipo ");
        strcat(buf, type);
        strcat(buf, "\n");
        showList(list);
    }
}

void showList(List *list) {
    for(Item *item = listFirst(list);
            item != NULL; 
            item = listNext(list) ){
        showItem(item);
    }
}
