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
	for(int i=0;i<n;i++)
	{
		int min = a[i];
		for(int j=i;j<n;j++)
		{
			if(min > a[j])
			{
				min = a[j];
				savage = j; 
			}
		}
		temp = a[i];
		a[i] = a[savage];
		a[savage] = temp;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
