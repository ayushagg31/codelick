#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll binary_search(ll a[],ll size,ll num)
{
	ll low =0 ;
	ll high =size-1;
	while(low<=high)
	{
		ll mid = (low+high)/2;
		if(a[mid] < num)
			low = mid+1;
		else if(a[mid] > num)
			high = mid -1;
		else
		{
			while(a[mid+1]==num){
				mid++;
			}
			return mid+1;
		}
	}
	return low;
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
ll p,q,r;
while(t--)
{
	ll sum =0;
	cin>>p>>q>>r;
	ll a[p],b[q],c[r];
	for(ll i=0;i<p;i++)
		cin>>a[i];
	sort(a,a+p);
	for(ll i=0;i<q;i++)
		cin>>b[i];
	for(ll i=0;i<r;i++)
		cin>>c[i];
	sort(c,c+r);
	ll sumx[p+1],sumz[r+1];
	memset(sumx,0,sizeof(sumx));
	memset(sumz,0,sizeof(sumz));
	for(ll i=0;i<p;i++)
		sumx[i+1] = (sumx[i]+a[i])%MOD;
	for(ll i=0;i<r;i++)
		sumz[i+1] = (sumz[i]+c[i])%MOD;
	for(ll i=0;i<q;i++)
	{
		ll temp = b[i];
		ll countx = (binary_search(a,p,temp))%MOD;
		ll countz = (binary_search(c,r,temp))%MOD;
	sum = (sum%MOD + ((sumx[countx]%MOD + (countx%MOD*b[i]%MOD)%MOD)%MOD*(sumz[countz]%MOD + (countz%MOD*b[i]%MOD)%MOD)%MOD))%MOD;
	}
	cout<<sum<<endl;
}
return 0;
}