#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;
int i=0;
struct stk{
int top;
int arr[10];
};
void push(struct stk *s, int data){
s->arr[++s->top]= data;
}
int pop(struct stk *s){
int x= s->arr[s->top--];
return x;
}
void init(struct stk* s){
s->top= -1;
}
void recursive(struct stk *s)
{
	if(i!=s->top/2)
	{
	swap(s->arr[i],s->arr[s->top-i]);
	i++;
	recursive(s);
	}
}

int main(){
stk s;
init(&s);
push(&s,17);
push(&s,15);
push(&s,13);
push(&s,12);
push(&s,10);
recursive(&s);
while(s.top!=-1)
{
	cout<<pop(&s)<<" ";
}
}
