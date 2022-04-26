#include "util.h"
#include "string.h"

char buf[5000];

// castea un puntero (void *) a (Song *)

List *genresToList(const char *genre){
    List *list = listCreate();

    char *genresCopy = strdup(genre);
    char *token = strtok(genresCopy, ",");

    int flag = 0;
    while(token != NULL){
        if (flag) listPushBack(list, token+1);
        else listPushBack(list, token);
        flag = 1;

        token = strtok(NULL, ",");
    }
        
    return list;
}

void clrscr() {
#if defined WINDOWS || defined _win32 || defined WIN32
    system("cls");
#else 
    system("clear");
#endif
};
