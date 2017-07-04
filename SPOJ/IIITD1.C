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
		ll x;
		cin>>x;
		ll y = abs(x);
		ll z = y;
		ll min_val=0;
		ll n=0;
		while(y)
		{
			y /=10;
			n++;
		}
		min_val = pow(10,n-1);
		if(x < 0)
			min_val = min_val + 2*z;
		if(x==0)
			min_val = 1;
		cout<<min_val<<endl;
	}
	return 0;
}