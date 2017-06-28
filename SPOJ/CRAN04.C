//author @ Ayush Aggarwal
// Let's Do this shit.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)	
	{
		ll sum=0,n,k,ans=0;
		cin>>n>>k;
		ll a;
		string str;
		cin>>str;
		int save[1000010];
		memset(save,0,sizeof(save));
		save[0]++;
		for(ll i=0;i<n;i++)
		{
			a = str[i] - (ll)'a' + 49;
			//cout<<a[i]<<endl;
			sum +=a;
			//cout<<sum<<endl;
			if(sum>=k)
			ans +=save[sum-k];
			//cout<<ans<<endl;
			save[sum]++;
		//	cout<<mp[sum]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}