#include "song.h"
#include <stdlib.h>
#include <stdio.h>
Song *createSong(){
	Song *song = (Song *)malloc(sizeof(Song));
	song->name = NULL;
	song->artist = NULL;
	song->playlist = NULL;
	song->genres = NULL;
	song->year = 0;
	return song;
}


