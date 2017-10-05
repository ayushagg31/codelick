//author @ Ayush Aggarwal
// Tree traversal in spiral order using two stacks
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

void spiral_order(node *root)
{
	if(root==NULL)
		return;
	stack <node*> s1,s2;
	s1.push(root);
	while(!s1.empty() or !s2.empty())
	{
		while(!s1.empty())
		{
			root = s1.top();
			s1.pop();
			cout<<root->data<<" ";
			if(root->left)
				s2.push(root->left);
			if(root->right)
				s2.push(root->right);
		}
		while(!s2.empty())
		{
			root = s2.top();
			s2.pop();
			cout<<root->data<<" ";
			if(root->right)
				s1.push(root->right);
			if(root->left)
				s1.push(root->left);
		}
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
	spiral_order(root);
    return 0;
}