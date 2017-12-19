//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a;
		set <int> s;
		set <int> :: iterator itr;
		for(int i=0;i<n;i++)
		{	
			cin>>a;
			s.insert(a);
		}
		int x=0,count=0;
		for(itr = s.begin();itr!=s.end();itr++)
		{
			if(x==*itr)
				x++;
			else
			{
				if(count!=k)
				{
					while((x<*itr) and (count<k))
					{
						x++;
						count++;
					}
					if(x==*itr)
						x++;
					if(x < *itr)
						itr--;
				}
				else
					break;
			}
		}
		while(count < k)
		{
			x++;
			count++;
		}
			cout<<x<<endl;
	}
	return 0;	
}