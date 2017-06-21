#include<iostream>
using namespace std;
void you_can_do_it(int a);
int main()
{
	int t,a;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a;
		you_can_do_it(a);
	}
}
void you_can_do_it(int x)
{
	unsigned long long int num = 1,cum=1,out;
	for(int i=1;i<x;i++)
		num = num*2;
	for(int i=1;i<(x-1);i++)
		cum = cum*2;
	out = x*num - ((x-1)*(cum));
	cout<<num<<" "<<out<<endl;
}
