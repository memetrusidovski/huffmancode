#include <stdio.h>
#include <stdlib.h>

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
struct LinkedList {
   node* head;
   //node* tail;
};
typedef struct LinkedList LinkedList_s;


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
LinkedList_s createSortedList()
{
   LinkedList_s list = {NULL};
   return list;
}

node* createStackNode(leaf* l){
    node* temp = malloc(sizeof(node));
    temp->data = l->freq;

    temp->leaf_data = l;

    return temp;
}


void insert(LinkedList_s* head, node* l) {
    

    if(head->head == NULL){
        head->head = l;
    }
    else if (head->head->data > l->data){
        l->ptr = head->head;
        head->head = l;
    }
    else{
    node *prev = (node*)malloc(sizeof(node));
    node *next = head->head;
    int i = 0;

    while(next != NULL && i == 0){
       
        if (next->data <= l->data){
            prev->ptr = l;
            l->ptr = next;
            i = 1;
        }
        prev = next;
        next = next->ptr;
    }
    if (next == NULL){
        prev->ptr = l;
        l->ptr = next;
    }
   
    free(prev);
    }

}


node* dequeue(LinkedList_s *list){
    node* temp = (node*)malloc(sizeof(node));
    temp = list->head;
    list->head = list->head->ptr;

    return temp;
}

void insertLeaf(LinkedList_s *list, leaf* l){
    node* n = createStackNode(l);

    insert(list, n);
}

void buildTreeTest(){
    LinkedList_s list = createSortedList();
    leaf* l1 = createLeaf('x', 3);
    leaf* l2 = createLeaf('a', 2);
    leaf* l3 = createLeaf('h', 5);
    leaf* l4 = createLeaf('m', 7);
    leaf* l5 = createLeaf('b', 5);
    node* n1 = createStackNode(l1);
    node* n2 = createStackNode(l2);
    node* n3 = createStackNode(l3);
    node* n4 = createStackNode(l4);
    node* n5 = createStackNode(l5);

    insert(&list, n1);
    insert(&list, n2);
    insert(&list, n3);
    insert(&list, n4);
    insert(&list, n5);

    printf("%d\n", dequeue(&list)->leaf_data->freq);
    printf("%d\n", dequeue(&list)->leaf_data->freq);
    printf("%c\n", dequeue(&list)->leaf_data->ch);
    printf("%c\n", dequeue(&list)->leaf_data->ch);
    printf("%d\n", dequeue(&list)->leaf_data->freq);
}
/*
int main(){
    int num;
    node *head, *p;
    head = NULL;
    
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 


    for(int i = 0; i <= size-1; i++)
            head = insert(head, freq[i], createLeaf(arr[i], freq[i]));


    LinkedList_t list = llCreate(head);

    for(int i = 0; i <= size-1; i++){
        printf("%d\n", dequeue(&list)->leaf_data.ch);
    }


    free_list(head);
    return 0;
}*/