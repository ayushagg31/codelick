#include<iostream>
using namespace std;
int solve(long long int a);
int main()
{
	int t;
	 long long int a,out;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a;
		out = solve(a);
//		cout<<out;
		cout<<"\nCase "<<i+1<<": "<<out;
		cout<<"\n";
	}
}
int solve(long long int a)
{
		int x = -1;	
		long long int qut = a/5,num;
		for(long long int i=1;i<=qut;i++)
		{
			num = a-(i*5);
	//		cout<<num;
			if((num%3==0)&&(num>0))
			{
//				cout<<"HI";
				return(num);
			}
		}
	//	cout<<"Hello";
		return(x);
}
