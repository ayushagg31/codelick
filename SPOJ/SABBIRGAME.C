#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,savex=0;
	cin>>t;
	while(t--)
	{
		ll x,sum=0,count=0,var;
		cin>>x;
		for(ll i=0;i<x;i++)
		{
			cin>>var;
			sum = sum+var;
			if(sum<=0)
			{
				count = -1*sum + 1+count;
				sum = 1;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}