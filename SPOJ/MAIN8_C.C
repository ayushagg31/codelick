//author @ Ayush Aggarwal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
bool func(ll val,ll k,ll n)
{
	if(k==1)
		return true;
	ll sum=0;
	for(ll i=n-1;i>=0;i--)
	{
		sum +=(a[i]/val);
	}
	if(sum >= k)
		return true;
	else
		return false;
}
void binary_search(ll n,ll k)
{
	ll lo =1;
	ll high =a[n-1]+1;
	ll mid=0;
	while(high > lo)
	{
		 mid = (lo+high)/2;
		if(func(mid,k,n))
			lo = mid+1;
		else
			high = mid;
	}
	cout<<lo-1<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		binary_search(n,k);
	}
	return 0;
}