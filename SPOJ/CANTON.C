#include<iostream>
using namespace std;
void calculate(int );
int main()
{
	int t,a;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a;
		/*if(a==1)
			cout<<"TERM "<<a<<" IS 1/1"<<endl;
		else	*/
		calculate(a);
	}
}
void calculate(int x)
{
	int num=1,den=1,count=1;
	while(count<x)
	{
		den++;
		count++;		
		if(count==x)
			break;
		while((count<x)&&(den>1))
		{
			num++;den--;count++;
		}
		if(count==x)
			break;
		else{
		num++;count++;
		while((count<x)&&(num>1))
		{
			num--;den++;count++;
		}
		}
	}
	cout<<"TERM "<<x<<" IS "<<num<<"/"<<den<<endl;
	}
