#include "list.h"

List *createList()
{
    List *list = (List*)malloc(sizeof(List));
    return list;
}

Node *createNode() 
{
    Node *node = (Node*)malloc(sizeof(Node));
    return node;
}
