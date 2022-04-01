#include "util.h"

char buf[5000];

// castea un puntero (void *) a (Song *)
Song *voidToSong(void *ptr){
    return (Song*)ptr;
}

List *genresToList(const char *genre){
    List *list = listCreate();
    char *token = strtok(genresCopy, ",");

    while(token != NULL){
        listPushBack(list, token);
        token = strtok(NULL, ",");
    }
        
    return list;
}
