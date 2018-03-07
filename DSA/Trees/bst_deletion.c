//author= Kumar Jatin
#include<stdio.h>
#include<stdlib.h>
//using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;
void inorder(struct node*);
void insert(int);
struct node* deletenode(struct node*,int);
int findmin(struct node*);
int main()
{
	insert(200);
	insert(100);
	insert(250);
	insert(50);
	insert(75);
	insert(300);
	printf("Before deletion inorder traversal:\n");
	inorder(root);
	root=deletenode(root,50);	
	printf("\nafter deletion inorder traversal:\n");
	inorder(root);
}
void insert(int x)
{	
	struct node *temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	// check if tree is empty
	if(root==NULL)
	{
		root=temp;
		return;
	}
	// else tree is not empty and we have to find parent of inserted element
	else
	{
		struct node *cur,*parent;
		cur=root;
		parent=root;
		while(cur)
		{	
			parent=cur;
			if(x>cur->data)
			{
				cur=cur->right;
			}
			else
			{
				cur=cur->left;
			}
		}
		if(x<parent->data)
		{
			parent->left=temp;
		}
		else
		{
			parent->right=temp;
		}
	}
}
void inorder(struct node *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%d\t",t->data);
		inorder(t->right);
	}
}
int findmin(struct node *t)
{	
	while(t->left)
	{
		t=t->left;
	}
	return t->data;
}
struct node* deletenode(struct node *t,int value)
{	
	// find the node to be deleted
	if(t==NULL)
	{
		return t;
	}
	else if(t->data<value)
	{
		t->right=deletenode(t->right,value);
	}
	else if(t->data>value)
	{
		t->left=deletenode(t->left,value);
	}
	// we have to delete the node
	else
	{
		// check if  node is leaf node
		if(t->left==NULL && t->right==NULL)
		{
			free(t);
			t=NULL;
			return NULL;
		}
		// if node has only left child
		else if(t->right==NULL)
		{
			struct node *sample=t;
			t=t->left;
			free(sample);
			return t;
		}
		// if node has only right child
		else if(t->left==NULL)
		{
			struct node *sample=t;
			t=t->right;
			free(sample);
			return t;
		}
		// if node has two children
		else
		{
			int var=findmin(t->right);
			t->data=var;
			t->right=deletenode(t->right,var);
			return t;
		}
	}
}
