#include <bits/stdc++.h>
using namespace std;

#define ALPHA_SIZE 26

struct Trie
{
	struct Trie *child[ALPHA_SIZE];
	bool is_end;
};

struct Trie *getNode()
{
	struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));
	if(node)
	{
		node->is_end = false;
		for(int i=0;i<ALPHA_SIZE;i++)
			node->child[i] = NULL;
	}
	return node;
}
void insert(struct Trie *root,string str)
{	
	struct Trie *temp = root;
	int len = str.length();
	for(int i=0;i<len;i++)
	{
		int index = (int)str[i] - (int)'a';
		if(!temp->child[index])
			temp->child[index] = getNode();
		temp = temp->child[index];
	}
	temp->is_end = true;
}
bool search(struct Trie *root,string str)
{
	struct Trie *temp = root;
	int len = str.length();
	for(int i=0;i<len;i++)
	{
		int index = (int)str[i] - (int)'a';
		if(!temp->child[index])
			return false;
		temp = temp->child[index];
	}
	return(temp!=NULL and temp->is_end);
}
bool is_free_node(struct Trie *root)
{
	int count=0;
	for(int i=0;i<ALPHA_SIZE;i++)
	{
		if(root->child[i])
			return false;
	}
	return true;
}
/*bool remove(struct Trie *root,string str,int level,int len);
{
	if(root)
	{
		if(level == len)
		{
			if(root->is_end)
			{
				root->is_end = false;
				if(is_free_node(root))
					return true;
				return false;
			}
		}
		else
		{
			int index = (int)str[level] - (int)'a';
			if(remove(root->child[index],str,level+1,len))
			{
				free(root->child[index]);
				root->child[index] = NULL;
				if(!root->is_end)
				{

				}	
			}
		}
	}
	return false;
	
}*/
int main()
{
	struct Trie *root = getNode();
	string str[10] = {"Ayush","there","a","answer"};
	for(int i=0;i<5;i++)
		insert(root,str[i]);
	string stress;
	cin>>stress;
	bool res = search(root,stress);
	if(res)
		cout<<"String Found"<<endl;
	else
		cout<<"String NOT found"<<endl;
	/*cout<<"Enter key to delete\n";
	cin>>stress;
	remove(root,stress,0,len);*/

	return 0;
}