#include<iostream>
#include<stdio.h>
using namespace std;
#define pi  3.14159
int main()
{
	double t,a,r,area;
	while(true)
	{
		cin>>a;
		if(a==0)
			break;
		else
		{
			r = a/pi;
			area = (pi*r*r)/2;
			printf("%.2f",area);
			cout<<endl;
		}
	}
}
