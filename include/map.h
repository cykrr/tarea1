#ifndef MAP_H
#define MAP_H

typedef struct Map Map;

typedef struct Pair {
     void * key;
     void * data;
} Pair;

Map * createMap(int (*is_equal)(void* key1, void* key2));

void insertMap(Map * map, void * key, void * value);

void * eraseMap(Map * map, void * key);

Pair * searchMap(Map * map, void * key);

Pair * firstMap(Map * map);

Pair * nextMap(Map * map);

void setSortFunction(Map* map, int (*lower_than)(void* key1, void* key2));

#endif /* MAP_h */