#include<iostream>
#include<stdlib.h>
#include<string.h>
#define max 1000000
using namespace std;
int main()
{
	int t;
	cin>>t;
	char str[max],str2[max];
	for(int i=0;i<t;i++)
	{
		cin>>str;
		strcpy(str2,str);
		//cout<<str<<" "<<str2;
		int len = strlen(str);
		if(len%2!=0)
		{
			if((str[0]=='9')&&(len==1))
				cout<<"11"<<endl;
			else{
			int k = len/2;
			for(int i=1;i<(len-k);i++)
				str[k+i] = str[k-i];
				//cout<<str;
			if(atoi(str)>atoi(str2))
				cout<<str<<endl;
			else
			{	
				//cout<<"kuteya";
				if(str[k]=='9')
					str[k] = '0';			
				else
					str[k] = (char)((int)str[k]+1);
				if(atoi(str)>atoi(str2))
				cout<<str<<endl;
				else{			
				for(int i=1;i<(len-k);i++)
				{
					if(str[k+i]=='9')
						str[k+i]='0';
					else
						str[k+i] = (char)((int)str[k+i]+1);
					if(str[k-i]=='9')
						str[k-i]='0';
					else
						str[k-i] = (char)((int)str[k-i]+1);
					if(atoi(str)>atoi(str2))
						break;
					else if(atoi(str)==0)
					{
						str[len-1] = '1';
						len = len+1;
						for(int j=len-1;j>0;j--)
						{
							str[j] = str[j-1];
						}
						str[0] = '1';
						break;
					}
				}
				
				cout<<str<<endl;
				
			}
		}
		}
		}
		else
		{
			int k = len/2;
			for(int i=0;i<(len-k);i++)
				str[k+i] = str[k-i-1];
			if(atoi(str)>atoi(str2))
				cout<<str<<endl;
			else
			{
				for(int i=0;i<(len-k);i++)
				{
					if(str[k+i]=='9')
						str[k+i] = '0';
					else
						str[k+i] = (char)((int)str[k+i]+1);
					if(str[k-i-1]=='9')
						str[k-i-1] = '0';
					else
						str[k-i-1] = (char)((int)str[k-i-1]+1);
					if(atoi(str)>atoi(str2))
						break;
					else if(atoi(str) == 0)
						{
						str[len-1] = '1';
						len = len+1;
						for(int j=len-1;j>0;j--)
						{
							str[j] = str[j-1];
						}
						str[0] = '1';
						break;
						}
			    }
			    cout<<str<<endl; 
		}
	}

}

}
