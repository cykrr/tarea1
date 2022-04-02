
#include <stdio.h>

#include <string.h>
#include <string.h>
#include "list.h"
#include "playlist.h"

List *listPlaylist = listCreate();

void showPlaylists(List *listPlaylist){
	for(playl *playlist = listFirst(listPlaylist); playlist != NULL; playlist = listNext(listPlaylist)){
		printf("Nombre: %s", playl -> name);
	}
}

//addPlaylist(List *list, playl playlist){
//	listPushBack()
//}
