#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products.h"
#include "treemap.h"

typedef struct TreeMap TreeNode;


void addProduct(TreeMap *treeNombre, TreeMap *treeMarca, TreeMap *treeTipo){


    fflush(stdin);
    Product * new;
    printf("Nombre producto: ");
    scanf("%[^\n]*s", new->nombre);
    getchar();

    printf("\nMarca: ");
    scanf("%[^\n]*s",new->marca);
    getchar();

    printf("\nTipo: ");
    scanf("%[^\n]*s",new->tipo);
    getchar();

    printf("\nStock: ");
    scanf("%[^\n]*s",new->tipo);
    getchar();

    printf("\nPrecio: ");
    scanf("%[^\n]*s",new->tipo);
    getchar();

    
    if(searchTreeMap(treeNombre,new -> nombre) != NULL){
        Pair * aux = searchTreeMap(treeMarca,new -> marca);
        Pair * aux2 = searchTreeMap(treeTipo,new -> tipo);
        //no se que este error
        treeNombre -> current -> pair -> value -> stock += new -> stock;
        treeMarca -> current -> pair -> value -> stock += new -> stock;
        treeTipo -> current -> pair -> value -> stock += new -> stock;

    }else{

        insertTreeMap(treeNombre,new -> nombre,new);
        insertTreeMap(treeMarca,new -> marca,new);
        insertTreeMap(treeTipo,new -> tipo,new);
    }
    
    return;
}

