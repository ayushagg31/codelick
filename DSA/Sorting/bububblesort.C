#include <iostream>
using namespace std;

int main()
{
	int n,temp=0,savage=0;
	cin >> n;
	int a[n];
	cout<<"Enter elements of array to be sorted \n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}	
		}
	}
	

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
