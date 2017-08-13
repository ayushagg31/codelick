//author @ Ayush Aggarwal
//Impulse : https://cptalks.quora.com/Cut-Vertex-Articulation-point
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector <int> adj[MAX];
int parent[MAX];
int tym[MAX];
int low[MAX];
bool visited[MAX];
int child_count[MAX];	//only for root node
bool cut_vertices[MAX];
void dfs(int s)
{
	static int count=0;
	visited[s] = true;
	low[s] = count;
	tym[s] = count;
	count++;
	for(int i=0;i<adj[s].size();i++)
	{
		int curr = adj[s][i];
		if(parent[s] == curr)
			continue;
		if(visited[curr]==false)
		{
			child_count[s]++;
			parent[curr] = s;
			dfs(curr);
			low[s] = min(low[s],low[curr]);
			if(low[curr] >= tym[s])
				cut_vertices[s] = true;;
		}
		else
			low[s] = min(low[s],tym[curr]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int v,e;
	cin>>v>>e;
	int a,b;
	for(int i=1;i<=e;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	parent[1] = -1;	//kinda NULL -_-
	dfs(1);

	if(child_count[1] >1)
		cut_vertices[1] = true;
	else
		cut_vertices[1] = false;
	for(int i=1;i<=v;i++)
	{
		if(cut_vertices[i])
			cout<<i<<" is a articulation point"<<endl;
	}
	return 0;	
}