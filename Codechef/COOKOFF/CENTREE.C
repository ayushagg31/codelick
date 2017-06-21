#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin>>t;
	int n,b;
	while(t--)
	{
		cin>>n>>b;
		if(n==2)
		{
			if(b==1)
				cout<<"YES\n1 2\n";
			else
				cout<<"NO\n";
		}
		else
		{
			if(n < 4*b)
				cout<<"NO\n";
			else		
			{
				cout<<"YES\n";
				if(b==0)
				{
					for(int i=2;i<=n;i++)
						cout<<"1 "<<i<<endl;
				}
				else
				{
					int val = 2*b+1;
					for(int i=2;i<=2*b+1;i++)
						cout<<i-1<<" "<<i<<endl;
					for(int i=2*b+2;i<=n;i++)
						cout<<val<<" "<<i<<endl;
				}

			}
		}
	}
	return 0;
}