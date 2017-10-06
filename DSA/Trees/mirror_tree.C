//author @ Ayush Aggarwal
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

void mirror_tree(node *root)
{
    if(root==NULL)
        return;
    mirror_tree(root->left);
    mirror_tree(root->right);
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inOrder(struct node* node) 
{
  if (node == NULL) 
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
 
  inOrder(node->right);
}  

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    mirror_tree(root);
    inOrder(root);
	return 0;
}