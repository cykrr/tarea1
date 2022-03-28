#include "util.h"

char buf[1024];

// castea un puntero (void *) a (Song *)
Song *voidToSong(void *ptr){
    return (Song*)ptr;
}
