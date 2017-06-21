#include<stdlib.h>
#include<stdio.h>

struct node {
int data;
struct node *next;
};
void beforelastnode(struct node **head_ref)
{
	if(*head_ref ==NULL)
		return;
	if(*head_ref->next==NULL)
		return;
	struct node *S = *head_ref;
	struct node *S1 = (struct node *)malloc(sizeof(struct node));
	while(S!=NULL)
	{	
		S1 = S;
		S = S->next;
	}
}
void printlist(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d\n",n->data);
		n = n->next;
	}
}
int main()
{
struct node *head ,*second ,*third ;
head = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node));
third = (struct node*)malloc(sizeof(struct node));
head->data = 1;
head->next = second;

second->data  = 2;
second->next = third;

third->data = 3;
third->next = NULL;
printlist(head);

return 0;
}
