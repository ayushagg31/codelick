#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	char ch[10];
	int b,r,m,e;
	int k=4;
	cin>>t;
	while(t--)
	{
		k=4;
	while(k--)
		{
		cin>>ch;
		if(ch[0]=='B')
			cin>>b;
		else if(ch[0]=='R')
			cin>>r;
		else if(ch[0]=='M')
			cin>>m;
		else
			cin>>e;
		}
		cout<<b<<" "<<r<<" "<<m<<" "<<e<<endl;
		if((r<m)&&(b>e))
			cout<<"Barcelona"<<endl;
		else
			cout<<"RealMadrid"<<endl;
	}
	return 0;
}