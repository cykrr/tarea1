#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"
#include "products.h"


/*
  función para comparar claves de tipo string
  retorna 1 si son iguales
*/
int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

/*
  función para comparar claves de tipo string
  retorna 1 si son key1<key2
*/
int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

/*
  función para comparar claves de tipo int
  retorna 1 si son iguales
*/
int is_equal_int(void * key1, void * key2) {
    if(*(int*)key1 == *(int*)key2) return 1;
    return 0;
}

/*
  función para comparar claves de tipo int
  retorna 1 si son key1<key2
*/
int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}

int main() {

    char in = '\0';

    while(in != 'q' ){
        mostrarMenu();
        scanf("%c", &in);
        getchar();

        switch(in) {
            case ('i'): // Importar archivo por nombre
                break;
            case('a'): // Agregar producto
                addProduct(nombre,marca,tipo,stock,precio);
                break;
            case('x'): // Quitar producto
                break;
            case('b'): // Buscar producto por nombre
                Pair *buscado = searchTreeMap(treeNombre,nombre);
                if(buscado != NULL){
                  showProduct();
                }else{
                  printf("no encontrado");
                }
                break;
            case('t'): // Buscar producto por marca
                Pair *buscado = searchTreeMap(treeMarca,marca);
                if(buscado != NULL){
                  showProduct();
                }else{
                  printf("no encontrado");
                }
                break;
            case('m'): // Buscar producto por tipo
                Pair *buscado = searchTreeMap(treeTipo,tipo);
                if(buscado != NULL){
                  showProduct();
                }else{
                  printf("no encontrado");
                }
                break;
            case('n'): // Agregar al carrito
                break;
            case('M'): // Elimnar del carrito
                break;
            case('A'): // Concretar compra
                break;
            case('X'): // Mostrar carritos
                break;
            default:
                break;
          } 

    } // while (in != q)
    

    return 0;
}


