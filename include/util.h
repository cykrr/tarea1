#ifndef UTIL_H
#define UTIL_H
#include "song.h"
Song *voidToSong(void *ptr);
extern char buf[];
List * genresToList(const char * genre);
#endif
