#ifndef SORTED_H
#define SORTED_H

// A Tree node
typedef struct leaf
{
	char ch;
	int freq;
	struct Node *left, *right;
}leaf;

typedef struct node{
    int data;
    leaf leaf_data;
    struct node *ptr;
} node;

//----- LINKED LIST -----
struct LinkedList_s {
   node* head;
   //node* tail;
} LinkedList_s;

void buildTree();
void insertLeaf(struct LinkedList_s *list, leaf* l);
struct LinkedList_s createSortedList();
leaf* createLeaf(char ch, int freq);

#endif