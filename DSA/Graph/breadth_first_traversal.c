// implementing breadth first traversal in graphs
// Author: Kumar Jatin
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define maxNode 4
struct node
{
	int vertex;
	struct node *next;
};
struct node *list[maxNode];
void addNode(int,int);
void BFS(int);
int visited[maxNode]={0};
int queue[maxNode],rear=-1,front=-1;
void enqueue(int);
int dequeue();
int main()
{
	int i;
	for(i=0;i<maxNode;i++)
	{
		list[i]=NULL;
	}
/*
		graph used is given by:
		0------------------1
		|                  |
		|		   |
		|		   |
		|		   |
		|		   |
		3------------------2
		
*/
	addNode(0,1);
	addNode(0,3);
	addNode(1,0);
	addNode(1,2);
	addNode(2,1);
	addNode(2,3);
	addNode(3,0);
	addNode(3,2);
	BFS(0);
	printf("\n");
}
void addNode(int s,int d)
{
	struct node *temp,*ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->vertex=d;
	ptr->next=NULL;
	if(list[s]==NULL)
	{
		list[s]=ptr;
	}
	else
	{
		temp=list[s];
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=ptr;
	}
}
void BFS(int u)
{	
	
	struct node *temp;
	// the vertex from which we are starting is visited
	visited[u]=1;
	printf("BFS=%d\t",u);
	int w;
	bool value=true;
	while(value)
	{	
		// to get its neighbours we will take the help of adjacency list
		// for any node u we shall find its all neighbours w
		temp=list[u];
		while(temp)
		{
			w=temp->vertex;
			if(visited[w]==0)
			{	
				// w is not visited and hence not yet explored
				// so put it in the queue
				enqueue(w);
				// now it is visited
				visited[w]=1;
				printf("%d\t",w);
			}
			temp=temp->next;
		}
		// if queue is empty then return
		if(rear==front)
		{	
			// queue is empty and that means we have explored all vertices
			value=false;
			return;
		}
		else
		{
			u=dequeue();
		}
	}
}
void enqueue(int x)
{	
	// not fully implemented but sufficient fot this algo
	rear=rear+1;
	queue[rear]=x;
}
int dequeue()
{	
	// not fully implemented but sufficient fot this algo
	front=front+1;
	return (queue[front]);
}
