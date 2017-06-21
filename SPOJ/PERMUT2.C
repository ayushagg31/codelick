#include<iostream>
using namespace std;
int main()
{
	int n;
	while(true)
	{
		cin>>n;
		if(n==0)
			break;
		else
		{
			int a[n],b[n],count=0;
			for(int i=0;i<n;i++)	
				cin>>a[i];
			for(int i=0;i<n;i++)
				b[a[i]-1]=i+1;
			for(int i=0;i<n;i++)
			{
				if(b[i]==a[i])
					count++;
			}
			if(count==n)
				cout<<"ambiguous"<<endl;
			else
				cout<<"not ambiguous"<<endl; 
		}
	}
}
