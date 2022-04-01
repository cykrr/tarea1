#ifndef SONG_H
#define SONG_H
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    char name[60];
    char artist[30];
    char playlist[10];
    List *genres;
    char year[10];
}Song;

Song *createSong();

#endif
