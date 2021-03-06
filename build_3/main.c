#include <stdio.h>
#include <stdlib.h>

#include "Sorted_List.h"
#include "linked_counter.h"


int main(void){
    int q = 1;
    //Make a Frequency List
    LinkedList_t* x = makeList();


    //Create a Sorted List/Priority Queue
    LinkedList_s list = createSortedList();
    leaf* l = malloc(sizeof(leaf));
    //Current node for traversal 
    Node_t* current = x->head;
    
    
    while(current != NULL){

        l = createLeaf(current->data, current->count);
        insertLeaf(&list, l);

        current= current->next;
    }


    for(int i = 0; i < 5; i++)
        printf("%c~~\n", dequeue(&list)->leaf_data->ch);
}