//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

struct node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(node *root)
{
	if(root==NULL)
		return;
	stack <node*> s;
	while(true)
	{
		while(root!=NULL)
		{
			s.push(root);
			root = root->left;
		}
		if(s.empty())
			return;
		node *temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
		root = temp->right;
	}
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    inorder(root);
	return 0;
}

