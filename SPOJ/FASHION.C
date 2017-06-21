#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int t;
cin>>t;
int n,sum=0;
for(int i=0;i<t;i++)
{	int sum=0;
	cin>>n;
	int m[n],f[n];
	for(int j=0;j<n;j++)
		cin>>m[j];
	for(int j=0;j<n;j++)
		cin>>f[j];
		sort(m,m+n);
		sort(f,f+n);
	for(int k=0;k<n;k++)
	{
		sum +=m[k]*f[k];
		
	}
	cout<<sum<<endl;
}

}
