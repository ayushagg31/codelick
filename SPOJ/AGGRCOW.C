#include <bits/stdc++.h>
using namespace std;
int n,c;
int stall[10001];
bool func(int x)
{
	int temp=1;
	int start = stall[0];
	for(int i=1;i<n;i++)
	{
		if(stall[i]-start >=x)
		{
			temp++;
			if(temp==c)
				return true;
			start = stall[i];
		}
		
	}
	return false;
}
int binary_search()
{
	int mid=0,lo=stall[0],high=stall[n-1];
	while(lo<high)
	{
		mid = (high+lo)/2;
		if(func(mid))
			lo = mid+1;
		else
			high = mid;
	}
	return lo-1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(int i=0;i<n;i++)
			cin>>stall[i];
		sort(stall,stall+n);
		cout<<binary_search()<<endl;;
	}
	return 0;
}