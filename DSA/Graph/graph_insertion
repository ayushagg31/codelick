// implementing graph with the help of adjacancy list
// Author: Kumar Jatin

#include<stdio.h>
#include<stdlib.h>
#define maxNode 4
struct node
{
	int vertex;
	struct node *next;
};
struct node *list[maxNode];
void addNode(int,int);
void printList();
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
		|				           |
		|				           |
		|				           |
		|				           |
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
	printList();
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
void printList()
{
	int i;
	struct node *temp;
	for(i=0;i<maxNode;i++)
	{
		printf("for node %d:head->",i);
		temp=list[i];
		while(temp->next)
		{
			printf("%d->",temp->vertex);
			temp=temp->next;
		}
		printf("%d\n",temp->vertex);
	}
}
