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

int main(void){
    //Make a Frequency List
    LinkedList_t* x = makeList("short.txt");


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

        temp = createLeaf('$', tempLeaf1->freq + tempLeaf2->freq);
        temp->right = tempLeaf1;
        temp->left = tempLeaf2;

        l = createStackNode( temp );
        insert(list, l);
    }

    leaf* BST_of_Char = dequeue(list)->leaf_data;
    //print2D( BST_of_Char );
    
    //for testing the code gen. function
    /*current = x->head;
    char s[20];
     while (current != NULL){
        printCode(BST_of_Char, current->data, s);
        printf("%s -> %c\n", s, current->data);
        memset(s,0,20);
        current = current->next;
    }*/


    FILE *fv;
    char lineOfText[100];
    char s[20];

    //Check if the file exists and if not terminate program
    if((fv = fopen("short.txt", "r")) == NULL){
        printf("Error! File could not be openned");
        exit(1);
    }

    //Scans a line in the file
    fscanf(fv, "%[^\n]%*c",lineOfText);
    for(int i = 0; i < 40; i++){
        printCode(BST_of_Char, lineOfText[i], s);
        printf("%s\n", s);
        memset(s,0,20);
    }
   



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