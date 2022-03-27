#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
typedef struct Node {
    void *data;
    Node *next;
    Node *prev;
}Node;

typedef struct LinkedList {
    Node *currrent;
    Node *tail;
    Node *current;
}List;

Node *createNode(void * data){
	Node *n = (Node*) calloc(1, sizeof(Node));
  	n -> data = data;
  	n -> next = NULL;
 	return n;
}

List *createList(){
	list = (List *) calloc(1,sizeof(List));
	list -> head = NULL;
	list -> tail = NULL;
	list -> current = NULL;
	return list;
}

void pushBack(List * list, void * data) {
    Node *nodo = createNode(data);
    if(list -> head == NULL){
      list -> head = nodo;
    }else{
      list -> tail -> next = nodo;
    }
    list -> tail = nodo;
}

#endif
