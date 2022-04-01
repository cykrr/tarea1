/* Entrada y salida estándar */
#include <stdio.h>

/* manipulación de Strings */
#include <string.h>

#include "csv.h"
#include "menu.h"
#include "util.h"

// Tarea 1:
/* 
  1.- Declaración de funciones

*/


/* Agregar canción (char* nombre, char*
 * artista, char** géneros, int año, char*
 * Lista_reproducción): El usuario ingresa
 * los datos de una canción y la aplicación
 * deberá agregarla en la lista de reproducción
 * indicada por el usuario. Además debe 
 * validarse que la canción no exista
 * previamente en la lista de reproducción. 
 * */
int addSong();

/* Buscar cancion por nombre (char* nombre):
 * El usuario ingresa el nombre de una canción
 * y la aplicación muestra por pantalla todas
 * las canciones (y su respectiva información) 
 * que tengan ese nombre. Si no existe ninguna 
 * canción con ese nombre debe mostrar un aviso. 
 */
int searchSong(List *list);

/*  Buscar canción por artista (char* artista):
 *  El usuario ingresa el nombre de un artista
 *  o banda y la aplicación muestra por pantalla
 *  todas las canciones (y su respectiva 
 *  información) que pertenezcan al artista 
 *  indicado. De no existir el artista,
 *  debe mostrar un mensaje por pantalla. 
 */
int searchArtist(char *artist);

/* Buscar cancion por género (char* género):
 * El usuario ingresa el nombre de un género
 * musical y la aplicación muestra por
 * pantalla todas las canciones (y su 
 * respectiva información) que pertenezcan
 * al género indicado. De no existir el
 * género, debe mostrar un mensaje por pantalla. 
 */
int searchGenre(List *list);

/* Eliminar cancion (char* Nombre, char* artista, int año):
 * El usuario ingresa el nombre de una canción y la
 * aplicación elimina la canción correspondiente de todas
 * las listas de reproducción correspondientes. De no 
 * existir la canción se debe mostrar un aviso por pantalla.
 */
int deleteSong(char *song, char * artist, int year);


/* Mostrar todas las canciones ():
 * Muestra todas las canciones de Helen,
 * sin importar a qué lista de
 * reproducción pertenezca. 
 */
int showAllSongs();

/* main function */
int main(){

    char in = '\0';
    CSV csv;

    CSVcreate(&csv);

    mostrarMenu(csv.list, 0);

    int repetida = 0;

    while(in != 'q' ){

        scanf("%c", &in);
        getchar();

        switch(in) {
            
            case 'i':
                addSong(csv.list);
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

        mostrarMenu(csv.list, repetida);

    }


    /* importamos las canciones en CSV */
    //importCSV(&csv, "Canciones.csv");

    //exportCSV(&csv, "Canciones.csv");

    return 0;
}

int addSong(List *list){

    Song *song = createSong();

    printf("Nombre cancion: ");
    scanf("%[^\n]*s", song->name);
    getchar();

    printf("\nArtista: ");
    scanf("%[^\n]*s", song->artist);
    getchar();

    printf("\nGeneros: (separados por comas. Ejemplo: Rock, Pop)\n");
    scanf("%[^\n]*s", song->genres);
    getchar();

    printf("\nPlaylist: ");
    scanf("%[^\n]*s", song->playlist);
    getchar();

    printf("\nAño: ");
    scanf("%[^\n]*s", song->year);
    getchar();
    

    putchar('\n');

    int existe = 0;
    Song *songAux = voidToSong(listHead(list));
    while (songAux != NULL){ 
        if(strcmp(songAux->name, song->name) == 0){
                existe = 1;
                break;
        }
        songAux = voidToSong(listNext(list));
    }
    if(!existe){
        listPushBack(list, song);
    } else {
        strcat(buf, "\x1b[31mError:  la cancion ya existe\x1b[0m\n");
    }

    return existe;
}

int searchSong(List *list){

    char busqueda[30];
    int found = 0;

    printf("Introduce el nombre de la canción a buscar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();

    for (Song *song = listHead(list); song != NULL; song = listNext(list)){

        if(strcmp(song->name, busqueda) == 0){
            strcat(buf, "Resultado busqueda: \n");
            mostrarCancion(song);
            found = 1;

        }
    }
    if (!found) {
        strcat(buf, "\033[0;31mError: Cancion no encontrada \033[0m \n");
    }
    return EXIT_SUCCESS;
}

int searchGenre(List *list){
    char busqueda[30];
    int found = 0;
    printf("Introduce el genero que desea buscar:\n");
    scanf("%[^\n]*s", busqueda);
    getchar();
    for(Song *song = listHead(list); song != NULL;song = listNext(list)) {
        for(char* name = listHead(song->genres); name != NULL; name = listNext(list)) {
            if (strcmp(busqueda, name) == 0) {
                mostrarCancion(song);
            }
        }

    }
    if (!found) {
        strcat(buf, "\033[0;31mError: Ninguna cancion con ese genero en la lista \033[0m \n");
    }
    return EXIT_SUCCESS;
}
