#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> PII;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		map <string,ll> mp;
		ll s;
		cin>>s;
		string str;
		vector <PII> adj[s+1];
		for(ll i=1;i<=s;i++)
		{
			cin>>str;
			mp[str] = i;
			ll x;
			cin>>x;
			ll a,wt;
			while(x--)
			{
				cin>>a>>wt;
				adj[i].push_back(make_pair(a,wt));
			}
		}
		ll query;
		cin>>query;
		string str1,str2;
		while(query--)
		{
			cin>>str1>>str2;
			ll source = mp[str1];
			ll dest = mp[str2];
			//cout<<source<<" "<<dest<<endl;
		priority_queue<PII,vector<PII>,greater<PII> > q;
		q.push(make_pair(0,source));
		bool visit[s+1];
		ll dist[s+1];
		memset(visit,false,sizeof(visit));
		memset(dist, 0x3f,sizeof(dist));
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
		cout<<dist[dest]<<endl;
		}
		for(ll i=1;i<=s;i++)
			adj[i].clear();

	}
	return 0;
}