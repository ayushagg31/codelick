#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
long long pow(int a,long long var)
{
	a = 2;
	if(var == 0)
		return 1;
	else if(var == 1)
		return a;
	else{
	long long R = (pow(a,var/2)%M);
	if(var%2==0)
		return ((R%M)*(R%M))%M;
	else
		return(((R%M)*a*(R%M))%M);
	}
}
int main()
{
	long long var,sum=0;
	cin>>var;
	vector <long long> v;
	long long a[var];
	for(long long i=0;i<var;i++)
		cin>>a[i];
	sort(a,a+var);
	for(long long i=0;i<(pow(2,var));i++)
	{
		for(long long j=0;j<var%M;j++)
				if(i & (1<<j))
					v.push_back(a[j]%M);
			if(v.size() > 1)
				sum = (sum%M + v[v.size() -1]%M - v[0]%M)%M;
			v.clear();
	 }
	cout<<sum%M;
	return 0;
}