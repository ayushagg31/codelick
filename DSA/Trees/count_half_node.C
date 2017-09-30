//author @ Ayush Aggarwal
//Count the number of half node in a binary tree

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node *Newnode(int val)
{
	struct node *temp = new node;
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}
int count_half_node(struct node *root)
{
	queue < node* > q;
	int count = 0;
	q.push(root);
	while(!q.empty())
	{
		struct node *temp = q.front();
		q.pop();
		if((!temp->left and temp->right) or (temp->left and !temp->right))
			count++;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	return count;
}
int main()
{
	struct node *root = Newnode(2);
	root->left    = Newnode(7);
    root->right   = Newnode(5);
    root->left->right = Newnode(6);
    root->left->right->left = Newnode(1);
    root->left->right->right = Newnode(11);
    root->right->right = Newnode(9);
    root->right->right->left = Newnode(4);

    cout<<count_half_node(root);

    return 0;
}