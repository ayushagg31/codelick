#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
void comp(char str[],long long len)
{
	for(long long i=0;i<len;i++)
		{
			if(str[i] =='0')
				str[i] = '1';
			else
				str[i] = '0';
		}
//		return 0;
}

int main()
{
	char str[MAX];
	cin>>str;
	long long len = strlen(str);
	long long count=0;
	//comp(str,len);
	for(long long i=len-1;i>=0;i--)
	{
		if(str[i]=='1')
			{comp(str,i+1);
				count++;
		//cout<<str<<endl;}
	}}
	cout<<count;
	return 0;
}