#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int a,b,d;
	bool flag = false;
	while(t--)
	{
		cin>>a>>b>>d;
		for(int i=a;i<=b;i++)
		{
			string str = (char)a;
			bool flag = false;
			for(int i=2;i*i<=a;i++)
			{
				if(a % (i*i) == 0)
				{
					flag = true;
					break;
				}
			}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}