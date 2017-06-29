//author @ Ayush Aggarwal
// Let's Do this shit.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
	int final = k;
	int limit = n-k+1;
	int save[k];
	int l=0,r=0;
	while(l<limit)
	{
		int s =0;
		while(r<final)
		{
			save[s] = a[r];
			s++;
			r++;
		}
		int max =save[0];
		for(int i=1;i<k;i++)
		{
			if(max < save[i])
				max = save[i];
		}
		cout<<max<<" ";
		r = l+1;
		l++;
		final = final+1;
		//cout<<r<<" "<<l<<" "<<final<<endl;
	}
	return 0;
}