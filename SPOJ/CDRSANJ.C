#include<iostream>
#include<math.h>
using namespace std;
int a[1000000];
int sum=0;
void calculate(int x);
void dumbass(int x);
void quadratic(int ,int );
int main()
{
	int x,count = 0;
	cin>>x;
	dumbass(x);
	cout<<sum;
	
}
void dumbass(int x)
{		//cout<<"dumbass"<<endl;
	int count =0;
	if((x==0)||(x==1)||(x==2))
		sum+=x;
	else
	{
		int q = x/2;
		for(int i=2;i<=q;i++)
	{
		if(x%i == 0)
		{	
			count = 1;
			break;
		}
	}
	if(count == 0)
//		cout<<"0";
		sum+=0;
	else
		calculate(x);
	}
}
void calculate(int x)
{
//	cout<<"calculate"<<endl;
	int num = x/2;
	int j=0;
	
	for(int i=1;i<=num;i++)
	{
		if(x%i==0)
		{
			a[j] = i+(x/i);
			j++;
		}
	}
	int min = a[0],temp;
	for(int i=1;i<j;i++)
	{
		if(a[i]<min)
		{
			temp = min;
			min = a[i];
			a[i] = temp;
		}
	}
	//cout<<min<<"\t";
	quadratic(min,x);
}
void quadratic(int min,int x)
{//	cout<<"quadratic"<<endl;
	int ping,sqroot;
	ping = (min*min)-(4*x);
	sqroot = sqrt(ping);
	int a,b;
	a = (min+sqroot)/2;
	b = min-a;
//	cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;
	dumbass(a);
	dumbass(b);
}
