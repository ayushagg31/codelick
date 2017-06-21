#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct tree
{
	int data;
	struct tree *left,*right;
};

//Implement using linked list
struct stk
{
	int content;
	struct stk *next;
};

struct tree *Newnode(int kata)
{
	struct tree *node = (struct tree*)malloc(sizeof(struct tree));
	node->data = kata;
	node->left = node->right = NULL;
	return node; 
}

void stack_push(struct stk **head_ref,int data)
{
	struct stk *new_node = (struct stk*)malloc(sizeof(struct stk));
	new_node->content = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void stack_pop(struct stk **head_ref)
{	
	if(*head_ref == NULL)
	{
		cout<<"stack is empty";
		return;
	}
	struct stk *del_node = *head_ref;
	int saver = del_node->content;
	cout<<saver<<" ";
	*head_ref = del_node->next;
}

void traversal(struct tree *root)
{
	struct stk *head = (struct stk*)malloc(sizeof(struct stk));
	head->content = root->data;
	head->next = NULL;
	while(head !=NULL)
	{	
		if(root->left != NULL)
		{
			root = root->left;
		}
		else
		{	
			stack_pop(&head);

		}
	}
}

int main()
{
	struct tree *root = Newnode(1);
	root->right = Newnode(3);
	root->left = Newnode(2);
	root->left->right = Newnode(5);
	root->left->left = Newnode(4);
}