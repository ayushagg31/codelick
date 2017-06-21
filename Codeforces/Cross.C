#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
	ll n,s,dev=0,count=0;
	cin>>n>>s;
	ll a[n];
	vector <ll> v;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	bool flag = false;
	for(ll i=n;i>0;i--)
	{
		ll sum=0;
		for(ll j=1;j<=n;j++)
		{
			ll val=a[j]+j*i;
			//sum = sum+val;
			v.push_back(val);
		}
		sort(v.begin(),v.end());
		for(ll j=0;j<i;j++)
			sum = sum + v[j];
		v.clear();
		if(sum <=s)
		{
			flag = true;
			dev = i;
			count = sum;
			break;
		}
	}
	if(flag)
	cout<<dev<<" "<<count;
	else
		cout<<0<<" "<<0;
	return 0;
}
