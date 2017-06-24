//author @ Ayush Aggarwal
// Let's Do this shit.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100005
ll tree[12*MAX];
ll lazy[12*MAX];
void build(ll a[],ll low,ll high,ll pos)
{
	if(low > high)
		return;
	if(low==high)
		tree[pos] = a[low];
	else
	{
		ll mid = (low+high)/2;
		build(a,low,mid,2*pos+1);
		build(a,mid+1,high,2*pos+2);
		tree[pos] = tree[2*pos+1] + tree[2*pos+2];
	}
}
void update(ll low,ll high,ll qlow,ll qhigh,ll val,ll pos)
{
	if(low > high)
		return;

	if(lazy[pos]!=0)
	{
		tree[pos] +=lazy[pos];
		if(low!=high)
		{
			lazy[2*pos+1] +=lazy[pos];
			lazy[2*pos+2] +=lazy[pos];
		}
		lazy[pos] =0;
	}
	if(qlow > high or qhigh < low)
		return;
	if(qlow <=low and qhigh >=high)
	{
		tree[pos] +=val;
		if(low!=high)
		{
			lazy[2*pos+1] +=val;
			lazy[2*pos+2] +=val;
		}
		return;
	}
	ll mid = (low+high)/2;
	update(low,mid,qlow,qhigh,val,2*pos+1);
	update(mid+1,high,qlow,qhigh,val,2*pos+2);
	tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}
ll query(ll low,ll high,ll qlow,ll qhigh,ll pos)
{
	if(low > high or qlow > high or qhigh < low)
		return 0;
	if(lazy[pos]!=0)
	{
		tree[pos] +=(lazy[pos]*((ll)(high-low+1)));
		if(low!=high)
		{
			lazy[2*pos+1] +=lazy[pos];
			lazy[2*pos+2] +=lazy[pos];
		}
		lazy[pos] =0; 
	}

	if(qlow <=low and qhigh >=high)
		return tree[pos];
	ll mid = (low+high)/2;
	return(query(low,mid,qlow,qhigh,2*pos+1)+query(mid+1,high,qlow,qhigh,2*pos+2));
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n,m;
	ll p,q,r,s;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll a[n];
		memset(a,0,sizeof(a));
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		build(a,0,n-1,0);
		while(m--)
		{
			cin>>p;
			if(p==0)
			{
				//update
				cin>>q>>r>>s;
				update(0,n-1,q-1,r-1,s,0);
			}
			else
			{
				//query
				cin>>q>>r;
				cout<<query(0,n-1,q-1,r-1,0)<<endl;
			}
			
		}
	}

	return 0;
}