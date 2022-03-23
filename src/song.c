#include "song.h"
#include <stdlib.h>
#include <stdio.h>
Song *createSong(char *name, char *artist, char **genres,
        int year, char *playlist)
{
    Song *song = (Song *)malloc(sizeof(Song));
    if (!song) {
        printf("Error alocando memoria para canción\n");
        exit(1);
    }
    return song;
}
