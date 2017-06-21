#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int p,l;
		cin>>p;
		cin>>l;
		int a[l];
		for(int i=0;i<l;i++)
			cin>>a[i];
		priority_queue<int,vector<int>,greater<int> >q;
		int x,rep,prev;
		for(int i=0;i<l;i++)
		{
			q.push(a[i]);
			rep  = a[i];
			x = a[i]*2 ;
			q.push(x+a[i]);
			prev = x + a[i];
			for(int j=3;j<=p;j++)
			{
				rep = x + a[i];
				x = rep;
				prev = prev + x;
				q.push(prev);
			}
		}
		int sum=0;
		for(int i=1;i<=p;i++)
		{
			sum = q.top();
			q.pop();
		}
		cout<<sum<<endl;
	}	
	return 0;
}