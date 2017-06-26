//author @ Ayush Aggarwal
// Let's Do this shit.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,a,b,c;
	cin>>t;
	while(t--)	
	{
		cin>>a>>b>>c;
		if(c%2==0)
		{
			cout<<max(a,b)/min(a,b)<<endl;
		}
		else
			cout<<max(a*2,b)/min(a*2,b)<<endl;	
	}
	return 0;
}