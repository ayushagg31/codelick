#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,temp=0,k;
	cin >> n;
	int a[n];
	cout<<"Enter elements of array to be sorted \n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		k = i;
		int victim = a[i];
		for(int j=k-1;j>=0;j--)
		{
			if(victim < a[j])	//2 7 12 13 5
			{swap(a[j],a[k]); 
				k = j;
			}
		}
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
