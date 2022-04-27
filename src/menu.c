#include "menu.h"
#include "products.h"
#include "util.h"
#include <string.h>

void mostrarMenu(){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Supermercado\n");

    printf("'a' : Agregar Producto\n");
    printf("'b' : Buscar\n");
    printf("'m' : Mostrar Productos\n");
    printf("'c' : Agregar al carrito\n");
    printf("'d' : Eliminar del carrito\n");
    printf("'v' : Concretar compra\n");
    printf("'w' : Mostrar carritos\n");
    printf("'q' : Salir\n");
}

void mostrarMenuBuscar(){
    system("clear");
    printf("%s", buf);
    strcpy(buf, "");

    printf("Menu de busqueda\n");
    printf("n: Por Nombre\n");
    printf("t: Por Tipo\n");
    printf("m: Por Marca\n");
    printf("q: Salir\n");

}

void mostrarProducto(Product *product){
    strcat(buf, "  Nombre: " );
    strcat(buf, product->nombre);
    strcat(buf, "\n  Marca: " );
    strcat(buf, product->marca);
    strcat(buf, "  Tipo: " );
    strcat(buf, product->tipo );
    strcat(buf, "\n  Stock: " );
    strcat(buf, product->stock);
    strcat(buf, "\n  Precio: " );
    strcat(buf, product->precio);
    strcat(buf, "\n\n");
}
