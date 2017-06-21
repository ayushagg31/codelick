#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct stk1
{
	int data;
	struct stk1 *next;
};

struct queue
{
	struct stk1 *stack1;
	struct stk1 *stack2;
};

//For stack operations like push and pop
void stack_push(struct stk1 **head_ref,int data)
{
	struct stk1 *new_node = (struct stk1*)malloc(sizeof(struct stk1));
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

int stack_pop(struct stk1 **head_ref)
{	
	if(*head_ref == NULL)
	{
		cout<<"stack is empty";
	}
	else{
	struct stk1 *del_node = *head_ref;
	int saver = del_node->data;
	//cout<<saver<<" ";
	*head_ref = del_node->next;
	return saver;
}
}

void enqueue(struct queue *q,int data)
{
	stack_push(&q->stack1,data);
}

void dequeue(struct queue *q)
{
	if(q->stack1 ==NULL && q->stack2 == NULL)
		{
			cout<<"Stack is empty\n";
			return;
		}
	if(q->stack2 ==NULL)
	{
		while(q->stack1 !=NULL)
		{
			int ret = stack_pop(&q->stack1);
			stack_push(&q->stack2,ret);
		}
	}
	int out = stack_pop(&q->stack2);
	cout<<"dequeue element is "<<out<<"\n";
}

void display(struct stk1 *top1, struct stk1 *top2)
{
    while (top1 != NULL) {

    printf("%d\n", top1->data);

    top1 = top1->next;

}

	while (top2 != NULL) {

    printf("%d\n", top2->data);

    top2 = top2->next;

}
}

int main()
{
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	char ch = 'y';
	int a,f;
    while (ch == 'y'||ch == 'Y') {

    printf("enter ur choice\n1.add to queue\n2.remove from queue\n3.display\n4.exit\n");

    scanf("%d", &f);

    switch(f) {

        case 1 : printf("enter the element to be added to queue\n");

                 scanf("%d", &a);

                 enqueue(q, a);

                 break;

        case 2 : dequeue(q);

                 break;

        case 3 : display(q->stack1, q->stack2);

                 break;

        case 4 : exit(1);

                 break;

        default : printf("invalid\n");

                  break;

    }

}
return 0;
}