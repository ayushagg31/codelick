//author @ Ayush Aggarwal
//iterative method to calculate the height of tree
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

int height_binary_tree(struct node *root)
{
	int count = 0;
	if(root == NULL)
		return 0;
	queue <node *> q;
	q.push(root);
	while(true)
	{
		int nodeCount = q.size();
		if(nodeCount == 0)
			return count;
		count++;
		while(nodeCount > 0)
		{
			node *temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			nodeCount--;
		}
	}
	return count;
}

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<< height_binary_tree(root);

	return 0;
}