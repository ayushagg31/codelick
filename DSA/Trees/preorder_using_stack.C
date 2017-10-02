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

void preorder(node *root)
{
    if(root == NULL)
        return;
    stack <node*> s;
    while(true)
    {
        while(root !=NULL)
        {
            cout<<root->data<<" ";
            s.push(root);
            root = root->left;
        }
        if(s.empty())
            return;
        root = s.top();
        s.pop();
        root = root->right;
    }
}

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    preorder(root);
	return 0;
}