#include <iostream>
#include<stdio.h>
using namespace std;
void count(int x);
int main() {
	// your code goes here
	 int t,a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&a);
		count(a);
	}
	return 0;
}
void count(int x){
int cont=0;
for(int j=5;j<=x;j*=5){
cont+=x/j;
}
cout<<cont<<endl;
}
