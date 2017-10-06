//author @ Ayush Aggarwal

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
		ll n,p;
		cin>>n>>p;
		ll cakewalk=0;
		ll hard=0,x;
		while(n--)
		{
			cin>>x;
			if(x <=(p/10))
				hard++;
			else if(x>=(p/2))
				cakewalk++;
		}
		if(hard == 2 and cakewalk==1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;	
}