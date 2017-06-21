#include <bits/stdc++.h>
using namespace std;
//tring str;
int main()
{
	long long t;
	long long len;
	cin>>t;
	while(t--)
	{
		cin>>str;
		len = str.length();
		long long sum = 0;
		for(long long k=0;k<len;k++)
			{
				long long num = (long long)str[k]-48;
//				cout<<num<<endl;
				sum = sum + num; 
				
			}
			cout<<sum<<endl;	
	}
}
