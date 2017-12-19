//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int action(string str)
{
	int len = str.length();
	int dp[len];
	dp[0] = 1;
	int j = int(str[0])-48;
	int k = int(str[1])-48;
	int val = j*10+k;
	if(val>9 and val<=26)
	{
		if(k==0)
			dp[1] = dp[0];
		else
			dp[1] = dp[0]+1;
	}
	else
		dp[1] = dp[0];
	for(int i=2;i<len;i++)
	{
		j = int(str[i-1])-48;
		k = int(str[i])-48;
		val = j*10+k;
		if(val>9 and val<=26)
		{
			if(k!=0)
				dp[i] = dp[i-1]+dp[i-2];
			else
				dp[i] = dp[i-2];
		}
		else
			dp[i] = dp[i-1];
		if(val>26 and k==0)
			return 0;
	}
	return dp[len-1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	while(true)
	{
		cin>>str;
		if(str=="0")
			break;
		cout<<action(str)<<endl;
	}
	return 0;	
}