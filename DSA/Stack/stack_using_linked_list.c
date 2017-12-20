//stack implementation using the linked list
// author:- Jatin Kumar
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*head=NULL;  // don't forget to make it null.....
void display();
void push();
void pop();
int main()
{	
	int choice,flag=0;
	start:
	printf("\n***********************Menu**************************\n");
	printf("1.)display the stack\n");
	printf("2.)push an element into the stack\n");
	printf("3.)pop an element from the stack\n");
	printf("4.)exit\n");
	printf("\n\nenter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:display();
				break;
		case 2:push();
				break;
		case 3:pop();
				break;
		case 4:flag=1;
				break;
		default:printf("\n\nPlease enter a valid choice\n\n");
				goto start;
	}
	if(flag==0)
	{
		goto start;
	}
}
void push()
{
	struct node *ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nstack overflow is occured\n");
		return;
	}
	else
	{
		printf("enter the element that you want to push into the stack=");
		scanf("%d",&ptr->data);
		ptr->link=head;   //this is the main thing that you have to remember
		head=ptr;         // so nice it is....
	}
}
void pop()
{
	if(head==NULL)
	{
		printf("\n\nstack underflow is occured\n\n");
		return;
	}
	else
	{
		struct node *ptr;
		ptr=head;
		head=ptr->link;
		free(ptr);
	}
}
void display()
{
	struct node *ptr=head;
	if(ptr==NULL)
	{
		printf("\n|EMPTY|\n");
	}
	else
	{
		while(ptr)
		{	
			printf("----\n");
			printf("|%d|\n",ptr->data);
			printf("----\n");
			ptr=ptr->link;
		}
	}
}
