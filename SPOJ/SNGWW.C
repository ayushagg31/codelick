#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{	
		cin>>n;
		int a[n][n];
		int count=1;
		for(int i=0;i<n;i++)
		{
			a[i][i] = count; 
			count++;
		}
		int j=0;
		for(int i=n-1;i>=0;i--)
		{
			a[i][j] = count;
			count++;
			j++;
		}
		int ans;
		if(n%2==0)
		ans = n*n;
		else
		ans = n*n+1;
		int save;
		save = n/2;
		for(int i=save;i>=0;i--)
			//cout << a[i][i]<<" ";
			ans = ans - a[i][i];
		cout<<"DWON "<<ans<<endl;
	}
		return 0;
}
