// Author:- Jatin Kumar
// Prim's Algorithm using min heap
// time complexity= O(E logV);
// based on greedy approach
// this implementation is useful in case of sparse graphs

#include<bits/stdc++.h>
using namespace std;
#define infinity INT_MAX
struct node
{
	int key;
	int present;
	int parent;
};
void buildminheap();
void minheapify(int);
int prims(int*);
int extractmin();
int n,heapsize,minCost=0;
struct node *array[100];
int main()
{
	cout<<"enter the no. of vertices=";
	cin>>n;
	heapsize=n;
	int costMatrix[n][n];
	cout<<"enter cost matrix:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>costMatrix[i][j];
			if((i!=j) && costMatrix[i][j]==0)
				costMatrix[i][j]=infinity;
		}
	}
	int result=prims(&costMatrix[0][0]);
	cout<<"\ncost of minimum cost spanning tree is "<<result<<"\n";
}
int prims(int *costMatrix)
{
	// initialize array of nodes
	for(int i=0;i<n;i++)
	{
		array[i]=(struct node*)malloc(sizeof(struct node));
		array[i]->key=infinity;
		array[i]->parent=-1;
		array[i]->present=i;
	}
	// start from any vertex and let it be 0
	array[0]->key=0;
	// now make a min heap of these nodes
	buildminheap();
	int flag,j;
	while(heapsize!=0)
	{
		int u=extractmin();
		// find all adjacents of u
		// it will be row u elements
		for(int i=0;i<n;i++)
		{	
			flag=0;
			int v=*(costMatrix+u*n+i);
			if(v==0 || v==infinity)
			{
				continue;
			}
			else
			{	
				// u is adjacent to i
				// check if i is present in heap or not
				for(j=0;j<heapsize;j++)
				{
					if(array[j]->present==i)
					{	
						
						flag=1;
						break;
					}
				}
				if(flag==0)
				{	
					continue;
				}
				else
				{	
					// we have index j that points to location where i is present
					if(array[j]->key>*(costMatrix+u*n+i))
					{
						array[j]->key=*(costMatrix+u*n+i);
						array[j]->parent=i;
					}
				}
			}
		}
		buildminheap();

	}
	return minCost;
}
void buildminheap()
{
	for(int i=(heapsize/2)-1;i>=0;i--)
	{
		minheapify(i);
	}
}
void minheapify(int root)
{
	int left=2*root+1;
	int right=2*root+2;
	int smallest;
	if(left<heapsize)
	{
		if(array[root]->key>array[left]->key)
		{
			smallest=left;
		}
		else
		{
			smallest=root;
		}
	}	
	else
	{
		return;
	}
	if(right<heapsize)
	{
		if(array[right]->key<array[smallest]->key)
		{
			smallest=right;
		}
	}
	if(smallest!=root)
	{
		struct node *t=array[root];
		array[root]=array[smallest];
		array[smallest]=t;
		minheapify(smallest);
	}
}
int extractmin()
{
	struct node *temp=array[0];
	array[0]=array[heapsize-1];
	heapsize--;
	minheapify(0);
	minCost=minCost+temp->key;
	return temp->present;
}
