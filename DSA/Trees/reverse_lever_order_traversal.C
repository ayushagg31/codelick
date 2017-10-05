//author @ Ayush Aggarwal
//Level by level printing of a binary tree using one queues
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

void reverse_level_order(node *root)
{
    stack <node*> s;
    queue <node*>q;
    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);
        if(root->right)
            q.push(root->right);
        if(root->left)
            q.push(root->left);
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

int main()
{
    struct node *root = newnode(10);
    root->left        = newnode(20);
    root->right       = newnode(30);
    root->left->left  = newnode(40);
    root->left->right = newnode(50);
    root->left->right->left = newnode(70);
    root->left->right->right = newnode(80);
    root->right->right = newnode(60);
    root->right->right->left = newnode(90);
	reverse_level_order(root);
    return 0;
}

