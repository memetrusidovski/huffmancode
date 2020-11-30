/*
------------------------------------------------------------------------------------------
File:    BST.c
Project: huffmancode
Purpose: 
==========================================================================================

Program Description:
  This program Builds the huffman trees and code encode or decode txt files
------------------------------------------------------------------------------------------
Authors:  Memet Rusidovski, Vibeesshanan Thevamanoharan, Tyler Dezeeuw, Arif Omogbolahan Ashogbon, Alexander Schwarze
User ID: rusi1550, thev0240, deze3010, asho0840, schw6340
-------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Sorted_List.h"
#include "linked_counter.h"

#define COUNT 5


void print2D( leaf *root);
void print2DUtil(leaf *root, int space);
bool printCode(leaf* root, char key, char s[]);
void printDecode(leaf* root, char *s, char *saveThisString);

int encodeFile(char *cmdFile, char *cmdSave){
    char fileName [1000];// File name Can't be more than 1000 character long
    strcpy(fileName, cmdFile);
    //Make a Frequency List
    LinkedList_t* x = makeList(fileName);


    //Create a Sorted List/Priority Queue
    LinkedList_s* list = createSortedList();
    node_sort* l;

    //Current node for traversal 
    Node_t* current = x->head;
    
    //Put all characters from frequency list into priority queue
    while(current != NULL){
        l = createStackNode(createLeaf(current->data, current->count));
        
        //printf("%d\n", list->height);
        insert(list, l);

        current= current->next;
    }

    leaf* tempLeaf1 = malloc(sizeof(leaf));
    leaf* tempLeaf2 = malloc(sizeof(leaf));
    leaf* temp = malloc(sizeof(leaf));

    while(list->height > 1){
        tempLeaf1 = dequeue(list)->leaf_data;
        tempLeaf2 = dequeue(list)->leaf_data;

        temp = createLeaf('\0', tempLeaf1->freq + tempLeaf2->freq);
        temp->right = tempLeaf1;
        temp->left = tempLeaf2;

        l = createStackNode( temp );
        insert(list, l);
    }

    leaf* BST_of_Char = dequeue(list)->leaf_data;
    //print2D( BST_of_Char );//Printout a copy of the BST
    
    //for testing the code gen. function
    //Generates a table of the codes for each character 
    current = x->head;
    char s[20];memset(s,0,20);// Set all values to empty;

     while (current != NULL){
        printCode(BST_of_Char, current->data, s);
        printf("%s -> %c\n", s, current->data);
        memset(s,0,20);
        current = current->next;
    }


    FILE *fv;
    char *lineOfText = malloc(sizeof(fv)*2);
    //char s[20];memset(s,0,20);

    //Check if the file exists and if not terminate program
    if((fv = fopen(cmdFile, "r")) == NULL){
        printf("Error! File could not be openned");
        exit(1);
    }

    //Scans a line in the file
    fscanf(fv, "%[^\0]%*c",lineOfText);
    //fclose(fv);

    FILE *saveFile;
    if((saveFile = fopen(cmdSave, "w")) == NULL){
        printf("Error! File could not be openned");
        exit(1);
    }
    
    Node_t* writeListCurrent = x->head;
    while (writeListCurrent != NULL)     
    {
        if(writeListCurrent->data == '\n')
            fprintf(saveFile, "%s%d", "\\n", writeListCurrent->count);
        else
            fprintf(saveFile, "%c%d", writeListCurrent->data, writeListCurrent->count);
        if(writeListCurrent->next != NULL)
            fprintf(saveFile, ":");//, writeListCurrent->data, writeListCurrent->count);
        writeListCurrent = writeListCurrent->next;
   }
   fprintf(saveFile, "\n");

    for(int i = 0; lineOfText[i] != '\0'; i++){
        printCode(BST_of_Char, lineOfText[i], s);
        for(int j = strlen(s) - 1; j >= 0; j--)
            fprintf(saveFile, "%c", s[j]);
        //fprintf(saveFile, "%s", s);
        memset(s,0,20);
    }
   

    return 1;

}

bool printCode(leaf* root, char key, char s[]){
    if (root == NULL)
    {
        return NULL;
    }

    if(printCode(root->right, key, s) == true){
        //printf("1");
        strcat(s, "1");
        return true;

    }
    if(printCode(root->left, key, s) == true){
        //printf("0");
        strcat(s, "0");
        return true;
    }

    if(root->ch == key){
        return true; 
    }
    
    else
    {
        return false;
    }
    


    
}



void print2DUtil(leaf *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%c\n", root->ch); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(leaf *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 

int decodeFile(char *cmdFile, char *cmdSave){
    char fileName [1000];// File name Can't be more than 1000 character long
    strcpy(fileName, cmdFile);
    //Make a Frequency List
    LinkedList_t* x = makeDecodeList(fileName);

    

    //Create a Sorted List/Priority Queue
    LinkedList_s* list = createSortedList();
    node_sort* l;
    

    //Current node for traversal 
    Node_t* current = x->head;
    
    //Put all characters from frequency list into priority queue
    while(current != NULL){
        l = createStackNode(createLeaf(current->data, current->count));
        
        //printf("%d\n", list->height);
        insert(list, l);

        current= current->next;
    }

    leaf* tempLeaf1 = malloc(sizeof(leaf));
    leaf* tempLeaf2 = malloc(sizeof(leaf));
    leaf* temp = malloc(sizeof(leaf));

    while(list->height > 1){//build the tree using a sorted list
        tempLeaf1 = dequeue(list)->leaf_data;
        tempLeaf2 = dequeue(list)->leaf_data;

        temp = createLeaf('\0', tempLeaf1->freq + tempLeaf2->freq);
        temp->right = tempLeaf1;
        temp->left = tempLeaf2;

        l = createStackNode( temp );
        insert(list, l);
    }

    leaf* BST_of_Char = dequeue(list)->leaf_data;
    //print2D( BST_of_Char );//Printout a copy of the BST
    
    //for testing the code gen. function
    //Generates a table of the codes for each character 
    current = x->head;
    char s[20];
    while (current != NULL){
        printCode(BST_of_Char, current->data, s);
        printf("%s -> %c\n", s, current->data);
        memset(s,0,20);
        current = current->next;
    }

    

    FILE *fv;
    //char s[20];

    //Check if the file exists and if not terminate program
    if((fv = fopen(cmdFile, "r")) == NULL){
        printf("Error! File could not be openned");
        exit(1);
    }
    char *lineOfText = malloc(sizeof(fv)*2000000);
    
    //Scans a line in the file
    fscanf(fv, "%[^\0]%*c",lineOfText);
    fclose(fv);


    //Get The Bit Stream
    char *string,*found;
    string = strdup(lineOfText);
    found = strsep(&string,"\n");
    found = strsep(&string,"\n");

    char *decodeString = (char*) malloc(sizeof(fv)*200000);
    decodeString = strdup(found);

    char *saveThisString = (char*) malloc(sizeof(decodeString)); 
    printDecode(BST_of_Char, decodeString, saveThisString);
    
    char t[1000];//Save the file 
    strcpy(t, cmdSave);
    FILE *saveFile;
    printf("%s\n", t);
    if((saveFile = fopen(t, "w")) == NULL){
        printf("Error! File could not be openned");
        exit(1);
    }
    
    
    fprintf(saveFile, "%s", saveThisString);

    fclose(saveFile);

    return 1;

}


void printDecode(leaf* root, char *s, char *saveThisString){
    leaf *current = root;
    
    for(int i = 0; i <= strlen(s); i++){
        if(s[i] =='1'){
            current = current->right;
        }else if(s[i] == '0'){
            current = current->left;
        }
        if(current->ch != '\0'){
            strncat(saveThisString, &current->ch, 1 );
            printf("%c", current->ch);
            current = root;
        }
    }
}