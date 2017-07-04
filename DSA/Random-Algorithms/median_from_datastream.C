//author @ Ayush Aggarwal
//Code for calculating median from data stream
//similar problem link : https://www.hackerearth.com/problem/algorithm/the-one-with-the-heckle-manor/description/
//Explanation link :https://www.youtube.com/watch?v=VmogG01IjYc
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue <ll> big;
priority_queue<ll,vector <ll>,greater<ll> > small;

void add(ll num)
{
	if(!big.empty() and num < big.top())
	{
		big.push(num);
		if (big.size() - small.size() == 1)
		{
			small.push(big.top());
			big.pop();
		}
	}
	else
	{
		small.push(num);
		if (small.size() - big.size() == 2)
		{
			big.push(small.top());
			small.pop();
		}
	}
}
ll median()
{
	if (small.size() == big.size())
		return (small.top() + big.top()) / 2.0;
	return small.top();
}
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
		add(x);
		cout<<median()<<endl;
	}
	return 0;
}