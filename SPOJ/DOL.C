#include <iostream>
using namespace std;

int main()
{
	long long int t;
	cin>>t;
	long long int var;
	long long int high;
	long long int j=1;
	long long int save;
	while(t--)
	{
		cin>>var;
		if(var%2!=0)
			save = var;
		else
		{
			high = var;
			while(high%2==0)
			{
				high = high/2;
			}
			save = high;
		}
		cout<<"Case "<<j<<": "<<save<<endl;
		j++;
	}
	return 0;
}