#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum = sum+a[i];
		}
	int x;
	int val = ((k-0.5)*n-sum)*2;
	x = max(0,val);
	cout<<x;
	return 0;
}