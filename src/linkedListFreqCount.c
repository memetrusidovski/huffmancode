#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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


Node_t* nodeCreate(char value)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->data = value;
    node->count=0;
    node->next = NULL;
    return node;
}

//----- CREATE LINKED LIST -----
LinkedList_t llCreate(char firstValue)
{
   Node_t* dummy = nodeCreate(firstValue);
   LinkedList_t list = {dummy, dummy};
   return list;
}

void countUp(Node_t *node)
{
    node->count++;
}

bool isInList(LinkedList_t list, char checkChar){
   bool b = false;

   Node_t* current = list.head;

   while (current != NULL && b == false)     
   {
      if (current->data == checkChar){
         b = true;
         current->count++;
      }
      current = current->next;
   }   

   return b;
}

void llLinkAfter(LinkedList_t *list, Node_t* cursor, Node_t* newNode)
{
   newNode->next = cursor->next;
   cursor->next = newNode;
   if (cursor == list->tail) {
      list->tail = newNode;
   }
}

void append(LinkedList_t* list, char c){
   Node_t* temp = nodeCreate(c);
   if(isInList(*list, c) == false){
      llLinkAfter(list, list->tail, temp);
   }
}

void printList(LinkedList_t list){
   Node_t* current = list.head;

   while (current != NULL)     
   {
      printf("[%c] -> %d\n", current->data, current->count);
      current = current->next;
   }
   
}

int main(void){
   LinkedList_t t = llCreate('c');

   FILE *fv;
   char s[100];

    //Check if the file exists and if not terminate program
    if((fv = fopen("short.txt", "r")) == NULL){
        printf("Error! File could not be openned");
        return 1;
    }

    //Scans a line in the file
    fscanf(fv,"%[^\n]%*c",s);

   printf("%s\n", s);

   for(int i = 0; i < 40; i++){
      append(&t, s[i]);
   }
   append(&t, 'c');
   append(&t, ' ');
   append(&t, 'b');
   printList(t);
}