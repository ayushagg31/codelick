#include <bits/stdc++.h>
using namespace std;
struct pos
{
	int sum=0;
	int min_sum=0;
}seg_tree[600005];
void build(int a[],int low,int high,int pos)
{
	if(low==high)
	{
		seg_tree[pos].sum = a[low];
		seg_tree[pos].min_sum=a[low];
		return;
	}
	int mid = (low+high)/2;
	build(a,low,mid,2*pos+1);
	build(a,mid+1,high,2*pos+2);
	seg_tree[pos].sum = seg_tree[2*pos+1].sum + seg_tree[2*pos+2].sum;
	seg_tree[pos].min_sum = min(seg_tree[2*pos+1].min_sum,seg_tree[2*pos+1].sum+seg_tree[2*pos+2].min_sum);
}
void update(int low,int high,int pos,int idx,int val)
{
	if(low == high)
	{
		seg_tree[pos].sum = val;
		seg_tree[pos].min_sum = val;
	}
	else
	{
		int mid = (low+high)/2;
		if(low <=idx and idx <=mid)
			update(low,mid,2*pos+1,idx,val);
		else
			update(mid+1,high,2*pos+2,idx,val);
		seg_tree[pos].sum = seg_tree[2*pos+1].sum + seg_tree[2*pos+2].sum;
		seg_tree[pos].min_sum = min(seg_tree[2*pos+1].min_sum,seg_tree[2*pos+1].sum+seg_tree[2*pos+2].min_sum);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t=10,Q,N;
	string str;
	for(int j=1;j<=t;j++)
	{
		//int seg_tree[600005];
		cin>>N;
		int a[N];
		cin>>str;
		for(int i=0;i<N;i++)
		{
			if(str[i]=='(')
				a[i] = 1;
			else
				a[i] = -1;
		}
		build(a,0,N-1,0);
		cin>>Q;
		int x;
		cout<<"Test "<<j<<":"<<endl;
		while(Q--)
		{
			cin>>x;
			if(x==0)
			{
				if((seg_tree[0].sum == 0 )and (seg_tree[0].min_sum >=0))
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
			else
			{
				//update
				x = x-1;
				int val;
				if(a[x] == -1)
				{
					a[x] = 1;
					val = 1;
				}
				else
				{
					a[x] = -1;
					val = -1;
				}
				update(0,N-1,0,x,val);
			}
				
		}
	}
	return 0;
}