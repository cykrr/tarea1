/* Entrada y salida estándar */
#include <stdio.h>
/*******************
 * 
 * 
 * 
 * 
 * mapaLista // el ultimo branch
 * 
 * 
/* manipulación de Strings */
#include <string.h>

#include "csv.h"
#include "menu.h"
#include "util.h"
#include "search.h"
//#include "song.h"
//#include "playlist.h"
#include "carrito.h" 
//#include "producto.h" 
#include "list.h" 

/* main function */
int main(){
    List  *listaCarritos = listCreate();
    List  *listaProductos = listCreate();

    char in = '\0';

    int repetida = 0;

    clrscr();
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
                break;
            case('x'): // Quitar producto
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

