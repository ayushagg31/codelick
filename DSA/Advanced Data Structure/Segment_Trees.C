#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
void construct_seg_tree(int a[],int seg_tree[],int low,int high,int pos)
{
	if(low == high){
		seg_tree[pos] = a[low]; 
		return;}
	int mid = (low+high)/2;
	construct_seg_tree(a,seg_tree,low,mid,2*pos+1);
	construct_seg_tree(a,seg_tree,mid+1,high,2*pos+2);
	seg_tree[pos] = min(seg_tree[2*pos+1],seg_tree[2*pos+2]);
}
int query(int seg_tree[],int l,int r,int low,int high,int pos)
{
	if(l <=low and r >=high)
		//total overlap
		return seg_tree[pos];
	else if(l >high or r < low)
		return MAX;
	else
	{
		int mid = (low+high)/2;
		return(min(query(seg_tree,l,r,low,mid,2*pos+1),query(seg_tree,l,r,mid+1,high,2*pos+2)));
	}
}
void update(int seg_tree[],int idx,int val,int low,int high,int pos)
{
	if(low==high)
		seg_tree[pos] = val;
	else
	{
		int mid = (low+high)/2;
		if(low <=idx and idx <=mid)
			update(seg_tree,idx,val,low,mid,2*pos+1);
		else
			update(seg_tree,idx,val,mid+1,high,2*pos+2);
		seg_tree[pos] = min(seg_tree[2*pos+1],seg_tree[2*pos+2]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,Q;
	cin>>N>>Q;
	int a[N];
	int seg_tree[2000005];
	for(int i=0;i<N;i++)
		cin>>a[i];
	construct_seg_tree(a,seg_tree,0,N-1,0);
	char ch;
	int x,y;
	for(int i=0;i<N;i++)
	{
		cin>>ch;
		cin>>x>>y;
		if(ch=='q')
			cout<<query(seg_tree,x-1,y-1,0,N-1,0)<<endl;
		else
		{
			a[x-1] = y;
			update(seg_tree,x-1,y,0,N-1,0);
		}
	}
	return 0;	
}