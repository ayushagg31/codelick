#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a,ll N)
{
	ll num=1;
	if(N==0)
		return 1;
	if(N==1)
		return a;
	else
	{
	ll count=0;
	while(num <= 1e18/a && count <=N)
	{
		num = num*a;
		count++;
	}
		return num;
	}
}
int main()
{
	ll x,y,l,s;
	cin>>x>>y>>l>>s;
	ll count=0;
	bool flag = false;
	//vector <ll> v;
	ll max=0;
	//v.clear();
	for(ll i=l;i<=s;i++)
	{
		ll a=i/x;
		ll b=i/y;
		//cout<<flag<<endl;
		flag = false;
		//cout<<max<<endl;
		for(ll j=0;j<=a;j++)
		{
			for(ll k=0;k<=b;k++)
			{
				if(i == pow(x,j)+pow(y,k))
				{
					flag = true;
					//cout<<i<<" is bad\n";
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
			{
				count++;
			//cout<<count<<endl;
			}
		else
		{
			if(max < count)
				max= count;
			count=0;
		}

	}
	if(max > count)
	cout<<max<<endl;
	else
		cout<<count;
	return 0;	
}