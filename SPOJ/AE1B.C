#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,s;
	cin>>n>>k>>s;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int total = k*s;
	int sum = a[n-1];
	int count =1;
	for(int i=n-2;i>=0;i--)
	{
		if(sum<total)
		{
			sum+=a[i];
			count++;
		}
	}
	cout<<count;
}
