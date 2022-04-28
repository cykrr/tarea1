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


void showList(Map* mapTypes,Item* item, Map* list){ 

    Node* aux= list->head;
    char key[60];
    printf("Nombre de la marca que busca: ");
    scanf("%[^\n]*s",key);
    getchar();
    char in = '\0';
    
    
    searchMap(mapTypes, key);

    
    while(in != 'q' ){
        scanf("%c", &in);
        getchar();

        switch(in) {
            
            case('a'): // Buscar por marca
                char name[60];
                printf("Nombre de la marca que busca: ");
                scanf("%[^\n]*s",name);
                getchar();
                while(aux != NULL){
                    if (name == item->brand){
                        showItem(item);
                    }
                    aux = aux->next;
                }
                break;

            case('x'): // buscar por tipo
                char name[60];
                printf("Nombre del tipo de producto que busca: ");
                scanf("%[^\n]*s",name);
                getchar();
                while(aux != NULL){
                    if (name == item->type){
                        showItem(item);
                    }
                    aux = aux->next;
                }
                
                break;

            case('b'): // buscar por nombre
                while(aux != NULL){
                    showItem(item);
                    
                    aux = aux->next;
                }
                break;
        }
    }
    
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
    char numero[10];
    sprintf(numero, "%d",item->stock);
    strcat(buf, "  Stock: " );
    strcat(buf, numero);
    strcat(buf, "  Precio: " );
    sprintf(numero, "%d",item->price);
    strcat(buf, numero);
    strcat(buf, "\n\n");
}

