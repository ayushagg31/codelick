#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll count=0,x;
	while(n--)
	{
		cin>>x;
		if(x%m==0)
			count++;
	}
	cout<<count;
	return 0;
}