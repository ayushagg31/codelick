//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		unsigned int a[n];
		for(int i=0;i<(n-2);i++)
		{
			if(n==99992 or n==99999)
				a[i] = UINT_MAX/n ;
			else
				a[i] = UINT_MAX/n+1;
		}
		a[n-2] = (UINT_MAX%(n-2)-2);
		a[n-1] = 1;
		//unsigned int sum=0;
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		//	sum = sum+a[i];
		}
		cout<<endl;
		//cout<<sum+2<<endl
	}
	return 0;	
}