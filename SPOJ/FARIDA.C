//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	ll n;
	cin>>t;
	for(ll j=1;j<=t;j++)
	{
		cin>>n;
		if(n==0)
		{
			cout<<"Case "<<j<<": "<<n<<endl;
			continue;
		}
		ll a[n];
		for(ll i=0;i<n;i++)
			cin>>a[i];
		if(n==1)
		{
			cout<<"Case "<<j<<": "<<a[0]<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<"Case "<<j<<": "<<max(a[1],a[0])<<endl;
			continue;
		}
		if(n==3)
		{
			cout<<"Case "<<j<<": "<<max(a[0]+a[2],a[1])<<endl;
			continue;			
		}
		ll res;
		ll dp[n];
		dp[0] = a[0];
		dp[1] = a[1];
		dp[2] = a[0] + a[2];
		for(int i=3;i<n;i++)
			dp[i] = max(dp[i-2],dp[i-3]) + a[i];
		res = max(dp[n-1],dp[n-2]);
		cout<<"Case "<<j<<": "<<res<<endl;
	}
	return 0;	
}