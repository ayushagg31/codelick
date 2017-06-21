#include<iostream>
using namespace std;
int main()
{
	int t,a,b;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		
		if(a==4)
		{
			if(b%2==0)
					cout<<"6"<<endl;
				else
					cout<<"4"<<endl;
		}
		else if(a==9)
		{
			if(b%2==0)
					cout<<"1"<<endl;
				else
					cout<<"9"<<endl;
		}
		else if(a==2)
		{
			if(b%4==0)
					cout<<"6"<<endl;
				else if(b%3==0)
					cout<<"8"<<endl;
				else if(b%2==0)
					cout<<"4"<<endl;
				else
					cout<<"2"<<endl;
		}
		else if(a==3)
		{
			if(b%4==0)
					cout<<"1"<<endl;
				else if(b%3==0)
					cout<<"7"<<endl;
				else if(b%2==0)
					cout<<"9"<<endl;
				else
					cout<<"3"<<endl;
		}
		else if(a==7)
		{
			if(b%4==0)
					cout<<"1"<<endl;
				else if(b%3==0)
					cout<<"3"<<endl;
				else if(b%2==0)
					cout<<"9"<<endl;
				else
					cout<<"7"<<endl;
		}
		else if(a==8)
		{
			if(b%4==0)
					cout<<"6"<<endl;
				else if(b%3==0)
					cout<<"2"<<endl;
				else if(b%2==0)
					cout<<"4"<<endl;
				else
					cout<<"8"<<endl;
		}
		else
		{	
			cout<<a<<endl;
		}
	/*switch(a)
	{
		case 0:cout<<"0"<<endl;
				break;
		case 1:cout<<"1"<<endl;
				break;
		case 5:cout<<"5"<<endl;
				break;
		case 6:cout<<"6"<<endl;
				break;
		case 4:
				if(b%2==0)
					cout<<"6"<<endl;
				else
					cout<<"4"<<endl;
				break;
		case 9:
				if(b%2==0)
					cout<<"1"<<endl;
				else
					cout<<"9"<<endl;
				break;
		case 2:
				if(b%4==0)
					cout<<"6"<<endl;
				else if(b%3==0)
					cout<<"8"<<endl;
				else if(b%2==0)
					cout<<"4"<<endl;
				else
					cout<<"2"<<endl;
				break;
		case 3:
				if(b%4==0)
					cout<<"1"<<endl;
				else if(b%3==0)
					cout<<"7"<<endl;
				else if(b%2==0)
					cout<<"9"<<endl;
				else
					cout<<"3"<<endl;
				break;
		case 7:
				if(b%4==0)
					cout<<"1"<<endl;
				else if(b%3==0)
					cout<<"3"<<endl;
				else if(b%2==0)
					cout<<"9"<<endl;
				else
					cout<<"7"<<endl;
				break;
		case 8:
				if(b%4==0)
					cout<<"6"<<endl;
				else if(b%3==0)
					cout<<"2"<<endl;
				else if(b%2==0)
					cout<<"4"<<endl;
				else
					cout<<"8"<<endl;
				break;
		default:
				break;*/
	
	}
}

