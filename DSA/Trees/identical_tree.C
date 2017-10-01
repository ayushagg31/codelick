//author @ Ayush Aggarwal
// iterative solution
// check whether two trees are identical or not
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int val)
{
	struct node *temp = new node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
} 
bool check_identical(struct node *root1, struct node *root2)
{
	queue <node *> q1;
	queue <node *> q2;
	if(root1 == NULL and root2 == NULL)
		return true;
	if(root1==NULL)
		return false;
	if(root2==NULL)
		return false;
	q1.push(root1);
	q2.push(root2);
	while(!q1.empty() and !q2.empty())
	{
		struct node *temp1 = q1.front();
		q1.pop();
		struct node *temp2 = q2.front();
		q2.pop();
		if(temp1->data != temp2->data)
			return false;
		if(temp1->left and temp2->left)
		{
			q1.push(temp1->left);
			q2.push(temp2->left);
		}
		else if(temp1->left or temp2->left)
			return false;
		if(temp1->right and temp2->right)
		{
			q1.push(temp1->right);
			q2.push(temp2->right);
		}
		else if(temp1->right or temp2->right)
			return false;
	}
	return true;
}

int main()
{
	struct node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
 
    struct node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    if(check_identical(root1,root2))
    	cout<<" Both trees are identical";
    else
    	cout<<" Trees are not identical";
 
	return 0;
}