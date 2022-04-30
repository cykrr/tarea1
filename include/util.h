#ifndef UTIL_H
#define UTIL_H

#include "list.h"
#define COLOR_RESET   "\033[0m"
#define COLOR_RED "\033[31m"      /* Red */

extern char buf[];
List * genresToList(const char * genre);
void clrscr();

char *_strdup(const char *str);

#endif
