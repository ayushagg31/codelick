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

void printINORDER(struct tree *root)
{
	if(root == NULL)
		return;
	printINORDER(root->left);
	cout<<root->data;
	printINORDER(root->right);
}

void printPOSTORDER(struct tree *root)
{
	if(root == NULL)
		return;
	printPOSTORDER(root->left);
	printPOSTORDER(root->right);
	cout<<root->data;

}

void printPreorder(struct tree *node)
{
    if (node == NULL)
    	return;
    cout<<node->data<<" ";
    printPreorder(node->left);  
    
    printPreorder(node->right);
}    

int main()
{
	struct tree *root = Newnode(10);
	root->left = Newnode(20);
	root->right = Newnode(17);
	root->right->left = Newnode(33);
	printPOSTORDER(root);
	cout<<endl;
	printPreorder(root);
	cout<<endl;
	printINORDER(root);

	return 0;
}