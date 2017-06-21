#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950
int n,f;
long double a[10005];
bool func(long double x)
{
	int frnd=0;
	if(x==0)
		return false;
	for(int i=0;i<n;i++)
		frnd = frnd + a[i]/x;
	if(frnd >=f)
		return true;
	return false;
}
long double bs()
{
	long double lo=0,high=a[n-1];
	long double mid=0;
	while(high - lo >= 1e-6)
	{
		mid = (lo+high)/2;
		if(func(mid))
			lo = mid;
		else
			high = mid;
	}
	return lo;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>f;
		f = f+1;
		int a1[n];
		for(int i=0;i<n;i++)
			cin>>a1[i];
		sort(a1,a1+n);
		for(int i=0;i<n;i++)
			a[i] = pi*1*a1[i]*a1[i];
		long double k = bs();
		printf("%.4Lf\n",k);
	}
	return 0;
}