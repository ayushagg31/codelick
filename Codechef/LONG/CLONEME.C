#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll N,Q,s1=0,s2=0;
		cin>>N>>Q;
		for(ll i=1;i<=N;i++)
			cin>>a[i];
		ll L1,R1,L2,R2;
		while(Q--)
		{
			cin>>L1>>R1>>L2>>R2;
			ll a1[R1-L1+1],a2[R2-L2+1];
			for(ll i=L1;i<=R1;i++)
				a1[i-L1] = a[i];
			for(ll i=L2;i<=R2;i++)
				a2[i-L2] = a[i];
			ll size = R2-L2+1;
			bool flag = false;
			ll count=0;
			for(ll i=0;i<size;i++)
			{
				ll min1 = a1[i];
				ll min2  = a2[i];
				ll s1 = i;
				ll s2 = i;
				for(ll j=i;j<size;j++)
				{
					if(min1 > a1[j])
					{
						min1 = a1[j];
						s1 = j;
					}
					if(min2 > a2[j])
					{
						min2 = a2[j];
						s2 = j;
					}

				}
				if(a1[s1]!=a2[s2])
					count++;
				if(count>1)
				{
					flag=true;
					break;
				}
				swap(a1[i],a1[s1]);
				swap(a2[i],a2[s2]);
			}
			if(flag)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
	}
	return 0;
}