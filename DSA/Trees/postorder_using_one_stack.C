//author @ Ayush Aggarwal
//Postorder traversal of tree using one stack
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

struct node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void postorder(node *root)
{
    node *curr = root;
    stack <node*> s;
    while(!s.empty() or curr!=NULL)
    {
        if(curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            node *temp = s.top()->right;
            if(temp == NULL)
            {
                temp = s.top();
                cout<<temp->data<<" ";
                s.pop();
                while(!s.empty() and temp==s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    cout<<temp->data<<" ";
                }
            }
            else
                curr = temp;
        }
    }
}

int main()
{
    struct node *root = newNode(10);
    root->left = newNode(-10);
    root->right = newNode(30);
    root->left->right = newNode(8);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(9);
    root->right->left = newNode(25);
    root->right->right = newNode(60);
    root->right->right->right = newNode(78);
    root->right->left->right = newNode(28);
    postorder(root);
	return 0;
}

