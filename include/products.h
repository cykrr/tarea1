#ifndef PRODUCTS_h
#define PRODUCTS_h
#include "treemap.h"

typedef struct{
    char *nombre;
    char *marca;
    char *tipo;
    int stock;
    long precio;
} Product;

void addProduct(TreeMap *treeNombre, TreeMap *treeMarca, TreeMap *treeTipo);


#endif /* PRODUCTS_h */
