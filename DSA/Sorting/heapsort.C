//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void heapify(int a[],int n,int i)
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l < n and a[l] > a[largest])
		largest = l;
	if(r < n and a[r] > a[largest])
		largest = r;
	if(largest!=i)
	{
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}

}
void heapsort(int a[],int n)
{
	for(int i = n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(int i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	heapsort(arr,n);		
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;	
}