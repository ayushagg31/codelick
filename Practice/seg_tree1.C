#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tree[400005];
int lazy[400005];
void build(int a[],int low,int high,int pos)
{
    if(low==high)
    {
        tree[pos] = a[low];
        return;
    }
    else
    {
        int mid = (low+high)/2;
        build(a,low,mid,2*pos+1);
        build(a,mid+1,high,2*pos+2);
        tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
    }
}
void update(int a[],int low,int high,int pos,int val,int startRange,int endRange)
{
    if(low>high)
        return ;

    if(lazy[pos]!=0)
    {
        tree[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1] + = lazy[pos];
            lazy[2*pos+2] + = lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(startRange>high or endRange < low)
        return;
    if(startRange <=low and endRange >=high)
    {
        if(tree[pos] > val)
            tree[pos] -=1;
        if(low!=high)
        {   
                lazy[2*pos+1] -= 1;
                lazy[2*pos+2] -= 1;
        }
        return;
    }
    int mid = (low+high)/2;
    update(a,low,mid,2*pos+1,val)
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
    build(a,0,N-1,0);
    int query,q;
    cin>>query;
    for(int i=0;i<query;i++)
    {
        cin>>q;   
        update(a,0,N-1,0,q,0,N-1);
    }
    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
    return 0;
}
