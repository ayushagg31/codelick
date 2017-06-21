#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// Directed Graph Case
	vector <PII> v[100005];
	ll n,m;
	ll a,b,w;
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>a>>b>>w;
		v[a].push_back(make_pair(b,w));
		//v[b].push_back(make_pair(a,w));
	}
	bool visit[n+1];
	memset(visit,false,sizeof(visit));
	ll dist[n+1];
	memset(dist,100,sizeof(dist));
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push(make_pair(0,1));
	dist[1] = 0;
	//visit[1] = true;
	while(!q.empty())
	{
		PII p;
		p = q.top();
		q.pop();
		ll wt = p.first;
		ll x = p.second;
		if(visit[x])
			continue;
		visit[x] = true;
		for(ll i=0;i<v[x].size();i++)
		{
			ll e = v[x][i].first;
			ll wte = v[x][i].second;
			if(dist[e] > dist[x] + wte)
			{
				dist[e] = dist[x] + wte;
				q.push(make_pair(dist[e],e));
			}
		}

	}
	for(int i=2;i<=n;i++)
		cout<<dist[i]<<" ";
	return 0;
}