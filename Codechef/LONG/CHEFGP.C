//author @ Ayush Aggarwal

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		string str1 = "*";
		int x,y;
		cin>>x>>y;
		int counta=0;
		int countb=0;
		int len = str.length();
		vector <int> v;
		bool keep = false;
		for(int i=1;i<len;i++)
		{
			if(str[i]=='a')
				counta++;
			if(str[i]=='b')
				countb++;
		}
		for(int i=1;str[i]!='\0';i++)
		{
			bool keep = false;
			if(str[i]==str[i-1])
			{
				if(str[i]=='b')
				{
					for(int j=i+1;j<len;j++)
					{
						if(str[j]=='a')
						{
							keep = true;
							swap(str[i],str[j]);
							break;
						}
					}
					if(keep==false)
					{
						str.insert(i,str1);
						i++;
					}
				}
				else
				{
					for(int j=i+1;j<len;j++)
					{
						if(str[j]=='b')
						{
							keep = true;
							swap(str[i],str[j]);
							break;
						}
					}
					if(keep==false)
					{
						str.insert(i,str1);
						i++;
					}
				}
			}
			else
				if(str[i]=='a')
					counta--;
				else 
					countb--;
		}
		cout<<str<<endl;	
	}
	return 0;	
}