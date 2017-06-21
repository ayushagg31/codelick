#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin>>t;
	long long a,b;
	while(t--)
	{
		cin>>a>>b;
		if(a%2==0)
			cout<<"Suresh"<<endl;
		else if(b%2==0)
			cout<<"Suresh"<<endl;
		else
			cout<<"Ramesh"<<endl;
	}
	return 0;
}