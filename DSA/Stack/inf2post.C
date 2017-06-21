#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
using namespace std;
struct node
{
	char data;
	struct node *next;
};

void stack_push(struct node **head_ref,char new_data)
{
	struct node *top = (struct node *)malloc(sizeof(struct node));
	top->data = new_data;	
	top->next = *head_ref;
	*head_ref = top;
	//cout<<new_data<<" Has been inserted!!!"<<endl;
}
char stack_pop(struct node **head_ref)
{
	struct node *temp = *head_ref;
	*head_ref = temp->next;
	return temp->data;
//	free(temp);
}
int precedence(char ch='!')
{  if(ch == '$')
	return -1;
	if(ch == '(')
	return 0;
	if(ch=='+'||ch=='-')
		return 1;
	if(ch =='*' ||ch =='/')
		return 2;
}


void print_stack(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d\t",n->data);
		n = n->next;
	}	
}
int main()
{
	struct node *top = NULL;
	char input[100],k;
	cin>>input;
	stack_push(&top,'$');
	for(int i=0;i<(strlen(input));i++)
	{
	if(isalnum(input[i]))
	cout<<input[i];
	
	else																//(a + b)
	{
		char sample = input[i];
		if(sample =='(')
			stack_push(&top,sample);
		else if(sample == ')')
			{
			while(top->data!='(')
			{
				k = stack_pop(&top);
				if(k==')'||k=='('){	}
				else
				cout<<k;
			}
			k = stack_pop(&top);
			if(k==')'||k=='('){	}
			else
			cout<<k;
			}
			else{				//cout<<"HI";
			while((precedence(sample)<=precedence(top->data))&&(top!=NULL))
			{
				//cout<<"HI";
				k = stack_pop(&top);
				if(k==')'||k=='('){	}
				else
				cout<<k;
			}
			stack_push(&top,sample);
			}}
	}
	while(top->next!=NULL)
	{
		k = stack_pop(&top);
		if(k==')'||k=='('){	}
				else
				cout<<k;
	}
	}
