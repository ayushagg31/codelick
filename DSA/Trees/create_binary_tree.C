#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree *Newnode(int new_data)
{
	struct tree *new_node = (struct tree *)malloc(sizeof(struct tree));
	new_node->data = new_data;
	new_node->left = NULL;
	new_node->right = NULL;

	return(new_node);
}

int main()
{
	struct tree *root = Newnode(10);
	root->left = Newnode(20);
	root->right = Newnode(17);
	root->right->left = Newnode(33);

	return 0;
}