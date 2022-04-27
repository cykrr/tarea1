#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"
#include "products.h"
#include "menu.h"


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



int main() {

  TreeMap * treeNombre = createTreeMap(lower_than_string,is_equal_string);
  TreeMap * treeMarca = createTreeMap(lower_than_string,is_equal_string);
  TreeMap * treeTipo = createTreeMap(lower_than_string,is_equal_string);

    char in = '\0';

    while(in != 'q' ){
        mostrarMenu();
        fflush(stdin);
        scanf("%c", &in);
        getchar();

        switch(in) {
          case ('a'): // Agregar Producto
            addProduct(treeNombre,treeMarca,treeTipo);
            break;
          case('b'): // Menu de busqueda
            mostrarMenuBuscar();
            scanf("%c", &in);
            getchar();
            switch(in){
              case'n':// Buscar por nombre
                break;
              case 't':// Buscar por tipo
                break;
              case 'm':// Buscar por marca
                break;
              case 'q': {
                exit(1);
                break;
                    }
            }
            case('m'): // Mostrar Productos
                break;
            case('c'): // Agregar al carrito
                break;
            case('d'): // Eliminar del carrito
                break;
            case('v'): // Concretar compra
                break;
            case('w'): // Mostrar carritos
                break;
            default:
                break;
          } 

    } // while (in != q)
    

    return 0;
}


