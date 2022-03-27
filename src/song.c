#include "song.h"
Song *createSong(){
	Song *song = (Song *)malloc(sizeof(Song));
        strcpy(song->name, "");
        strcpy(song->artist, "");
        strcpy(song->playlist, "");
	song->genres = NULL;
	song->year = 0;
	return song;
}


