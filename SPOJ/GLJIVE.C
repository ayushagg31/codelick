#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a[10],s[10],d1,d2;;
	for(int i=0;i<10;i++)
		cin>>a[i];
	int sum=0;
	for(int i=0;i<10;i++)
	{
		sum +=a[i];
		s[i] = sum;
		if(sum>100)
		{
			d1 = sum-100;
			d2 = 100-s[i-1];
			if(d1>d2)
				cout<<s[i-1];
			else
				cout<<sum;
			return 0;
		}
		
	}
	cout<<sum;
	
}

