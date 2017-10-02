//author @ Ayush Aggarwal
//Lowest common ancestor of a binary tree in a single traversal
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

node *lca(node *root, int key1, int key2)
{
	if(root==NULL)
		return NULL;
	if(root->data==key2 or root->data==key1)
		return root;
	node *left_lca = lca(root->left,key1,key2);
	node *right_lca = lca(root->right,key1,key2);
	if(left_lca and right_lca)
		return root;
	if(!left_lca and !right_lca)
		return NULL;
	if(left_lca)
		return left_lca;
	if(right_lca)
		return right_lca;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<lca(root,2,5)->data;
	return 0;
}

