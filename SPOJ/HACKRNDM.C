#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ll xx=0;
	for(int i=0;i<n;i++)
	{
		ll count = a[i] + k;
		ll low=i+1;
		ll high = n-1;
		while(low<=high)
		{
			ll mid = (low+high)/2;
			if(a[mid] > count)
				high = mid-1;
			else if(a[mid] < count)
				low = mid+1;
			else
			{
				xx++;
				break;
			}
		}
	}
	cout<<xx<<endl;
	return 0;
}