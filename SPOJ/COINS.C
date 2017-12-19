//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,ll> res;
ll coins(int n)
{
	res[0] = 0;
	res[1] = 1;
	res[2] = 2;
	res[3] = 3;
	res[4] = 4;
	if(n==0)
		return 0;
	if(res[n]!=0)
		return res[n];
	// both n and fuction has different data type
	ll val = coins(n/2)+coins(n/3)+coins(n/4);
	if(val > n)
		res[n] = val;
	else
		res[n] = n;
	return res[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n)
		cout<<coins(n)<<endl;
	return 0;	
}