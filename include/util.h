#ifndef UTIL_H
#define UTIL_H
#include "song.h"
extern char buf[];
List * genresToList(const char * genre);
List *voidToList(void *ptr);
#endif
