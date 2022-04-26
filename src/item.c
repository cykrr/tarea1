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

int deleteSong(List *list){
    char busqueda[60];

    printf("Introduce el nombre de la cancion a borrar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();
    
    Song *cancion = findSong(list, busqueda);
    if(cancion) { 
            listPopCurrent(list);
            return EXIT_SUCCESS;
    } else {
        strcat(buf, "\033[0;31mError: Cancion no encontrada \033[0m \n");
        return EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}

Song *findSong(List *playlist, char *name) {
    int existe = 0;
    for(Song* songAux = listFirst(playlist); songAux != NULL; songAux = listNext(playlist)){
        if(strcmp(songAux->name, name) == 0){
            return songAux;
        }
    }
    return NULL;
}
