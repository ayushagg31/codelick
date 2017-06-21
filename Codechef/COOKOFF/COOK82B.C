#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MOD 1000000007
vector <ll> primes;
ll power(ll a, ll b){
if (b == 0) return 1;
if (b == 1) return a;
if (b%2 == 1) return (a*power(a,b-1))%MOD;
ll x = power(a,b/2)%MOD;
return (x*x)%MOD;
}

void sieve()
{
	ll max = 31625;
	bool prime[max+1];
	memset(prime ,true,sizeof(prime));
	for(ll p=2;p*p<=max;p++)
	{
		if(prime[p]==true)
		{
			for(ll i=p*2;i<=max;i+=p)
				prime[i] = false;
		}
	}
	for(ll p=2;p<=max;p++)
	{
		if(prime[p])
			primes.pb(p);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	sieve();
	int n;
	cin>>n;
	ll x;
	map<ll,ll> mp;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		for(int j=0;j<primes.size();j++)
		{
			while(x%primes[j]==0)
			{
				x = x/primes[j];
				mp[primes[j]]++;
			}if(x==1)
				break;
			}
			if(x>1) mp[x]++;
		}
		bool justdoit = true;
    	ll ans = 1;
        for (auto it = mp.begin(); it != mp.end(); it++){
            ll a = it->first;
            ll b = it->second;
            if (b%n != 0){ 
                justdoit = false;
            }
            if (b%(n+1) != 0){
                ans *= power(a,n+1-(b%(n+1)));
                ans %= MOD;
            }
        }
        if (justdoit) cout << "justdoit\n";
        else cout << ans << endl;
	}
