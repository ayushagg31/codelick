//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e9 + 5
#define MAX 100
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int dist[MAX][MAX];
	int v,e;
	cin>>v>>e;
	int from,next,wt;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i==j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	for(int i=0;i<e;i++)
	{
		cin>>from>>next>>wt;
		dist[from][next] = min(wt,dist[from][next]);
	}
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(dist[i][k] !=INF	and dist[k][j] !=INF)
				{
					if(dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];				
				}
			}
		}
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}