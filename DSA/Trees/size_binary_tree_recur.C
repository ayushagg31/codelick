//author @ Ayush Aggarwal
// recursive one
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
    if(root == NULL)
        return 0;
    int left_size = calc_size(root->left);
    int right_size = calc_size(root->right);
    return left_size + right_size + 1;
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