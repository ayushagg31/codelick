//author @ Ayush Aggarwal
// Inorder predecessor and successor for a given key in a binary search tree
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

struct node* newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder_pre_suc(node *root, node*& pre, node*& suc, int key)
{
	if(root==NULL)
		return;
	if(root->data == key)
	{
		if(root->left!=NULL)
		{
			node *temp = root->left;
			while(temp!=NULL)
				temp = temp->right;
			pre = temp;
		}
		if(root->right!=NULL)
		{
			node *temp = root->right;
			while(temp!=NULL)
				temp = temp->left;
			suc = temp;
		}
		return;
	}
	if(root->data > key)
	{
		suc = root;
		inorder_pre_suc(root->left,pre,suc,key);
	}
	else
	{
		pre = root;
		inorder_pre_suc(root->right,pre,suc,key);
	}
}

int main()
{
    struct node *root = newnode(50);
    root->left        = newnode(30);
    root->right       = newnode(70);
    root->left->left  = newnode(20);
    root->left->right = newnode(40);
    root->right->left = newnode(60);
    root->right->right = newnode(80);
    int key = 65;
    node *pre = NULL;
    node *suc = NULL;
	inorder_pre_suc(root,pre,suc,key);
	if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor"<<endl;
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";

    return 0;
}