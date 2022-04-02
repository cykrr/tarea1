#include "list.h"
#include "assert.h"

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
        list -> length = 0;
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
    (list -> length )++;
}

void *listHead(List *list){
    if(list && list->head){
        list->current = list->head;
        return list->head->data;
    }

    else return NULL;
}

void * listNext(List * list) {
    if (list == NULL || list->head == NULL || list->current == NULL || list->current->next == NULL) return NULL;
    list->current = list->current->next;
    return (void *)list->current->data;
}

void *listCurrent(List *list) {
    if(list->current) {
        return list->current->data;
    }
    return NULL;
}

void * listPopCurrent(List * list) {
    assert(list != NULL || list->head != NULL);
    
    if (list->current == NULL) return NULL;
    
    Node * aux = list->current;
    
    if (aux->next != NULL) 
        aux->next->prev = aux->prev;
    
    
    if (aux->prev != NULL) 
        aux->prev->next = aux->next;
    
    
    void * data = (void *)aux->data;
    
    if(list->current == list->tail)
        list->tail = list->current->prev;

    if(list->current == list->head)
        list->head = list->current->next;
        
    list->current = aux->prev;



    
    free(aux);
    
    return data;
}

 
void * listPop(List * list) {
  Node *nodo = list->current; 
  void *data = nodo->data;
  if(nodo == list -> head){
    list -> head = nodo -> next;
  }

  if(list -> current -> next != NULL){
    list -> current = list -> current -> next;
  }else{
    list -> current = list -> current -> prev;
    list -> tail = nodo -> prev;
  }
  if(nodo -> prev != NULL){
    nodo-> prev -> next = nodo -> next;
  }
  if(nodo -> next != NULL){
    nodo -> next -> prev = nodo -> prev;
  }
  free(nodo);

return data;
}
