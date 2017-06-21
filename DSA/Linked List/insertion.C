#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
};
void push(struct node **head_ref,int new_data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
/*void insertAfter(struct node *prev_node,int nw_data)
{
	struct node *new_node  = (struct node *)malloc(sizeof(struct node));
	new_node->data = nw_data;
	if (prev_node == NULL)
		return;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	
}
*/
void sorting(struct node **head_ref)
{
	if(*head_ref == NULL)
	return;
	struct node *temp = *head_ref;
	if(temp->next == NULL)
	return;
	while(temp!=NULL)
	{
		struct node *temp1 = temp->next;
		while(temp1!=NULL)
		{
//		struct node *temp2 = temp1->next;
			if((temp1->data)<(temp->data))
			{
				int num = temp1->data;
				temp1->data = temp->data;
				temp->data = num;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}
void append(struct node **head_ref,int new_data)
{
	
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = new_data;
	if(*head_ref == NULL)
		{	
			*head_ref = new_node;	
			return;
		}
	struct node *last = *head_ref;
	while(last->next!=NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	return;
}
void printlist(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	}
}

int main()
{
	struct node *head = NULL;
	int var,new_data;
	cout<<"Enter 1 for PUSH  2 for SORTING and 3 for PUSH_END and 4 to PRINT and 5 to exit"<<endl;
	do{
		cin>>var;
		switch(var){
			case 1:
					cout<<"Enter data to be inserted"<<endl;
					cin>>new_data;
					push(&head,new_data);
					break;
			/*case 2:
					cout<<"Enter data to be inserted"<<endl;
					cin>>new_data;
					insertAfter(head->next,new_data);
					break;*/
			case 2:
					cout<<"Here our sorting starts"<<endl;
					sorting(&head);
					cout<<endl;
					break;
			case 3:
					cout<<"Enter data to be inserted"<<endl;
					cin>>new_data;
					append(&head,new_data);
					break;
			case 4:
					printlist(head);
					cout<<endl;
					break;
			default:
					cout<<"Enter valid case "<<endl;
					break;
		}
	}while(true);
	
}
