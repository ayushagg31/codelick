#include <iostream>
using namespace std;
void merge(int a[],int p,int q,int r) ;
void mergesort(int a[],int p,int r);
int main()
{
	int n,temp=0,savage=0;
	cin >> n;
	int a[n];
	cout<<"Enter elements of array to be sorted \n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
void mergesort(int a[],int p,int r)
{
	if(p<r)
	{
		int mid = (p+r)/2;
		mergesort(a,p,mid);
		mergesort(a,mid+1,r);
		merge(a,p,mid,r);
	}
}
void merge(int a[],int p,int mid,int r)
{
	int n1 = mid-p+1;
	int n2 = r-mid;
	int a1[n1];
	int a2[n2];
	int k=0,t=0;
	for(int i=p;i<=mid;i++)
	{
		a1[k] = a[i];
		k++;
	}
	for(int i=mid+1;i<=r;i++)
	{
		a2[t] = a[i];
		t++;
	}
	int i=0;
	k = p;
	int j = 0;
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			a[k] = a1[i];
			i = i+1;
		}
		else 
		{
			a[k] = a2[j];
			j = j+1;
		}
		k = k+1;
	}

	while(i<n1)
	{
		a[k++] = a1[i++];
	}
	while(j<n2)
	{
		a[k++] = a2[j++];
	}
}
