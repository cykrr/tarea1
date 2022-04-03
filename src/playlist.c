
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "list.h"
#include "playlist.h"

void showPlaylists(List *listPlaylist){
	for(playl *playlist = listFirst(listPlaylist); playlist != NULL; playlist = listNext(listPlaylist)){
		printf("Nombre: %s\n", playlist -> name);
		//strcat(buf, playlist -> name)
	}
	getc(stdin);
}

//addPlaylist(List *list, playl playlist){
//	listPushBack()
//}
