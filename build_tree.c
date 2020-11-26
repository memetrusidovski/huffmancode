/*
 -------------------------------------
 File:    build_trees.c
 Project: huffmancode
 A program that takes a list of counted char nodes and uses them to build a huffman tree.
 -------------------------------------
 Author:  Tyler Dezeeuw
 ID:      201533010
 Email:   deze3010@mylaurier.ca
 Version  2020-11-16
 -------------------------------------
 */

//----- LINKED LIST -----
typedef struct LinkedList {
	node *head;
	node *tail;
};

//Huffman tree nodes
typedef struct node {
	char data;
	int count;
	struct node *left, *right;
	struct node *next
};

node* build_tree(LinkedList *LL);
node* sumNode(node *leftChild, node *rightChild);

node* build_tree(LinkedList *LL) {
	while (LL->head != LL->tail) {
		node *sum = sumNode(ll->head, ll->head->next);
		node *cursor = ll->head->next;
		while (cursor->next != NULL && cursor->next->count < sum->count) {
			cursor = cursor->next;
		}
		sum->next = cursor->next;
		cursor->next = sum;
		ll->head = ll->head->next->next;
	}
	ll->tail = ll->head;
	return ll->head;
}

node* sumNode(node *leftChild, node *rightChild) {
	node *sum = malloc(sizeof(node));
	sum->data = NULL;
	sum->count = leftChild->count + rightChild->count;
	sum->left = leftChild;
	sum->right = rightChild;
	sum->next = NULL;
}
