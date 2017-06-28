//author @ Ayush Aggarwal
// Let's Do this shit.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n;
	cin>>t;
	while(t--)	
	{
		cin>>n;
		ll a[n];
		map<ll,ll> mp;
		mp.clear();
		mp[0]++;	
		ll tot[n],sum=0,res=0;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			sum = sum+a[i];
				res+=mp[sum - 47];
			mp[sum]++;
		}
		cout<<res<<endl;
	}
	return 0;
}