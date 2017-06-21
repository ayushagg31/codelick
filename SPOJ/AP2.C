#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long int a3,an3,s,a,d,n;
	for(int j=0;j<t;j++)
	{
		cin>>a3>>an3>>s;
		n = (2*s)/(a3+an3);
		d = (an3-a3)/(n-5);
		a = a3-(2*d);
		cout<<n<<endl;
		for(long long int i=0;i<n;i++)
		{
			s = a+(i)*d;
			cout<<s<<" ";
		}
		cout<<endl;
	}
}
