#include "list.h"

Node *nodeCreate(void * data){
	Node *n = (Node*) calloc(1, sizeof(Node));
  	n -> data = data;
  	n -> next = NULL;
 	return n;
}

List *listCreate(){
	List *list = (List *) calloc(1,sizeof(List));
	list -> head = NULL;
	list -> tail = NULL;
	list -> current = NULL;
	return list;
}

void listPushBack(List * list, void * data) {
    Node *nodo = nodeCreate(data);
    if(list -> head == NULL){
      list -> head = nodo;
    }else{
      list -> tail -> next = nodo;
    }
    list -> tail = nodo;
}
