#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
int main()
{
	stack <ll> s;
	queue <ll> q;
	vector <ll> v;
	ll N,M,saver;
	cin>>N>>M;
	ll a[N],i=0;
	for(ll i=0;i<N;i++)
		cin>>a[i];
	ll query[M];
	for(ll i=0;i<M;i++)
		cin>>query[i];
	sort(a,a+N);
	for(int i=0;i<N;i++)
		s.push(a[i]);
	v.pb(s.top());
	q.push(s.top()/2);
	s.pop();
	while(!s.empty())
	{
		if(s.top() > q.front())
		{
			v.pb(s.top());
			q.push(s.top()/2);
			s.pop();
		}
		else if(s.top() < q.front())
		{
			v.pb(q.front());
			q.push(q.front()/2);
			q.pop();
		}
		else
		{
			if(q.front() == 1)
				break;
			else
			v.pb(q.front());
			q.push(q.front()/2);
			q.pop();
		}
	}
	while(q.front()!=1)
	{
		v.pb(q.front());
		q.push(q.front()/2);
		q.pop();
	}
	/*while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;*/
	for(ll i=0;i<M;i++)
	{
		ll save = query[i];
		if(save > v.size())
			cout<<"1"<<endl;
		else
			cout<<v[save-1]<<endl;
	}
	return 0;
}
