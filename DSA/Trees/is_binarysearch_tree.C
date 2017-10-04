//author @ Ayush Aggarwal
//Root to leaf sum of a binary tree
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

bool isBST(node *root,int min,int max)
{
    if(root==NULL)
        return true;
    if(root->data <=min or root->data > max)
        return false;
    return(isBST(root->left,min,root->data) and 
            isBST(root->right,root->data,max));
}

int main()
{
    struct node *root = newnode(10);
    root->left        = newnode(10);
    root->right       = newnode(19);
    root->left->left  = newnode(-5);
    root->right->right = newnode(21);
    root->right->left = newnode(17);
    if(isBST(root,-100,100))
        cout<<"Given tree is a binary search tree";
    else
        cout<<"Given tree is not a binary search tree";
	return 0;
}

