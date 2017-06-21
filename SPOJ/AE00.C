#include<iostream>
using namespace std;
int main()
{
	int n,out;
	cin>>n;
	int sum=0;
//	int	i=1;
	for(int i=1;i<=n;i++)
	{
	for(int j=i*i;j<=n;j=j+i)
	{
		sum+=1;
	}
	}
	cout<<sum;
}
