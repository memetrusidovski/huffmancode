#ifndef LINKED_H
#define LINKED_H

//----- NODE -----
struct  Node {
    char data;
    int count;
    struct Node* next;
};
typedef struct Node Node_t;

//----- LINKED LIST -----
struct LinkedList {
   Node_t* head;
   Node_t* tail;
};
typedef struct LinkedList LinkedList_t;

LinkedList_t* makeList();
#endif