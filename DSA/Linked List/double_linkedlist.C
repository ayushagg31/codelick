#include<stdlib.h>
#include<stdio.h>

struct node
{
	int info;
	struct node *prev,*next;
};

void insert_At_start(struct node **head_ref,int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->info = data;
	n->prev = NULL;
	if(*head_ref == NULL)
		*head_ref = n;
	else
	{
		(*head_ref)->prev = n;
		n->next = *head_ref;
		*head_ref = n;
	}
}

void delete_node(struct node **head_ref)
{
	if(*head_ref == NULL)
	{
	printf("list is empty");
	printf("\n");
	}
	else 	
	{
		*head_ref = (*head_ref)->next;
		(*head_ref)->prev = NULL;
	}
}

void print_list(struct node *n)
{
	if(n==NULL)
	printf("list is empty");
	else
	{
	while(n!=NULL)
	{
		printf("%d ",n->info);
		n = n->next;
	}
	}
}
int main()
{
	struct node *start = NULL;
	int data;
	insert_At_start(&start,10);
	insert_At_start(&start,20);
	insert_At_start(&start,25);
	print_list(start);
	delete_node(&start);
	print_list(start);
	
}
