#include "song.h"
Song *createSong(List *list){
	Song *song = (Song *)malloc(sizeof(Song));
        strcpy(song->name, "");
        strcpy(song->artist, "");
        strcpy(song->playlist, "");
        strcpy(song->genres, "");
        strcpy(song->year, "");
	return song;
}


