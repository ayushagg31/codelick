#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	ll t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		ll sum = a+b;
		ll rank = ((sum)*(2+(sum-1)))/2;
		rank = rank + a+1;
		cout<<rank<<endl;
	}
	return 0;
}