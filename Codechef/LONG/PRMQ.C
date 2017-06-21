#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000005
ll a[100005];
ll spf[MAXN];
 
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (ll i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (ll j=i*i; j<MAXN; j+=i)
 
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
map <ll,ll> getFactorization(ll x)
{
    map<ll,ll> mp;
    ll count=0;
    while (x != 1)
    {
        mp[spf[x]] = mp[spf[x]]+1;
        x = x / spf[x];
    }
    return mp;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  
    sieve();
    map<ll,ll> mp;
    ll N;
    cin>>N;
    //ll a[N];
    for(ll i=1;i<=N;i++)
        cin>>a[i];
    ll query;
    cin>>query;
    ll L,R,X,Y;
    for(ll i=0;i<query;i++) 
    {
        ll saum=0;
        cin>>L>>R>>X>>Y;
        ll x=1;
        for(ll i=L;i<=R;i++)
            {x = a[i];
    mp = getFactorization(x);
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        ll a= i->first;
        ll b= i->second;
        if(a>=X&&a<=Y)
            saum = saum + b;
        else if(a>Y)
            break;
    }
         mp.clear();}
    cout<<saum<<endl;
    mp.clear();
}
    return 0;
}
 