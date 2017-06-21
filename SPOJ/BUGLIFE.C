#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 3000
vector <ll> adj[MAX];
ll color[MAX];
bool bfs(ll z){
	queue <ll> q;
	q.push(z);
	color[z] = 1;
	//here color work like visit
	while(!q.empty()){
		ll x = q.front();
		q.pop();
		for(ll i=0;i<adj[x].size();i++)
		{
			ll p = adj[x][i];
			if(color[p]==-1)
			{
				color[p] = 1-color[x];
				q.push(p);
			}
			else if(color[p]==color[x])
				return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	ll m,x,n,y;
	for(ll i=1;i<=t;i++)
	{
		cin>>n>>m;
		for(int j=0;j<m;j++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool flag = false;
		memset(color,-1,sizeof(color));
		for(ll u=1;u<=n;u++)
		{
			if(color[u]==-1)
				flag = bfs(u);
			if(!flag)
				break;
		}
		cout<<"Scenario #"<<i<<":\n";
		if(!flag)
			cout<<"Suspicious bugs found!\n";
		else
			cout<<"No suspicious bugs found!\n";
		for(ll z=1;z<=n;z++)
			adj[z].clear(); 
	}
	return 0;
}
