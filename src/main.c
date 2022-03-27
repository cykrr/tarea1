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
int searchGenre(char *genre);

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
                searchSong(csv.list);
                break;
            case 'm':
                mostrarLista(csv.list, 0);
        }
        mostrarMenu(csv.list, repetida);

    }


    /* importamos las canciones en CSV */
    //importCSV(&csv, "Canciones.csv");

    //exportCSV(&csv, "Canciones.csv");

    return 0;
}

Song *voidToSong(void *ptr){
    return (Song*)ptr;
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

    putchar('\n');

    int existe = 0;
    if(list->head)
        for(Node *node = list->head; node != NULL; node= node->next){
            if(strcmp(voidToSong(node->data)->name, song->name) == 0){
                printf("Repetida\n");
                existe = 1;
                break;
            }
        }

    if(!existe){
        listPushBack(list, song);
    }

    return existe;
}
