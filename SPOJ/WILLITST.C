#include<iostream>
using namespace std;
int main()
{
	unsigned long long int n;
	cin>>n;
	while (n > 1)
	{
		if (n%2 == 0)
		    n = n/2;
	   else
       		n = 3*n+3;
       if((n==3)||(n==6)||(n==12))
       	{cout<<"NIE";
//       		flag =1;
       		return 0;
       	}
       	else
       		{
       		 continue;
       		}
     }
     cout<<"TAK";
}
