#include<iostream>
using namespace std;
int main()
{
	int t,num,i;
	cin>>t;
	if(t%10==0)
		cout<<"2";
	else
	{
		cout<<"1"<<endl;
		cout<<(t%10);
		}
}
