//author @ Ayush Aggarwal
// Recursive solution
//check whether two trees are identical or not
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left,*right;
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
	if(!root1 and !root2)
		return true;
	if(!root1 or !root2)
		return false;
	if((root1->data==root2->data) and (check_identical(root1->left,root2->left)) and (check_identical(root1->right,root2->right)))
		return true;
	else 
		return false;

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
