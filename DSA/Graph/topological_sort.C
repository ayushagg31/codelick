//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> vec[100];
stack <int> s;
bool visited[1000];
void topsort(int i)
{
	visited[i] = true;
	for(int j=0;j<vec[i].size();j++)
	{
		if(visited[vec[i][j]] == true)
			continue;
		topsort(vec[i][j]);
	}
	s.push(i);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int e,v;
	cin>>v>>e;
	memset(visited,false,sizeof(visited));
	int from,next;
	for(int i=0;i<e;i++)
	{
		cin>>from>>next;
		vec[from].push_back(next);
	}
	for(int i=0;i<v;i++)
	{
		if(visited[i]==true)
			continue;
		topsort(i);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;	
}