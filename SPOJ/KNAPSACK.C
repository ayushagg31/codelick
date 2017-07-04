//author @ Ayush Aggarwal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,L;
	cin>>N>>L;
	int wt[L],val[L];
	for(int i=0;i<L;i++)
		cin>>wt[i]>>val[i];
	int T[L+1][N+1];
	for(int i=0;i<L+1;i++)	
	{
		for(int j=0;j<N+1;j++)
		{
			if(i==0 || j==0)
				T[i][j] = 0;
			else if( j < wt[i-1])
				T[i][j] = T[i-1][j];
			else
				T[i][j] = max(T[i-1][j-wt[i-1]] + val[i-1],T[i-1][j]);
			cout<<T[i][j]<<endl;
		}
	}
	//cout<<T[1][1]<<endl;
	cout<<T[L][N]<<endl;
	return 0;
}