/* Entrada y salida estándar */
#include <stdio.h>

/* manipulación de Strings */
#include <string.h>

#include "csv.h"
#include "menu.h"
#include "util.h"
#include "search.h"
#include "carrito.h" 
#include "list.h" 
#include "map.h"
#include "item.h"

int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

/* main function */
int main(){
    List  *listaCarritos = listCreate();
    List  *listaProductos = listCreate();
    Map * mapNames = createMap(is_equal_string);
    Map * mapTypes = createMap(is_equal_string);
    Map * mapBrands = createMap(is_equal_string);

    char in = '\0';

    int repetida = 0;

    while(in != 'q' ){
        mostrarMenu();
        fflush(stdin);
        scanf("%c", &in);
        getchar();

        switch(in) {
            case ('i'): // Importar archivo por nombre
//                List *lista = listaImportarArchivo();
                break;
            case('a'): // Agregar producto
                if(addItem(mapNames,mapTypes,mapBrands) == 1 ){
                    printf("Stock del producto actuliazdo");
                }else{
                    printf("Producto agregado");
                }
                break;
            case('x'): // Quitar producto
                showItem(mapNames -> head -> data);
                break;
            case('b'): // Buscar producto
                break;
            // Mostrar todos los productos por tipo
            case('t'):
                break;
            // Mostrar todos los productos por marca
            case('m'):
                break;
            // Mostrar todos los productos por nombre
            case('n'):
                break;
            case('M'): // Mostrar todos los productos
                break;
            case('A'): // Añadir al carrito
                break;
            case('X'): // Quitar del carrito
                break;
            case('p'): // Concretar compra
                break;
            case('C'): // Mostrar carritos
                break;
            default:
                break;
          } 

    } // while (in != q)
    printf("Bye bye\n");
    return 0;
}

