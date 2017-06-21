#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
	ll T,N,sum=0,var;
	cin>>T;
	while(T--)
	{
		sum=0;
		cin>>N;
		ll i=0;
		while(i<N)
		{
			cin>>var;
			sum +=var;
			i++;
		}
		if(sum%N!=0)
			cout<<"NO"<<endl;
		else
		{

		}
	}
	return 0;
}
