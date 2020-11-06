#include <stdio.h>
#include <stdlib.h>

// A Tree node
struct Node
{
	char ch;
	int freq;
	struct Node *left, *right;
};
typedef struct Node Node_b;

Node_b* createNode(char ch, int freq)
{
    Node_b* node = malloc(sizeof(Node_b));

	node->ch = ch;
	node->freq = freq;
    
	return node;
}
