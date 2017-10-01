//author @ Ayush Aggarwal
// recursive one
// height of tree = number of nodes on longest path from root to deepest node **<<<**
// height of tree = number of edges on longest path from root to deepest node
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int calc_height(struct node *root)
{
    if(root == NULL)
        return 0;
    int left_ht = calc_height(root->left);
    int right_ht = calc_height(root->right);
    return 1 + max(left_ht ,right_ht);
}

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<calc_height(root);
	return 0;
}