//author @ Ayush Aggarwal
//calculate the size of binary tree
// size of binary tree = no of nodes in a binary tree
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int calc_size(struct node *root)
{
    int size = 0;
    if(root==NULL)
        return 0;
    queue <node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *temp = q.front();
        size++;
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return size;
}

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<calc_size(root);
	return 0;
}