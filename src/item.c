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

    if(searchMap(mapNames,item -> name) == NULL){
        insertMap(mapNames, item->name, item);
    }else{
        Item *aux = searchMap(mapNames,item -> name);
        aux->stock += item->stock;
        found++;
    }

    putchar('\n');


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

