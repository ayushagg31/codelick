//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node *insert(struct node* root,int data)
{
	if(root == NULL)
		return(newNode(data));
	if(data > root->data)
		root->right = insert(root->right,data);
	else
		root->left = insert(root->left,data);
	return root;
}

void search(struct node *root,int aim)
{
	if(root==NULL)
	{
		cout<<"Doesn't exist"<<endl;
		return;
	}
	if(root->data > aim)
		search(root->left,aim);
	if(root->data < aim)
		search(root->right,aim);
	if(root->data == aim)
	{
		cout<<"Node exist"<<endl;
		return;
	}

}
int main()
{

	struct node *root = NULL;
	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    search(root,90);
	return 0;	
}