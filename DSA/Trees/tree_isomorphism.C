//author @ Ayush Aggarwal
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


bool isIsomorphic(node *root1, node* root2)
{
    if(root1==NULL and root2==NULL)
        return true;
    if(root1==NULL or root2==NULL)
        return false;
    if(root1->data !=root2->data)
        return false;
    return((isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right)) or 
        (isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left)));
}

int main()
{
	struct node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);

    struct node *root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->left->right = newNode(6);
    root2->right->left = newNode(4);
    root2->right->right = newNode(5);

    if(isIsomorphic(root1,root2))
        cout<<"Both trees are isomorphic";
    else
        cout<<"Trees are not isomorphic";
	return 0;
}