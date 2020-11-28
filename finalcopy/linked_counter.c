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
    node->count=1;
    node->next = NULL;
    return node;
}

//----- CREATE LINKED LIST -----
LinkedList_t* llCreate()
{
   //Node_t* dummy = nodeCreate(firstValue);
   LinkedList_t* list = malloc(sizeof(LinkedList_t));
   list->head =NULL;
   list->tail =NULL;

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
   if(list->head == NULL){
      list->head = temp;
      list->tail = temp;
   }
   else if(isInList(*list, c) == false){
      llLinkAfter(list, list->tail, temp);
   }
}

void printList(LinkedList_t* list){
   Node_t* current = list->head;

   while (current != NULL)     
   {
      printf("[%c] -> %d\n", current->data, current->count);
      current = current->next;
   }
   
}

void printFile(LinkedList_t list){
   Node_t* current = list.head;

   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("program.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   while (current != NULL)     
   {
      fprintf(fptr, "%c%d,", current->data, current->count);
      current = current->next;
   }
   fclose(fptr);
}


LinkedList_t* makeList(char *fileName){
   LinkedList_t* t = llCreate();

   FILE *fv;

    //Check if the file exists and if not terminate program
    if((fv = fopen(fileName, "r")) == NULL){
        printf("Error! File could not be openned");
        exit(1);
    }
   char *s = malloc(sizeof(fv)*2);

    //Scans a line in the file
   fscanf(fv,"%[^\0]%*c",s);

      
   printf("\033[36m"); //Set the text to the color blue
      printf("%s\n", s);
   printf("\x1B[0m"); //Resets the text to default color
   

   for(int i = 0; s[i] != '\0'; i++){
      append(t, s[i]);
   }

   fclose(fv);


   printList(t);
   //printFile(t);

   return t;
}

LinkedList_t* makeDecodeList(char *fileName){
   LinkedList_t* t = llCreate();

   FILE *fv;
   //Check if the file exists and if not terminate program
   if((fv = fopen("savefile.txt", "r")) == NULL){
      printf("Error! File could not be openned");
      exit(1);
    }
   char *s = malloc(sizeof(fv)*2);

    //Scans a line in the file
   fscanf(fv,"%[^\n]%*c",s);

      
   printf("\033[32m"); //Set the text to the color
      printf("%s\n", s);
   printf("\x1B[0m"); //Resets the text to default color
   

   char *string,*found;

   string = strdup(s);

   while( (found = strsep(&string,":")) != NULL ){
      int starter = 1;
      //printf("->'%c'\n",found[0]);
      
      if (found [0] == (char)NULL){
         append(t, ':');
         found = strsep(&string,":");
         t->tail->count = (int) strtol(found,NULL, 0);
      }else{
      if (found[0] == '\\'){
         append(t, '\n');
         starter = 2;
      }
      else{

         append(t, (char) found[0]);
      }
      char *tempString = (char*) malloc(sizeof(found));
      for(int i = starter; i <= strlen(found); i++){
            //printf("%c", found[i]);
            strncat(tempString, &found[i],1);
         }
         //printf(" %s\n", tempString);
         
         t->tail->count = (int) strtol(tempString,NULL, 0);
      }


   }

   
   fclose(fv);

   //Print test functions
   //printList(t);
   //printFile(t);

   return t;
}