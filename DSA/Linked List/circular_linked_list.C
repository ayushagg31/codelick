#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct list
{
	int data;
	struct list *next;
};
void display(struct list *head_ref)
{
	struct list *node = head_ref;
	cout<<node->data;
	node = node->next;
	cout<<" ";
	while(node!=head_ref)
	{
		cout<<node->data <<" ";
		node = node->next;
	}
}
void adding_head(struct list **head_ref,int data)
{
	struct list *node = (struct list *)malloc(sizeof(struct list));
	node->data = data;
	node->next = *head_ref;
	if(*head_ref !=NULL)
	{
		struct list *temp = *head_ref;
		while(temp->next!=*head_ref)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
	else
	{
		node->next = node;
	}	
	*head_ref = node;
}

void adding_end(struct list **head_ref,int data)
{
	struct list *node = (struct list *)malloc(sizeof(struct list));
	node->data = data;
	if(*head_ref == NULL)
	{
		*head_ref = node;
	}
	else
	{
		struct list *temp = *head_ref;
		while(temp->next!=*head_ref)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
	node->next = *head_ref;
	//free(temp);
}
void display_order(struct list **head_ref)
{
	int count=1;
	struct list *even = NULL;
	struct list *odd = NULL;
	struct list *temp = *head_ref;
	adding_end(&odd,temp->data);
	temp = temp->next;
	count = count+1;
	while(temp!=*head_ref)
	{
		if(count%2!=0)
			adding_end(&odd,temp->data);
		else if(count%2==0)
			adding_end(&even,temp->data);
		temp = temp->next;
		count++;
	}
	cout<<"\nEven list\n";
	display(even);
	cout<<"\nOdd list\n";
	display(odd);
}
void delete_head(struct list **head_ref)
{
	struct list *temp = *head_ref;
	int save = temp->data;
	cout<<"Item deleted is "<<save<<endl;
	while(temp->next!=*head_ref)
	{
		temp = temp->next;
	}
	struct list *node = *head_ref;
	node = node->next;
	*head_ref = node;
	temp->next = *head_ref;
	//free(temp);
}
void delete_end(struct list **head_ref)
{
	struct list *temp = *head_ref;
	while(temp->next->next!=*head_ref)
	{
		temp = temp->next;
	}
	int save = temp->next->data;
	cout<<"Item deleted is "<<save<<endl;
	temp->next = *head_ref;
	//free(temp);
}


int main()
{
	struct list *head = NULL;
	//head->data = 15;
	//head->next = head;
	//adding_head(&head,15);
	adding_end(&head,25);
	adding_head(&head,5);
	adding_end(&head,7);
	adding_head(&head,13);
	adding_end(&head,19);
	display(head);
	//delete_head(&head);
	//display(head);
	//delete_end(&head);
	//display(&head);
	/*delete_head(&head);
	display(&head);
	delete_end(&head);*/
	//display(head);
	display_order(&head);
}