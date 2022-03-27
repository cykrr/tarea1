#include "list.h"
#include <stdio.h>

int main(){
    List *list = listCreate();
    Node *node = NULL;
    for(int i = 0; i < 10; i++){
        listPushBack(list, (void*)"asd");
    }

    for(Node * data = list->head; data != NULL; data = data->next){
        printf("%s\n", (const char *)data->data);
    }

    return 0;
}
