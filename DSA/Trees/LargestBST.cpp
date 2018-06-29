/* author @ Ayush Aggarwal
Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of whole tree.
*/
# include<bits/stdc++.h>
using namespace std;

int maa = INT_MIN;
struct node
{
	int val;
	node *left;
	node *right;
};

struct retype
{
	bool isBst;
	int size_Bst;
	int max_left;
	int min_right;
};

retype check(node *root)
{
	retype tmp;
	if(root==NULL)
	{
	tmp.isBst = true;
	tmp.size_Bst = 0;
	tmp.max_left=INT_MIN;
	tmp.min_right=INT_MAX;
		return tmp;
	}
	if(root->left==NULL and root->right==NULL)
	{
	// that means the root node represents leaf
	// a leaf is always a binary search tree of size 1
	tmp.isBst = true;
	tmp.size_Bst = 1;
	maa = max(1,maa);
	tmp.max_left = root->val;
	tmp.min_right = root->val;
		return tmp;
	}
	retype tmp_left = check(root->left);
	retype tmp_right = check(root->right);
	
	if(tmp_left.isBst and tmp_right.isBst and root->val > tmp_left.max_left and root->val < tmp_right.min_right)
	{
		tmp.isBst = true;
		tmp.size_Bst = tmp_left.size_Bst + tmp_right.size_Bst + 1;
		maa = max(tmp.size_Bst,maa);
		tmp.max_left = tmp_right.max_left;
		tmp.min_right = tmp_left.min_right;
		return tmp;
	}
	else
	{
		tmp.isBst = false;
		tmp.size_Bst = 0;
		tmp.max_left = 0;
		tmp.min_right=0;
		return tmp;
	}
}

node *newNode(int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->val = data;
	tmp->left=NULL;
	tmp->right = NULL;
	return tmp;
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
    cout<<node->val<<endl;
	printInorder(node->right);
}

int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
	printInorder(root);
retype result = check(root);
cout<<maa<<endl;
	
}
