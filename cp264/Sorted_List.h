#ifndef SORTED_H
#define SORTED_H

// A Tree node
typedef struct leaf
{
	char ch;
	int freq;
	struct leaf *left, *right;
}leaf;

//Sorted List Node
typedef struct node{
    int priority;
    leaf* leaf_data;
    struct node *ptr;
} node_sort;

//----- LINKED LIST -----
typedef struct LinkedList_s {
    int height;
    node_sort* head;
   //node* tail;
} LinkedList_s;

void insertLeaf(LinkedList_s *list, leaf* l);
LinkedList_s* createSortedList();
leaf* createLeaf(char ch, int freq);
node_sort* dequeue(LinkedList_s *list);
node_sort* createStackNode(leaf* l);
void insert(LinkedList_s* linked, node_sort* l);

#endif