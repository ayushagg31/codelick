//Their is some problem with this code........I don't know what??
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int id[MAX];
pair <int,pair<int,int> > p[MAX];
int n,m;
void initialize()
{
	for(int i=1;i<=MAX;i++)
		id[i] = i;
}
int root(int x)
{
	while(id[x]!=x)
	{
		x = id[x];
	}
	return x;
}
void union1(int x,int y)
{
	int p = root(x);
    int q = root(y);
    id[p] = q;
}
int kruskal()
{
	int cost=0,min_cost=0;
	int x,y;
	for(int i=1;i<=m;i++)
	{	
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x)!=root(y))
		{
			min_cost = min_cost+cost;
			union1(x,y);
		}
	}
	return min_cost;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	initialize();
	cin>>n>>m;
	int x,y,wt;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>wt;
		p[i] = make_pair(wt,make_pair(x,y));
	}
	sort(p,p+m);
	int min_cost = kruskal();
	cout<<min_cost<<endl;
	return 0;
}