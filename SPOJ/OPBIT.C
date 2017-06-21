#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		vector <ll> v,s;
		ll a1 =sqrt(a),save;
		ll b1 = sqrt(b);
		ll kand,kxor,kans;
		if(a1!=b1){
		for(ll i=a1+1;i<=b1;i++)
		{
			save = (i*i)-((i-1)*(i-1));
			v.push_back(save);
			s.push_back(save);
		}
		for(ll i=0;i<v.size()-1;i++)
		{
			kand = v[i] &v[i+1];
			v[i+1] = kand;
		}
		kand = v[v.size()-1];
		for(ll i=0;i<s.size()-1;i++)
		{
			kxor = s[i] ^ s[i+1];
			s[i+1] = kxor;
		}
		kxor = s[s.size()-1];
		kans = kand&kxor;
		cout<<kans<<endl;
		v.clear();
		s.clear();
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}