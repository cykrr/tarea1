#include "map.h"
#include "item.h"
#include <string.h>

/* funcion podria ir en util.h */
int isEqualString(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

void listItems(Map *map);
void showItemNoBuf(Item *item);


int main() {
    Map* mapaDePrueba = createMap(isEqualString);
    Item *item = createItem();
    /* Insertamos un item */
    strcpy(item->name, "Leche 200ml");
    strcpy(item->brand, "colun");
    strcpy(item->type, "lacteo");
    item->stock = 2;
    item->price = 500;

    insertMap(mapaDePrueba, item->name, item);

    listItems(mapaDePrueba);
}

void listItems(Map* map) {
    for(Item *item = firstMap(map); item != NULL; item = nextMap(map)) {
        showItemNoBuf(item);
    }
}

void showItemNoBuf(Item *item) {
    printf("Nombre: %s\n", item->name);
    printf("Marca: %s\n", item->brand);
    printf("Tipo: %s\n", item->type);
    printf("Stock: %d\n", item->stock);
    printf("Precio: $%d\n", item->price);
}
