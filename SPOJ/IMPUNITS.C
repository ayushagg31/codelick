#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(long a, long b) {
  long r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main()
{
	ll t,a,b,a1=1,b1=1,ans;
	while(true)
	{
		a1 = 1;
		b1 =1;
		cin>>t;
		if(t!=-1)
		{
			t = t-1;
			while(t--)
			{
				cin>>a>>b;
				a1 *=a;
				b1 *=b;
			}
			ans = gcd(a1,b1);
			cout<<a1/ans<<" "<<b1/ans<<endl;
		}
		else
			break;
	}
	return 0;
}