//author @ Ayush Aggarwal
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
bool visit[MAX];
vector <int> v[MAX],vrev[MAX];
stack <int> s;
int t=0,finish[MAX];
void dfs(int start)
{
	visit[start] = true;
	for(int i=0;i<v[start].size();i++)
	{
		if(!visit[v[start][i]])
			dfs(v[start][i]);
	}
	s.push(start);
}
void dfs_rev(int start)
{
	visit[start] = true;
	for(int i=0;i<vrev[start].size();i++)
	{
		if(!visit[vrev[start][i]])
			dfs(vrev[start][i]);
	}
}
int main()
{	
	int u,v1,V,E;
	cin>>V>>E;
	for(int i=0;i<E;i++)	
	{
		cin>>u>>v1;
		//edge from u to v
		v[u].push_back(v1);
		vrev[v1].push_back(u);
	}
	memset(visit,false,sizeof(visit));
	for(int i=0;i<V;i++)
	{
		if(visit[i] == false)
			dfs(i);
	}
	memset(visit,false,sizeof(visit));
	int count=0;
	while(!s.empty())
	{
		int val = s.top();
		s.pop();
		if(visit[val] == false)
		{
			dfs_rev(val);
			count++;
		}
	}
	cout<<"Number of connected components :"<<count;
	return 0;
}