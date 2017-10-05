//author @ Ayush Aggarwal
// Tree traversal in spiral order using one deque => double ended queue
// We use deque as two stack where top half of queue represent first stack 
//and second half represent second stack and both stacks are seperated by null value
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
	deque<node*> q;
	q.push_front(NULL);
	q.push_front(root);
	while(q.front()!=NULL or q.back()!=NULL)
	{
		while(q.front()!=NULL)
		{
			root = q.front();
			q.pop_front();
			cout<<root->data<<" ";
			if(root->left)
				q.push_back(root->left);
			if(root->right)
				q.push_back(root->right);
		}
		while(q.back()!=NULL)
		{
			root = q.back();
			q.pop_back();
			cout<<root->data<<" ";
			if(root->right)
				q.push_front(root->right);
			if(root->left)
				q.push_front(root->left);
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