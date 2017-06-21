#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t,sum=0;
	cin>>t;
	multiset <ll,greater<ll> > pq;
	multiset <ll,greater<ll> > :: iterator it1;
	multiset <ll> q;
	multiset <ll> :: iterator it2;
	while(t--)
	{
		ll x,S;
		cin>>x;
		while(x--)
		{
			cin>>S;
			q.insert(S);
			pq.insert(S);
		}
		it1 = pq.begin();
		it2 = q.begin();
		sum = sum+*it1-*it2;
		q.erase(it2);
		pq.erase(it1);
	}
	cout<<sum<<endl;
	return 0;
}