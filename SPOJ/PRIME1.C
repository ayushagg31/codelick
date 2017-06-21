#include <iostream>
#include<stdio.h>
using namespace std;
void prime(long long int x);
int main() {
	// your code goes here
	int t;
	long long a,b;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	scanf("%lld%lld",&a,&b);
	for(int x=a;x<=b;x++)
	prime(x);
	printf("\n");
	}
	return 0;
}
void prime(long long int a){
	
	int count = 0;
	int q = a/2;
	if(a!=1){
	for(int i=2;i<=q;i++)
	{
	if(a%i == 0)
	{	count = 1;
		break;
	}
	}
	if(count == 0){
	printf("%lld",a);
	printf("\n");}
	}}
	
	

