#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,e;
vector <ll> adj[100005];
bool visit[100005];
void dfs(ll x)
{
	stack<ll> s;
	s.push(x);
	visit[x]= true;
	while(!s.empty())
	{
		ll x = s.top();
		s.pop();
		for(ll i=0;i<adj[x].size();i++)
		{
			ll save = adj[x][i];
			if(visit[save]==false)
			{
				s.push(save);
				visit[save] = true;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>e;
		ll x,y;
		memset(visit,false,sizeof(visit));
		for(ll i=1;i<=e;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		ll count=0;
		for(ll i=0;i<n;i++)
		{
			if(visit[i]==false)
			{
				dfs(i);
				count++;
			}
		}
		cout<<count<<endl;
		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
		}
	}
	return 0;
}