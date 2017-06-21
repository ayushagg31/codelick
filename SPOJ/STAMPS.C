#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,a,b;
	cin>>t;
	for(int p=0;p<t;p++)
	{
		int sum=0;
		cin>>a>>b;
		int stamp[b];
		for(int j=0;j<b;j++)
			cin>>stamp[j];
		sort(stamp,stamp+b);
		int count = 1;
			sum = stamp[b-1];
		for(int i =b-2;i>=0;i--)
		{	
			
			if(sum<a)
			{
				sum += stamp[i];
				count++;
			}
			else
				break;
		}
		cout<<"\n\nScenario #"<<p+1<<":"<<endl;
		if(sum>=a)
		cout<<count<<endl;
		else
		cout<<"impossible"<<endl;
			}
}
