#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
bool check(char str[]);
//void cal
int main()
{
	int t,count;
	char num1[100],opr1[100],num2[100],opr2[100],num3[100];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>num1>>opr1>>num2>>opr2>>num3;
		if(check(num1))
		{
			count = atoi(num3) - atoi(num2);
			cout<<count<<" "<<opr1<<" "<<num2<<" "<<opr2<<" "<<num3<<endl;
			
		}
		else if(check(num2))
		{
			count = atoi(num3) - atoi(num1);
			cout<<num1<<" "<<opr1<<" "<<count<<" "<<opr2<<" "<<num3<<endl;
		}
		else
		{
			count = atoi(num1) + atoi(num2);
			cout<<num1<<" "<<opr1<<" "<<num2<<" "<<opr2<<" "<<count<<endl;
		}
			}
}
bool check(char str[])
{
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		if(isalpha(str[i]))
			{
				return(true);
			}
	}
	return(false);
}

