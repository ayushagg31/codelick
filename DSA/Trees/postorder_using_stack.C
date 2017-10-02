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

void postorder(node *root)
{
    if(root == NULL)
        return;
    stack <node*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
    while(!s2.empty())
    {
        node *temp1 = s2.top();
        s2.pop();
        cout<<temp1->data<<" ";
    }
}

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    postorder(root);
	return 0;
}