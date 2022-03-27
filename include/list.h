#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    Node *current;
}List;

Node *nodeCreate(void * data);

List *listCreate();

void listPushBack(List * list, void * data);
#endif
