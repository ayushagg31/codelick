#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000000
int main()
{
	srand(time(NULL));
	int t;
	cin>>t;
	for(ll i=0;i<t;i++)
		cout<<rand() % MAX<<" ";
	return 0;
}