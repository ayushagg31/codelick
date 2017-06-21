#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	ll N,Q;
	cin>>N>>Q;
	ll a[N],L,R;
	for(ll i=0;i<N;i++)
		cin>>a[i];
	while(Q--)
	{
		cin>>L>>R;
		if(L==R)
			cout<<a[L-1]<<endl;
		else
			cout<<"0"<<endl;
	}
	return 0;
}