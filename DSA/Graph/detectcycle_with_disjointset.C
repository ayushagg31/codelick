//author @ Ayush Aggarwal
//Detect cycle in undirected graph using disjoint set 
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
pair<int,int> p[MAX];
int id[MAX];
void initialize()
{
	for(int i=0;i<MAX;i++)
		id[i] = i;
}
int root(int x)
{
	while(id[x] !=x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}
void union1(int x,int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	initialize();
	bool flag = true;
	int v,e,from,next;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		cin>>from>>next;
		p[i] = make_pair(from,next);
	}
	sort(p,p+e);
	for(int i=0;i<e;i++)
	{
		int x = p[i].first;
		int y = p[i].second;
		if(root(x)!=root(y))
			union1(x,y);
		else
		{
			flag = false;
			break;
		}
	}
	if(flag == false)
		cout<<"Cycle detected in graph"<<endl;
	else
		cout<<"No cycle in graph"<<endl;
	return 0;	
}