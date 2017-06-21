#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree *Newnode(int data)
{
	struct tree *node = (struct tree *)malloc(sizeof(struct tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
struct tree *insert(struct tree *root,int data)
{
	if(root == NULL)
		return Newnode(data);
	else
	{
		if(root->data < data)
		{
			//Go to right
			 root->right= insert(root->right,data);
		}
		else
		{
			//Go to left
			
			root->left = insert(root->left,data);
		}
		return root;
	}
}
void traverse(struct tree *root)
{
	  if (root != NULL)
    {
        traverse(root->left);
        printf("%d \n", root->data);
        traverse(root->right);
    }
}

int main()
{
	struct tree *root = NULL;
	root = insert(root,25);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    traverse(root);
}
