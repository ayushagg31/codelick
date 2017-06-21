#include<iostream>
using namespace std;
int main()
{
	double t;
	int i;
	while(true)
	{
		double sum = 0.00;
		cin>>t;
		if(t==0.00)
			break;
		else
		{	int i=2;
			while(true)
			{
				sum += (float)1/i;
				if(sum>=t)
					break;
				else
					{
						i++;
						continue;
					}
			}
		
		cout<<i-1<<" card(s)"<<endl;
		}
	}
}
