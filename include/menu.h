#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "song.h"
#include "util.h"

void mostrarMenu();

void mostrarLista(List *lista, int repetida);

void mostrarCancion(Song *song);

void mostrarMenuBuscar();

void mostrarMenuPlaylists();
#endif
