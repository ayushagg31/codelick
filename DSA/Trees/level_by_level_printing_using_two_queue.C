//author @ Ayush Aggarwal
//Level by level printing of a binary tree using two queues
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
    queue <node*> q1,q2;
    q1.push(root);
    while(!q1.empty() or !q2.empty())
    {
        while(!q1.empty())
        {
            root = q1.front();
            q1.pop();
            cout<<root->data<<" ";
            if(root->left)
                q2.push(root->left);
            if(root->right)
                q2.push(root->right);
        }
        cout<<endl;
        while(!q2.empty())
        {
            root = q2.front();
            q2.pop();
            cout<<root->data<<" ";
            if(root->left)
                q1.push(root->left);
            if(root->right)
                q1.push(root->right);   
        }
        cout<<endl;
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

