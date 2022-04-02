/* Entrada y salida estándar */
#include <stdio.h>

/* manipulación de Strings */
#include <string.h>

#include "csv.h"
#include "menu.h"
#include "util.h"
#include "search.h"
#include "song.h"
/* main function */
int main(){

    char in = '\0';
    CSV csv;

    CSVcreate(&csv);

    mostrarMenu(csv.list, 0);

    int repetida = 0;

    while(in != 'q' ){
        mostrarMenu(csv.list, repetida);
        fflush(stdin);
        scanf("%c", &in);
        getchar();

        switch(in) {
            
            case 'i':
                addSong(csv.list);
                break;
            case 'x':
            	deleteSong(csv.list);
            	break;
            case 'n':
                mostrarMenuBuscar();
                scanf("%c", &in);
                getchar();
                switch(in){
                    case'i':
                        searchSong(csv.list);
                        break;
                    case 'm':
                        searchGenre(csv.list);
                        break;
                    case 'q': {
                        exit(1);
                        break;
                    }
                }
                break;
            case 'm':
                mostrarLista(csv.list, 0);
                break;
            case 'y':
                CSVimport(&csv, "Canciones.csv");
                break;
            case 'e':{
                char archivo[20];
                printf("Nombre archivo: ");
                scanf("%s", archivo);
                CSVexport(&csv, archivo);
                break;
            }


        }


    }


    /* importamos las canciones en CSV */
    //importCSV(&csv, "Canciones.csv");

    //exportCSV(&csv, "Canciones.csv");

    return 0;
}





// Tarea 1:
/* 
  1.- Declaración de funciones

*/


int showAllSongs();

