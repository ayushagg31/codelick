//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector <int> adj[MAX];
int White = 0;	//unvisited node
int Black = 1;	//visited node
int Gray  = -1;	//visiting node
int color[MAX];
bool dfs(int start)
{
	color[start] = Gray;
	for(int i=0;i<adj[start].size();i++)
	{
		if(color[adj[start][i]] == Gray)
			return true;
		if(color[adj[start][i]] == Black)
			continue;
		if(dfs(adj[start][i]))
			return true;
	}
	color[start] = Black;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int v,e,a,b;
	bool flag = false;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=0;i<v;i++)
	{
		if(color[i]==White)
		{
			if(dfs(i))
			{
				flag = true;
				break;
			}
		}
	}
	if(flag == true)
		cout<<"Cycle detected"<<endl;
	else
		cout<<"No cycle detected"<<endl;
	return 0;	
}