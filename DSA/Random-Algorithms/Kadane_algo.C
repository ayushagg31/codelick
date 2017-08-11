//author @ Ayush Aggarwal

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
	int max_ending_here = 0;
	int max_so_far = 0;
	for(int i=0;i<n;i++)
	{
		max_ending_here = max_ending_here + a[i];
		if(max_ending_here < 0)
			max_ending_here = 0;
		if(max_ending_here > max_so_far)
				max_so_far = max_ending_here;
	}
	cout<<max_so_far<<endl;
	return 0;	
}