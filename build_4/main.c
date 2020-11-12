#include <stdio.h>
#include <stdlib.h>

#include "Sorted_List.h"
#include "linked_counter.h"

#define COUNT 5

void inorder( leaf* root);
void print2D( leaf *root);
void print2DUtil(leaf *root, int space);

//sasfasfa
int isValidBST(leaf* node, leaf* minNode, leaf* maxNode) {
    if(!node) return 1;//Check for a null and break recursion 
    if((minNode && node->freq <= minNode->freq) || //check if the key is less that the previous and not Null 
        (maxNode && node->freq >= maxNode->freq)) //check if the key is greater than the previous 
        return 0;
    return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
}

int isBST(leaf* node){
    return isValidBST(node,NULL,NULL);//start helper function 
}
//dfsdfsd


int main(void){
    //Make a Frequency List
    LinkedList_t* x = makeList();


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

        l = createStackNode(temp );
        insert(list, l);
    }

    leaf* BST_of_Char = dequeue(list)->leaf_data;
    print2D( BST_of_Char );
    
    //inorder(BST_of_Char);


    if(isBST(BST_of_Char))
    printf("A valid tree\n");
    else 
    printf("Not a valid tree\n");
}


//print out the BST
void inorder( leaf* root){
    if(root==NULL)//reach a deadend or null space end recursion 
		return;

	inorder(root->left);//move left
    if(root->ch == '$')
	printf(" %c\n",root->ch);//prints keys when recursion backtracks 
	inorder(root->right);//go to right node and will print when it reaches null 
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