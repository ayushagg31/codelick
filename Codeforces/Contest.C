#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll q;
	cin>>q;
	ll x,sum=0;
	for(ll i=0;i<q;i++)
	{
		cin>>x;
		sum = sum+x;
	}
	ll m,y;
	cin>>m;
	vector<pair<ll,ll> >v;
	bool flag = false;
	for(ll i=0;i<m;i++)
	{
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	ll out=-1;
	for(ll i=0;i<v.size();i++)
	{
		if(v[i].first==sum)
		{
			out = sum;
			break;
		}
		else if(v[i].first>sum)
		{
			out = v[i].first;
			break;
		}
		else if(v[i].second >=sum && v[i].first <sum)
		{
			out = sum;
			break;
		}
	}
	cout<<out<<endl;
	return 0;
}