#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
#define MAX 100000
bool marked[MAX];
vector <PII > adj[MAX];
void prim(int x)
{
	priority_queue<PII,vector<PII>,greater<PII> > q;
	PII p;
	q.push(make_pair(0,x));
	ll y,wt,min_cost=0;
	while(!q.empty())
	{
		p = q.top();
		q.pop();
		x = p.second;
		wt = p.first;
		if(marked[x]==true)
			continue;
		min_cost +=wt;
		marked[x] = true;
		for(ll i=0;i<adj[x].size();i++)
		{
			y = adj[x][i].second;
			wt = adj[x][i].first;
			if(marked[y]==false)
				q.push(make_pair(wt,y));
		}
	}
	cout<<min_cost<<endl;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,e,x,y,wt;
	cin>>n>>e;
	for(ll i=1;i<=e;i++)
	{
		cin>>x>>y>>wt;
		adj[x].push_back(make_pair(wt,y));
		adj[y].push_back(make_pair(wt,x));
	}
	prim(1);
	return 0;
}