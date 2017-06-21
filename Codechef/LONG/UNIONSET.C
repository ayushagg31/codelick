#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> v[2505];
int main()
{
	ios::sync_with_stdio(false);
	ll t,n,jugnoo;
	cin>>t;
	while(t--)
	{
		cin>>n>>jugnoo;
		ll x,len;
		for(ll i=1;i<=n;i++)
		{
			cin>>len;
			for(ll j=1;j<=len;j++)
			{
				cin>>x;
				v[i].push_back(x);
			}
			sort(v[i].begin(),v[i].end());
		}
		vector <ll> ad;
		ll count=0;
		ad.clear();
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				ll v1 = v[i].size();
				ll v2 = v[j].size();
				ll k=0,l=0;
				while(k<v1 && l < v2)
				{
					if(v[i][k] < v[j][l])
						ad.push_back(v[i][k++]);
					else if(v[j][l] < v[i][k])
						ad.push_back(v[j][l++]);
					else
					{
						ad.push_back(v[j][l++]);
						k++;
					}
				}
				while(k < v1)
					ad.push_back(v[i][k++]);
				while(l < v2)
					ad.push_back(v[j][l++]);
				//cout<<ad.size()<<endl;
				if(ad.size()==jugnoo)
					count++;
				ad.clear();
			}
		}
		cout<<count<<endl;
		for(ll i=1;i<=n;i++)
			v[i].clear();

	}
	return 0;
}