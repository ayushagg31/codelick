//author @ Ayush Aggarwal
// Let's Do this shit.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	double v;
	while(t--)
	{
		cin>>v;
		double S, s1, a, s2, h;

		a = (double)cbrt(4*v);
		h = (double)a/sqrt(3);

		s1 = (double)((double)pow(a,2) * (double)sqrt(3)/2);
		s2 = (double)3*a*h;
		S = s1+s2;
		
		printf("%f\n", S);
	}
	return 0;
}