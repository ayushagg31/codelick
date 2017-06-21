#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

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
int main(){
stk s;
init(&s);
char input[100];
cin>>input;
int len = strlen(input);
//cout<<len;
for(int i=0;i<len;i++)
{
char sample = input[i];
if(isalnum(sample))
{	//cout<<"HI";
	int chutspaa = sample-48;
	push(&s,chutspaa);
}
else
{
int k1 = pop(&s);
int k2 = pop(&s);
int res=0;
if(sample =='*')
res = k2*k1;
else if(sample =='-')
res = k2-k1;
else if(sample =='/')
res = k2/k1;
else if(sample =='+')
res = k2+k1;
push(&s,res);
}
}
cout<<pop(&s);
return 0;
}
