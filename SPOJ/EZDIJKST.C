#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	vector <PII> adj[10005];
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll a,b,wt;
		for(ll i=0;i<m;i++)
		{
			cin>>a>>b>>wt;
			adj[a].push_back(make_pair(b,wt));
		}
		ll source ,dest;
		cin>>source>>dest;
		priority_queue<ll,vector<PII>,greater<PII> > q;
		q.push(make_pair(0,source));
		bool visit[n+1];
		ll dist[n+1];
		memset(visit,false,sizeof(visit));
		memset(dist,10005,sizeof(dist));
		dist[source] = 0;
		while(!q.empty())
		{
			PII p;
			p = q.top();
			q.pop();
			ll x = p.second;
			ll w = p.first;
			if(visit[x])
				continue;
			visit[x] = true;
			for(ll i=0;i<adj[x].size();i++)
			{
				ll y = adj[x][i].first;
				ll wei = adj[x][i].second;
				if(dist[y] > dist[x] + wei)
				{
					dist[y] = dist[x] + wei;
					q.push(make_pair(dist[y],y));
				}
			}
		}
		if(dist[dest] >10000)
			cout<<"NO"<<endl;
		else
		cout<<dist[dest]<<endl;

		//else
		for(ll i=1;i<=n;i++)
			adj[i].clear();

	}
	return 0;
}