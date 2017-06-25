//author @ Ayush Aggarwal
// Using two-pointers technique
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll sum=0,ans=0;
	ll l=0,r=0;
	while(l < n)
	{
		while(r < n and (sum + a[r] <= m))
		{
			sum += a[r];
			r++;
		}
		ans = max(ans,sum);
		sum = sum - a[l];
		l++;
	}
	cout<<ans<<endl;
	return 0;
}