#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int col,len,div,p;
char str[200];
while(1)
{
	cin>>col;	//5
	if(col==0)
		break;
	else
	{
		cin>>str;
		len = strlen(str);	//35
		div = len/col;	//7
		int k=1;
		for(int i=0;i<col;i++)
		{
				p = i;int j = 1;
				
				while((p<len)&&(j<=div))
				{
					if(j%2!=0)
					{
						cout<<str[p];
						
					}
					else
					{
						p += 2*(col-i-1)+1;
						cout<<str[p];
						p=p+i+k;
					}
					j++;
				}
				k++;
		}
						
	}
	cout<<endl;
		
}
	
}
	
