#include "menu.h"
#include "util.h"
#include "string.h"
#include "map.h"
#include "item.h"

void mostrarMenu(){
    clrscr();
    printf("%s", buf);
    strcpy(buf, "");

    printf("Tienda\n");

    printf("'i' : Importar archivo por nombre\n");
    printf("'e' : Exportar archivo por nombre\n");

    printf("'a' : Agregar producto\n");
    printf("'b' : Mostrar menú de busqueda\n");
    /*printf("'t' : Buscar productos por tipo\n");
    printf("'m' : Buscar productos por marca\n");*/
    printf("'M' : Mostrar todos los productos\n");
    printf("'A' : Agregar al carrito\n");
    printf("'X' : Quitar al carrito\n");

    printf("'p' : Concretar compra\n");
    printf("'C' : Mostrar carritos\n");
    printf("'c' : Mostrar carrito\n");


    printf("'q' : Salir\n");
}

void mostrarMenuBuscar(Map* mapNames, Map* mapTypes, Map* mapBrands){
    clrscr();
    printf("%s", buf);
    strcpy(buf, "");


    printf("Menu de busqueda\n");
    printf("n: Por Nombre\n");
    printf("t: Por Tipo\n");
    printf("m: Por Marca\n");
    printf("e: Salir\n");
    
                
}



