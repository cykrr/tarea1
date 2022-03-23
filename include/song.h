#ifndef SONG_H
#define SONG_H
typedef struct {
    char name[30];
    char artist[30];
    char playlist[10];
    char **genres;
    int year;
}Song;

Song *createSong(char *name,
        char *artist,
        char **genres,
        int year,
        char *playlist);

#endif
