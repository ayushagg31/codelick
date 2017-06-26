//author @ Ayush Aggarwal
// Let's Do this shit.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> mp;
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n],sum[n],tot=0;
		ll seg=0,res=0,final=0;
		mp.clear();
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			tot +=a[i];
			if(tot==0)
				seg++;
			mp[tot]++;
			//cout<<tot<<endl;
		}
		for(auto i=mp.begin();i!=mp.end();i++)
		{
			ll l = i->first;
			ll r = i->second;
			//cout<<l<<" "<<r<<endl;
			if(r > 1)
				res += (r*(r-1))/2;
		}
		//cout<<seg<<" "<<res<<endl;
		cout<<res+seg<<endl;

	}
	return 0;
}