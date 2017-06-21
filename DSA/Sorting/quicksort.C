#include <iostream>
using namespace std;

int partitioning(int a[],int p,int r);
void quicksort(int a[],int p,int r)
{
	if(p<r)
	{
	int q = partitioning(a,p,r);
	cout<<"q ="<<q<<" \n";
	quicksort(a,p,q);
	quicksort(a,q+1,r);
	}
}
int main()
{
	int n,temp=0,savage=0;
	cin >> n;
	int a[n];
	cout<<"Enter elements of array to be sorted \n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	quicksort(a,0,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
int partitioning(int a[],int p,int r)
{
	cout<<"p ="<<p<<" \n";
	cout<<"r ="<<r-1<<" \n";
	int q=0,temp=0;
	int pivot = a[r-1];
	int i=p-1;
	for(int j=p;j<r-1;j++)
	{
		if(a[j]<=pivot)
		{
			i = i+1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
		q = i+1;
	temp = a[q];
	a[q] = a[r-1];
	a[r-1] = temp;
	for(int i=p;i<r;i++)
		cout<<a[i]<<" ";
		cout<<"\nDONE\n";
	return q;
}