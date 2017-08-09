//author @ Ayush Aggarwal

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define anf 10000
vector <int> vj[1000];
int dist[1000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int v,e;
	bool flag = false;
	cin>>v>>e;
	int from,to,wt;
	for(int i=0;i<e;i++)
	{
		cin>>from>>to>>wt;
		vj[i].push_back(from);
		vj[i].push_back(to);
		vj[i].push_back(wt);
	}
	for(int i=0;i<v;i++)
		dist[i] = anf;
	dist[0] = 0;
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int u1 = vj[j][0];
			int u2 = vj[j][1];
			int u3 = vj[j][2];
			if(dist[u1] + u3 < dist[u2])
				dist[u2] = dist[u1] + u3;
		}
	}
	for(int j=0;j<e;j++)
	{
		int u1 = vj[j][0];
		int u2 = vj[j][1];
		int u3 = vj[j][2];
		if(dist[u1] + u3 < dist[u2])
			flag = true;
	}
	for(int i=0;i<v;i++)
		cout<<"from source to "<<i<<" = "<<dist[i]<<endl;
	if(flag = true)
		cout<<"Negative weight cycle exception"<<endl;
	return 0;	
}