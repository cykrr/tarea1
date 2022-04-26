#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products.h"
#include "treemap.h"

typedef struct TreeMap TreeMap;

void addProduct(char *nombre,char *marca,char *tipo,int stock, long precio, TreeMap *treeNombre, TreeMap *treeMarca, TreeMap *treeTipo){
    
    if(searchTreeMap(treeNombre,nombre) != NULL){
        searchTreeMap(treeMarca,marca);
        searchTreeMap(treeTipo,tipo);
        treeNombre -> current -> pair -> value -> stock += stock;
        treeMarca -> current -> pair -> value -> stock += stock;
        treeTipo -> current -> pair -> value -> stock += stock;

    }else{
        Product * new;
        strcpy(new->nombre,nombre);
        strcpy(new->marca,marca);
        strcpy(new->tipo,tipo);
        new -> stock = stock;
        new -> precio= precio;

        insertTreeMap(treeNombre,new -> nombre,new);
        insertTreeMap(treeMarca,new -> marca,new);
        insertTreeMap(treeTipo,new -> tipo,new);
    }
    
    return;
}