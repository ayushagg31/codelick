#include<iostream>
using namespace std;
#define mod 1000007
int main()
{
	long long int t,a,out;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long int sum=0,sum1;
		cin>>a;
	for(int j=1;j<=a;j++)
		sum +=j;
	sum1 = sum-a;
	sum = sum*2;
	out = sum1+sum;
	out = out%mod;
	cout<<out<<endl;
	}
}
