#include <stdio.h>
#include <stdlib.h>

#include "Sorted_List.h"
#include "linked_counter.h"


int main(void){
    LinkedList_t* x =(LinkedList_t*) malloc(sizeof(LinkedList_t));
    *x = makeList();
    printf("~~~");
    struct LinkedList_s* list = malloc(sizeof(LinkedList_s));
    *list = createSortedList();
    leaf* l = malloc(sizeof(leaf));
    Node_t* current = malloc(sizeof(Node_t));
    current= x->head;
    
    while(current != NULL){
        l = createLeaf(current->data, current->count);
        insertLeaf(list, l);
        current= current->next;
    }

    printf("%c~~\n", list->head->leaf_data.ch);
}