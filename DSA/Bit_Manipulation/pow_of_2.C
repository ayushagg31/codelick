#include <iostream>
using namespace std;

bool pow_of_2(int n)
{
	if(n==0)
		return false;
	else
	return (!(n&n-1));
}

int main()
{
	int n;
	cin>>n;
	cout<<pow_of_2(n);
}