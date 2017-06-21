#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue
{
	int front,rear,size;
	int capacity;
	int *array;
};

struct ArrayQueue *CreateQueue(int capacity)
{
	struct ArrayQueue *Q  = (struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));

	
		Q->front = -1;
		Q->rear = -1;
		Q->size = 0;
		Q->capacity = capacity;
		Q->array = (int*)malloc(capacity*sizeof(int));
		return(Q);
	
}

bool isFullQueue(struct ArrayQueue *Q)
{
	if(Q->size == Q->capacity)
		return true;
	else
		return false;
}

bool isEmptyQueue(struct ArrayQueue *Q)
{
	if(Q->size == 0)
		return true;
	else
		return false;
}

void enqueue(struct ArrayQueue *Q , int item)
{
	if(isFullQueue(Q))
		{
			printf("Queue is already full");
			return ;
		}
	if(Q->front == -1)
		Q->front = 0;
	Q->rear = (Q->rear + 1)%(Q->capacity);
	Q->array[Q->rear] = item;
	Q->size +=1;
}

int dequeue(struct ArrayQueue *Q)
{
	int data = -1;
	if(isEmptyQueue(Q))
	{
		printf("Queue is empty");
		return data;
	}

	data = Q->array[Q->front];
	Q->front = (Q->front+1)%(Q->capacity);
	Q->size -=1;
	return data;
}


int main()
{
	struct ArrayQueue* queue = CreateQueue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n", dequeue(queue));
}