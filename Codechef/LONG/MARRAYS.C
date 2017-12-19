//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int k;



		int fmax[n],fmin[n],smax[n],smin[n];
		for(int i=0;i<n;i++)
		{
			cin>>k;
			int fsmall = INT_MAX;
			int ssmall = INT_MAX;
			int flarge = INT_MIN;
			int slarge = INT_MIN;
			int val;
			for(int j=0;j<k;j++)
			{
				cin>>val;
				if(val < fsmall)
				{
					ssmall = fsmall;
					fsmall = val;
				}
				else if(val < ssmall and val !=fsmall)
					ssmall = val;
				if(val > flarge)
				{
					slarge = flarge;
					flarge =val;
				}
				else if(val > slarge and val !=flarge)
					slarge = val;
			}
			fmin[i]=fsmall;
			smin[i]=ssmall;
			fmax[i]=flarge;
			smax[i]=slarge;
		}
		int sum=0;
		for(int i=n-1;i>0;i--)
		{
			if(abs(fmax[i]-fmin[i-1]) > abs(fmin[i]-fmax[i-1]))
			{
				sum = sum + abs(fmax[i]-fmin[i-1])*i;
					fmin[i-1] = smin[i-1];
			}
			else
			{
				sum = sum + abs(fmin[i]-fmax[i-1])*i;
					fmax[i-1] = smax[i-1];
			}
		}
		cout<<sum<<endl;

	}
	return 0;	
}