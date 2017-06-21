#include <iostream>
using namespace std;

bool check(int N,int i)
{
	int sample = 1<<i;
	bool res = N & sample;
	return res;
}

int main()
{
	int N,i;
	cin>>N;
	cin>>i;
	cout<<check(N,i);
	return 0;
}