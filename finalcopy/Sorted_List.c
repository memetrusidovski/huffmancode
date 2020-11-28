#include <stdio.h>
#include <stdlib.h>

#include "Sorted_List.h"


leaf* createLeaf(char ch, int freq)
{
    leaf* node = malloc(sizeof(leaf));

	node->ch = ch;
	node->freq = freq;
    node->left = NULL;
    node->right= NULL;
	return node;
}

//----- CREATE LINKED LIST -----
LinkedList_s* createSortedList()
{
   LinkedList_s* list = malloc(sizeof(LinkedList_s));
   list->height=0;
   return list;
}

node_sort* createStackNode(leaf* l){
    node_sort* temp = malloc(sizeof(node_sort));
    temp->priority = l->freq;
    temp->leaf_data = l;

    return temp;
}


void insert(LinkedList_s* linked, node_sort* l){
    if (linked->head == NULL){//Add the node to an empty list
        linked->head = l;

    }else if ( l->priority <= linked->head->priority){//Add the node to the front 
        l->ptr = linked->head;
        linked->head = l;
    }
    else{

    node_sort *prev = linked->head;// = malloc(sizeof(node_sort));
    node_sort *next = linked->head->ptr;
    int i = 0;

    while(next != NULL && i == 0){
       
        if (l->priority <= next->priority){
            
            i = 1;
        }else{
        prev = next;
        next = next->ptr;}
    }
    
        prev->ptr = l;
        l->ptr = next;
    
    }

    linked->height++;
    

}


node_sort* dequeue(LinkedList_s *list){
    node_sort* temp = list->head;
    list->head = list->head->ptr;

    list->height--;
    return temp;
}

void insertLeaf(LinkedList_s *list, leaf* l){
    node_sort* n = createStackNode(l);

    insert(list, n);
}
/*
int main(void){
    LinkedList_s* linked_list = createSortedList();

    node_sort* list = createStackNode( createLeaf('c', 5) );
    insert(linked_list, list);

    list = createStackNode( createLeaf('r', 3) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('e', 4) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('g', 3) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('q', 2) );
    insert(linked_list, list);
    list = createStackNode( createLeaf('k', 6) );
    insert(linked_list, list);

    printf("%d\n", linked_list->head->ptr->priority);

}*/