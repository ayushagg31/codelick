#include <bits/stdc++.h>
using namespace std; 	
typedef long long ll;
int main()
{
	ll n,f;
	vector <ll> v;
	ll sum=0,k,l,var;
	cin>>n>>f;
	for(ll i=0;i<n;i++)
	{
		cin>>k>>l;
		sum +=min(k,l);
		var = min(2*k,l) - min(k,l);
		v.push_back(var);
	}
	sort(v.begin(),v.end());
	ll x = v.size()-1;
	while(f--)
	{
		sum +=v[x];
		x--;
	}
	cout<<sum;
	return 0;
}