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
	if(root->data > max(key1,key2))
		lca(root->left,key1,key2);
	else if(root->data < min(key1,key2))
		lca(root->right,key1,key2);
	else 
		return root;
}

int main()
{
    struct node *root = newNode(10);
    root->left = newNode(-10);
    root->right = newNode(30);
    root->left->right = newNode(8);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(9);
    root->right->left = newNode(25);
    root->right->right = newNode(60);
    root->right->right->right = newNode(78);
    root->right->left->right = newNode(28);
    cout<<lca(root,-10,6)->data;
	return 0;
}

