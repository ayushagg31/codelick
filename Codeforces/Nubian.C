#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
vector <ll> v;
ll n;
ll check(ll x)
{
	ll sum=0;
	for(ll i=1;i<=n;i++)
			v.push_back(a[i]+i*x);
	sort(v.begin(),v.end());
	for(ll i=0;i<x;i++)
		sum +=v[i];
	v.clear();
	return sum;
}
int main()
{
	ll s;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll low = 1;
	ll high = n,mid;
	ll no=0,final=0;
	while(low <=high)
	{
		mid = (high+low)/2;
		ll val = check(mid);
		if(val <=s)
		{
			no = mid;
			final = val;
			low = mid +1;
		}
		else
			high = mid-1;
	}
	cout<<no<<" "<<final;
	return 0;
}