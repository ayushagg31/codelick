#include <bits/stdc++.h>
using namespace std;
 
#define MX 10000000
 
int main() {
	// your code goes here
	int T;
	while(1)
	{
		int N,i,j,k;
		cin>>N;	
		if(N==0)
			return 0;
		int dis[N+1][N+1];
memset(dis,0,sizeof(dis));
		for(i=0; i<=N ; i++)
			for(j=0 ; j<=N ; j++)
				dis[i][j] = MX;
 
		for(i=1 ; i<=N ; i++)
		{
			int x;
			string str;
			cin>>x>>str;
			if(str == "true")
				dis[i][x] = 2;
			else
				dis[i][x] = 1;
		}
 
		for(k=1;k<=N;k++)
		{
			for(i=1;i<=N;i++)
			{	
				for(j=1;j<=N;j++)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
 
		int temp=0;
		for(i=1 ; i<=N ; i++)
		{
			if( dis[i][i] < MX/ 2 && dis[i][i] % 2 == 1)
			{
				cout<<"PARADOX"<<endl;
				temp = 1;
				break;
			}
 
		}
		if(temp == 0)
		{
			cout<<"NOT PARADOX"<<endl;
		}
	}
	return 0;
}