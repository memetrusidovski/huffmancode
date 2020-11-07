#include <stdio.h>
#include <stdlib.h>

// A Tree node
struct Node
{
	char ch;
	int freq;
	struct Node *left, *right;
};
typedef struct Node leaf;

typedef struct node{
    int data;
    leaf leaf_data;
    struct node *ptr;
} node;


leaf* createLeaf(char ch, int freq)
{
    leaf* node = malloc(sizeof(leaf));

	node->ch = ch;
	node->freq = freq;
    
	return node;
}

//----- LINKED LIST -----
struct LinkedList {
   node* head;
   //node* tail;
};
typedef struct LinkedList LinkedList_t;

//----- CREATE LINKED LIST -----
LinkedList_t llCreate(node* dummy)
{
   LinkedList_t list = {dummy};
   return list;
}

node* insert(node* head, int num, leaf* l) {
    node *temp, *prev, *next;
    temp = (node*)malloc(sizeof(node));
    temp->data = l->freq;
    temp->ptr = NULL;
    temp->leaf_data = *l;

    if(!head){
        head=temp;
    } else{
        prev = NULL;
        next = head;
        while(next && next->data<=num){
            prev = next;
            next = next->ptr;
        }
        if(!next){
            prev->ptr = temp;
        } else{
            if(prev) {
                temp->ptr = prev->ptr;
                prev-> ptr = temp;
            } else {
                temp->ptr = head;
                head = temp;
            }            
        }   
    }
    return head;
}

void free_list(node *head) {
    node *prev = head;
    node *cur = head;
    while(cur) {
        prev = cur;
        cur = prev->ptr;
        free(prev);
    }       
}

node* dequeue(LinkedList_t *list){
    node* temp = (node*)malloc(sizeof(node));
    temp = list->head;
    list->head = list->head->ptr;

    return temp;
}



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
}