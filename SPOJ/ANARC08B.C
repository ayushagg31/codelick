#include<iostream>
#include<string.h>
using namespace std;
char *calculate(char str[]);
char *dumb(char str[]);
int main()
{
	char str[100],opr[1],opr1[1],str2[100],str3[100];
	while(true)
	{
		cin>>str;
		if(str=="BYE")
			break;
		else{
//		cout<<str;
		int len = strlen(str);
		int plus;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='+')
				{
					plus = i;
					break;}													
		}
		for(int i=0;i<plus;i++)
				str2[i] = str[i];
		for(int i=(plus+1);i<len-1;i++)
			str3[i]=str[i];
		char *ptr1,*ptr2;
		ptr1 = calculate(str2);
		ptr2 = calculate(str3);
		cout<<ptr1<<"\t"<<ptr2<<endl;
    		}
	}
}
char *calculate(char str[])
{
	int len = strlen(str);
	char str2[3];
//	str1 = str;
	int k=0;
	int t = len/3;
	char *str1;
	char str3[t];
	for(int i=0;i<len;i=i+3)
	{
		for(int j=i;j<i+3;j++)
			{
				str2[j] = str[j];
			}
			str1 = dumb(str2);
			str3[k] = *str1;
			k++;
	}
	return(str3);
}
char *dumb(char ch[])
{
	string str = ch;
	string cum = "0123456789";
	if(str=="063")
		return("0");
	else if(str=="107")
		return("9");
	else if(str=="010")
		return("1");
	else if(str=="093")
		return("2");
	else if(str=="079")
		return("3");
	else if(str=="106")
		return("4");
	else if(str=="103")
		return("5");
	else if(str=="119")
		return("6");
	else if(str=="011")
		return("7");
	else
		return("8");
}

