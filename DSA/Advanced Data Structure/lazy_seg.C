//author @ Ayush Aggarwal

// Let's Do this shit.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005
int tree[5*MAX+5];
int lazy[5*MAX+5];
void build(int a[],int low,int high,int pos)
{
	if(low > high)
		return;
	if(low == high)
		tree[pos] = a[low];
	else
	{
		int mid = (low+high)/2;
		build(a,low,mid,2*pos+1);
		build(a,mid+1,high,2*pos+2);
		tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
	}
}
void update(int low,int high,int qlow,int qhigh,int pos,int x,int val)
{
	if(low > high)
		return ;
	if(lazy[pos]!=0)
	{
		tree[pos]+=lazy[pos];
		if(low!=high)
		{
			lazy[2*pos+1] +=lazy[pos];
			lazy[2*pos+2] +=lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(qlow >high or qhigh < low)
		return;
	if(qlow <=low and qhigh >=high){
	if(tree[pos] > x)
	{
		tree[pos] +=val;
		if(low!=high)
		{
			lazy[2*pos+1] += val;
			lazy[2*pos+2] +=val;
		}
		return;
	}
}
	int mid = (low+high)/2;
	update(low,mid,qlow,qhigh,2*pos+1,x,val);
	update(mid+1,high,qlow,qhigh,2*pos+2,x,val);
	tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
}
int query(int low,int high,int qlow,int qhigh,int pos)
{
	if(low > high)
		return INT_MAX;
	if(lazy[pos] !=0)
	{
		tree[pos] +=lazy[pos];
		if(low!=high)
		{
			lazy[2*pos+1] +=lazy[pos];
			lazy[2*pos+2] +=lazy[pos];
		}
		lazy[pos] = 0;
	}
	if((qlow > high)||(qhigh < low))
		return INT_MAX;
	if(qlow <=low and qhigh >= high)
		return tree[pos];
	int mid = (low+high)/2;
	return(min(query(low,mid,qlow,qhigh,2*pos+1),query(mid+1,high,qlow,qhigh,2*pos+2)));
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	//sort(a,a+N);
	memset(lazy,0,sizeof(lazy));
	build(a,0,N-1,0);
	int q,x;
	cin>>q;
	while(q--)
	{
		cin>>x;
		update(0,N-1,0,N-1,0,x,-1);
	}
	for(int i=0;i<N;i++)
	{
		cout<<query(0,N-1,i,i,0)<<" ";
	}

	return 0;
}