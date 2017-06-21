#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visit[1000005];
vector <ll> adj[1000005];
void dfs(ll x)
{
	visit[x] = true;
	//changed here
	for(int i=0;i<adj[x].size();i++)
    {
        if(visit[adj[x][i]]==false)
            dfs(adj[x][i]);
    }
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	char ch;
	ll k=0,ranjana=0;
	char str[n][m];
	ll count[n][m];
	//vector <ll> adj[n*m+1];
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>ch;
			str[i][j] = ch;
			count[i][j] = k;
			k++;
		}
	}
	memset(visit,false,sizeof(visit));
	ll val=0;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			if(str[i][j]=='S' and i+1 < n)
				val = count[i+1][j];
			else if(str[i][j]=='N' and i-1 >=0)
				val = count[i-1][j];
			else if(str[i][j]=='E' and j+1 < m)
				val = count[i][j+1];
			else if(str[i][j]=='W' and j-1 >= 0)
				val = count[i][j-1];
 
			adj[count[i][j]].push_back(val);
			// Changed here
			adj[val].push_back(count[i][j]);
		}
	}
	for(ll i=0;i<n*m ; i++)
	{
		if(visit[i]==false)
		{
			dfs(i);
			ranjana++;
		}
	}
	cout<<ranjana<<endl;
	for(ll i=0;i<n*m;i++)
		adj[i].clear();
 
	return 0;
}