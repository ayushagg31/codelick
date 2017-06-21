#include<iostream>
using namespace std;
int main()
{
	long int t,x,y,out;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>x>>y;
		if(((x-y)<=2)&&((x-y)>=0)){
		if((x%2==0)&&(y%2==0)){
		out = x+y;
		cout<<out<<endl;}
		else if((x%2!=0)&&(y%2!=0)){
		out = x+y-1;
		cout<<out<<endl;
		}
		else
		cout<<"No Number"<<endl;
		}
		else
		cout<<"No Number"<<endl;
		}
}

