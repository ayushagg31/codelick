// implementing a queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void display();
int count=0;
int main()
{	
	int choice,flag=0;
	start:
	printf("\n*******************MENU***********************\n");
	printf("1.)enqueue\n");
	printf("2.)dequeue\n");
	printf("3.)display\n");
	printf("4.)exit\n");
	printf("enter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:enqueue();
				break;
		case 2:dequeue();
				break;
		case 3:display();
				break;
		case 4:flag=1;
				break;
		default:printf("\nplease enter a correct choice\n");
	}
	if(flag==0)
	{
		goto start;
	}
}
void enqueue()
{
	struct node *ptr;
	count++;
	ptr=malloc(sizeof(struct node));	
	if(!ptr)
	{
		printf("\noverflow is detected\n");
		return;
	}
	else if(count==1)
	{
		printf("enter the value=");
		scanf("%d",&ptr->data);
		rear=ptr;
		front=rear;
	}
	else
	{
		printf("enter the value=");
		scanf("%d",&ptr->data);
		rear->link=ptr;
		rear=ptr;
		rear->link=NULL;
	}
}
void dequeue()
{
	struct node *ptr=front;
	if(!ptr)
	{
		printf("\nlist is empty and there is underflow condition\n");
		return;
	}
	front=ptr->link;
	free(ptr);
}
void display()
{
	struct node *ptr=front;
	if(!ptr)
	{
		printf("\nlist is empty and there is nothing to print\n");
		return;
	}
	while(ptr!=rear)
	{
		printf(" |%d| ",ptr->data);
		ptr=ptr->link;
	}
	printf(" |%d| ",ptr->data);
}
