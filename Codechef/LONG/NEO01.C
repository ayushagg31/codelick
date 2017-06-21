#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll a[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	ll N;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>N;
		vector <ll> v;
		v.clear();
		ll sum=0,count=0,laila=0;
		for(ll i=0;i<N;i++)
		{
			cin>>x;
			if(x>=0)
			{
				sum = sum+x;
				count++;
			}
			else
				v.push_back(-1*x);
		}
		ll nano = sum*count,save=0;
		sort(v.begin(),v.end());
		for(ll i=0;i<v.size();i++)
		{
			if(((sum -v[i])*(count+i+1)) > nano)
			{
				nano = (sum -v[i])*(count+i+1);
				sum = sum-v[i];
			}
			else
			{
				save = i;
				break;
			}
		}
		ll total=0;
		for(ll i=save;i<v.size();i++)
			total +=v[i];
		cout<<nano-total<<endl;
	}
	return 0;
}