#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
typedef struct Node {
    void *data;
    void *next;
}Node;

typedef struct LinkedList {
    Node** nodes;
}List;

Node *createNode();

List *createList();

#endif
