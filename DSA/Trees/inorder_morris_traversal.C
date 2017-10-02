//author @ Ayush Aggarwal
// Morris traversal of a tree
// Traversal without stack and without recursion
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

struct node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(node *root)
{
	if(root==NULL)
		return;
	node *current = root;
	node *pre;
	while(current!=NULL)
	{
		if(current->left==NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		}
		else
		{	
			pre = current->left;
			while(pre->right!=NULL and pre->right !=current)
				pre = pre->right;
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
}

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    inorder(root);
	return 0;
}

	