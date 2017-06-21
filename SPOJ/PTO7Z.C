#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100000
ll dist[MAX];
bool visit[MAX];
ll n;
vector <ll> adj[MAX];
ll bfs(ll s)
{
	memset(visit,false,sizeof(visit));
	memset(dist,0,sizeof(dist));
	queue <ll> q;
	q.push(s);
	dist[s] = 0;
	visit[s] = true;
	while(!q.empty())
	{
		ll x = q.front();
		q.pop();
		for(ll i=0;i<adj[x].size();i++)
		{
			ll fk = adj[x][i];
			if(visit[fk]==false)
			{
				visit[fk] = true;
				q.push(fk);
				dist[fk] = dist[x] + 1;
			}
		}
	}
	//for(ll i=1;i<=n;i++)
	//	cout<<dist[i]<<endl;
	return(max_element(dist,dist+n+1) - dist);
}
int main()
{
	ll x,y;
	cin>>n;
	for(ll i=1;i<n;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll v1 = bfs(1);
	//cout<<v1;
	ll out = bfs(v1);
	//cout<<out;
	cout<<dist[out]<<endl;
	//cout<<max;
	return 0;
}