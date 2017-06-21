#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	string str;
	while(t--)
	{
		cin>>str;
		int len = str.length();
		int count1=0,count2=0;
		int i=0;
		if(str[0]=='U')
			count1++;
		else
			count2++;
		for(int i=1;i<len;i++)
		{
			if(str[i]=='U' and str[i-1]=='D')
				count1++;
			else if(str[i]=='D' and str[i-1]=='U')
				count2++;
		}
		cout<<min(count1,count2)<<endl;
		
	}
	return 0;
}