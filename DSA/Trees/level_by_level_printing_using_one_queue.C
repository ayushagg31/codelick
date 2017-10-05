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

void levelBylevel(node *root)
{
    if(root==NULL)
        return;
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        else
        {
            if(!q.empty())
            {
                cout<<endl;
                q.push(NULL);
            }
        }
    }
}
int main()
{
    struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
	levelBylevel(root);
    return 0;
}

