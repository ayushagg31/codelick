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

bool haspathsum(node *root, int sum)
{
    if(root==NULL)
        return false;;
    if(root->left == NULL and root->right == NULL)
        if(root->data == sum)
            return true;
    if(haspathsum(root->left,sum-root->data))
        return true;
    if(haspathsum(root->right,sum-root->data))
        return true;
    return false;

}
int main()
{
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
    if(haspathsum(root, 14))
        cout<<"Their exists a path from root to leaf in given tree";
    else
        cout<<"Their is no path exists in given tree";

	return 0;
}

