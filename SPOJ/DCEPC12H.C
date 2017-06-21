#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	float var1,var2;
	while(T--)
	{
		cin>>var1>>var2;
		float res = (var1+1)/2;
		printf("%06f\n",res);
	}
	return 0;

}