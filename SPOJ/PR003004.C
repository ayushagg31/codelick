#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define max 1000000	
int main()
{
	
	long long int a,b,len1,len2,sum=0,num,rem;
	char str1[max],str2[max];
	while(true)
	{
		sum=0;
		cin>>str1>>str2;
		if(str1[0]=="-1")
			break;
		else{	
		
		b = atoi(str2);
		long long int diff = b-a;
		for(int i=1;i<=diff;i++)
		{
			len1 = strlen(str1);
			for(int j=0;j<len1;j++)	
				sum +=(int)str1[j];
			a = atoi(str1);
			str1 = (char)(a+1); 
		}
		cout<<sum<<endl;
	}
}
}
