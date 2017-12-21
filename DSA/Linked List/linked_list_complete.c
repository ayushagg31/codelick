// program to implement linked list
// author:- Jatin Kumar
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*head;
void create();
void display(struct node*);
void insertbeg();
void insertend();
void insertaftervalue();
void deletebeg();
void deleteend();
void deletevalue();
void search();
void largest();
void smallest();
void reverseorder(struct node*);
void insertbefore();
//struct node* reverse(struct node*);
void reverse(struct node*,struct node*);
int main()
{	int choice,flag=0;
	start:
	printf("\n****************************menu**************************\n");
	printf("1.)create the linked list\n");
	printf("2.)display the linked list\n");
	printf("3.)insert element at the beginning\n");
	printf("4.)insert element at the end\n");
	printf("5.)insert element after particular value\n");
	printf("6.)Insert element before an element\n");
	printf("7.)delete the element from the beginning\n");
	printf("8.)delete the element from the end\n");
	printf("9.)delete the particular node\n");
	printf("10.)search an element\n");
	printf("11.)find the largest element in the list\n");
	printf("12.)find the smallest element in the linked list\n");
	printf("13.)print the linked list in the reversed order\n");
	printf("14,)reverse the linked list entirely\n");
	printf("15.)exit\n");
	printf("enter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:create();
				break;
		case 2:display(head);
				break;
		case 3:insertbeg();
				break;
		case 4:insertend();
				break;
		case 5:insertaftervalue();
				break;
		case 6:insertbefore();
				break;
		case 7:deletebeg();
				break;
		case 8:deleteend();
				break;
		case 9:deletevalue();
				break;
		case 10:search();
				break;
		case 11:largest();
				break;
		case 12:smallest();
				break;
		case 13:reverseorder(head);
				break;
		case 14: reverse(NULL,head);
				break;
		case 15: flag=1;
				break;
		default:printf("please enter the CORRECT CHOICE");
				goto start;
	}
	if(flag==0)
	{
		goto start;
	}
	printf("\n\nLINKED LIST EXECUTED SUCCESSFULLY...!!!\n");
}
void create()
{	
	int choice;
	struct node *ptr,*cpt;
	ptr=malloc(sizeof(struct node));
	head=ptr;
	printf("enter the data=");
	scanf("%d",&ptr->data);
	label:
	printf("do you want to add more nodes(0/1):");
	scanf("%d",&choice);
	if(choice==1)
	{
		cpt=malloc(sizeof(struct node));
		printf("enter the data=");
		scanf("%d",&cpt->data);
		ptr->link=cpt;
		ptr=cpt;
		goto label;
	}
	else if(choice==0)
	ptr->link=NULL;
	else
	{
		printf("\nplease enter the correct choice\n");
		goto label;
	}
}
void display(struct node *p)
{
	if(p)
	{
		printf("|%d|->",p->data);
		display(p->link);
	}
	if(p==NULL)
	printf("NULL\n");
}
void insertbeg()
{
	struct node *new;
	new=(struct node*)(malloc(sizeof(struct node)));
	if(new==NULL)
	{
		printf("\noverflow is occured...!!!\n");
		return;
	}
	else
	{
		printf("enter the data=");
		scanf("%d",&new->data);
		new->link=head;
		head=new;
	}
}
void insertend()
{
	struct node *t,*new;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("\noverflow is occured...!!!\n");
		return;
	}
	else
	{
		printf("enter the data=");
		scanf("%d",&new->data);
		t=head;
		while(t->link!=NULL)
		{
			t=t->link;
		}
		new->link=NULL;
		t->link=new;
	}
}
void insertaftervalue()
{	
	int value;
	struct node *ptr=head,*temp;
	temp=malloc(sizeof(struct node));
	printf("enter the value after which you want to insert the node=");
	scanf("%d",&value);
	while(ptr)
	{	
		if(ptr->data==value)
		{
			printf("enter the value that you want to insert=");
			scanf("%d",&temp->data); 
			temp->link=ptr->link;
			ptr->link=temp;	
			return;	
		}
		ptr=ptr->link; 
	}
	printf("\nvalue not found in the linked list plese enter a correct value....!!!!\n");
}
void deletebeg()
{
	struct node *t;
	t=head;
	if(head==NULL)
	{
		printf("list is empty, nothing to delete...!!\n");
		return;
	}
	else if(head->link==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	else
	{
		head=head->link;
		free(t);
	}
}
void deleteend()
{
	struct node *ptr=head;
	if(ptr==NULL)
	{
		printf("\n the list is empty....nothing to delete\n");
		return;
	}
	else if(!ptr->link)
	{	
		free(ptr);
		head=NULL;
		return;
	}
	else
	{
		while(ptr->link->link)
		{
			ptr=ptr->link;               
		}
		free(ptr->link);
		ptr->link=NULL;
	}
}
void deletevalue()
{
	int value,check;
	struct node *ptr=head,*temp; 
	printf("enter the value that you want to delete=");
	scanf("%d",&value);
	if(!ptr)
	{
		printf("\nlist is empty....and there is nothing to delete\n");
	}
	else if(ptr->data==value)
	{
		head=ptr->link;
		free(ptr);
		return;
	}
	else
	{
		while(ptr->link->data!=value)
		{
			ptr=ptr->link;
		}
		temp=ptr->link;
		ptr->link=temp->link;
		free(temp);
	}
}
void  search(int j)
{	
	int value,flag2=0;
	printf("enter the value that you want to search=");
	scanf("%d",&value);
	struct node *ptr=head;
	int flag=0;
	while(ptr)
	{
		if(ptr->data==value)
		{
			flag2=1;
		}
		ptr=ptr->link;
	}
	if(flag2)
	{
		printf("value is present in the linked list\n");
	}
	else
	{
		printf("value is not present in the linked list\n");
	}
}
void largest()
{
	int max;
	struct node *t=head;
	max=t->data;
	t=t->link;
	while(t)
	{
		if(max<t->data)
		{
			max=t->data;
		}
		t=t->link;
	}
	printf("largest value is %d\n",max);
}
void smallest()
{
	int min;
	struct node *t=head;
	min=t->data;
	t=t->link;
	while(t)
	{
		if(min>t->data)
		{
			min=t->data;
		}
		t=t->link;
	}
	printf("smallest value is %d\n",min);
}
void reverseorder(struct node *temp)
{
	if(temp)
	{
		reverseorder(temp->link);
		printf("->|%d|",temp->data);
	}
	else
	{
		printf("NULL");
	}
}
/*struct node* reverse(struct node *cur)
{
	struct node *pre=NULL,*nextnode=NULL;       this is the iterative version of reversing a linked list
	while(cur)
	{
		nextnode=cur->link;
		cur->link=pre;
		pre=cur;
		cur=nextnode;
	}
	return pre;
}*/
void reverse(struct node *pre,struct node *cur)
{
	if(cur)
	{
		reverse(cur,cur->link);
		cur->link=pre;				// this is the recursive version to reverse a linked list
	}
	else
	{
		head=pre;
	}
}
void insertbefore()
{
	int value,data,check;
	struct node *ptr=head,*temp;
	printf("enter the value before which you want to insert the node=");
	scanf("%d",&value);
	temp=malloc(sizeof(struct node));
	if(ptr->data==value)
	{
		temp->link=ptr;
		head=temp;
		return;
	}
	else
	{
		while(ptr->data!=value)
		{
			ptr=ptr->link;
		}
		temp->link=ptr->link;
		ptr->link=temp;
		temp->data=ptr->data;
		printf("enter the data=");
		scanf("%d",&ptr->data);
	}
}
