#ifndef SORTED_H
#define SORTED_H

// A Tree node
typedef struct leaf
{
	char ch;
	int freq;
	struct leaf *left, *right;
}leaf;

typedef struct node{
    int data;
    leaf* leaf_data;
    struct node *ptr;
} node;

//----- LINKED LIST -----
typedef struct LinkedList_s {
   node* head;
   //node* tail;
} LinkedList_s;

void buildTree();
void insertLeaf(LinkedList_s *list, leaf* l);
struct LinkedList_s createSortedList();
leaf* createLeaf(char ch, int freq);
node* dequeue(LinkedList_s *list);

#endif