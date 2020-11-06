/*
------------------------------------------------------------------------------------------
File:    main.c
Project: rusi1550_quiz05
Purpose: 
==========================================================================================

Program Description:
  This program build a binary search tree 
------------------------------------------------------------------------------------------
Author:  Memet Rusidovski
ID:      130951550
Email:   rusi1550@mylaurier.ca
Version  2020-10-31
-------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char key;
    int count;
    struct Node *left, *right;
} Node;

struct Node* newNode(int key);
struct Node* constructBST(int preorder[], int start, int end);

void inorder(struct Node* root);
int isBST(struct Node* node);

int main(void){
    int keys[] = {'c','h','q','k','t'};


    size_t length = sizeof(keys) / sizeof(keys[0]); //Get number of Array elements 
    Node* nn = constructBST(keys,0,(int) length - 1 );// Start BST Constructor with length of array 

    inorder(nn);//Print results in order 
    printf("\n");

    //nn->left->key = 55; change the tree to make it invalid

    if(isBST(nn))
    printf("A valid tree");
    else 
    printf("Not a valid tree");
    
}

struct Node* constructBST(int preorder[], int start, int end){
    if (start > end) return NULL;//end recursion 
        
    Node* root = newNode(preorder[start]);//create new node

    int i = start;
	while( i <= end && preorder[start] >= preorder[i] ) i++;//find the index that is higher than root
   
    root->left=constructBST(preorder,start+1, i-1);//recursively move into left node
    root->right=constructBST(preorder,i, end);//move into right node
    
    return root;
}

struct Node* newNode(int key){
    Node* nn = (Node*) malloc(sizeof(Node));//allocate memory 
    nn->key = key;//set key
    nn->left=NULL;
    nn->right=NULL;

    return nn;
}

void inorder(struct Node* root){
    if(root==NULL)//reach a deadend or null space end recursion 
		return;

	inorder(root->left);//move left 
	printf("%d ",root->key);//prints keys when recursion backtracks 
	inorder(root->right);//go to right node and will print when it reaches null 
}

int isValidBST(Node* node, Node* minNode, Node* maxNode) {
    if(!node) return 1;//Check for a null and break recursion 
    if((minNode && node->key <= minNode->key) || //check if the key is less that the previous and not Null 
        (maxNode && node->key >= maxNode->key)) //check if the key is greater than the previous 
        return 0;
    return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
}

int isBST(struct Node* node){
    return isValidBST(node,NULL,NULL);//start helper function 
}
