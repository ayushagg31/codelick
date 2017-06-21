#include<iostream>
using namespace std;
void calculate(long long int );
int main()
{
	int t;
	long long int a;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a;
		calculate(a);
	}
}
void calculate(long long int x)
{
	long long int p=x,sum=0,t;
	while(x>0)
	{
		t = x%10;
		sum +=t;
		x = x/10;
	}
	if(p%sum==0)
	cout<<p<<endl;
	else
		calculate(p+1);
	
}
